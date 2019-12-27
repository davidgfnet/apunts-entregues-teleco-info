
#include <fat.h>
#include <utils.h>
#include <errno.h>
#include <sys.h>
#include <mm.h>
#include <sched.h>
#include <devices.h>

// The data itself
char * zeosfat_data; //[MAX_BLOCKS][256];
// The FAT (indicates the next block)
int zeosfat_fat[MAX_BLOCKS];
// The directory of the FS
struct dir_entry zeosfat_directory[MAX_FILES];

/* Initializes the fat by marking the blocks as unused
   Also inits de FS directory                             */
int initZeOSFat(void)
{
  int i;
  for (i = 0; i < MAX_FILES; i++)
    zeosfat_directory[i].used = -1; // Empty!

  for (i = 0; i < MAX_BLOCKS; i++)
    zeosfat_fat[i] = ZEOS_FAT_NOT_USED;

  zeosfat_data = (char*)DISK_DATA_START;

  // Map the FAT to some physical pages (with user=0)
  // We could save back the physical pages used, but as we
  // don't need to free them (at least in PROSO)
  for (i = 0; i < (MAX_BLOCKS*256)/(PAGE_SIZE)+1; i++)
    set_ss_pag_kernel((((int)zeosfat_data)>>12)+i,alloc_frame());
  set_cr3();

  return 0;
}

/* Finds an unused disk block, otherwise returns -1 */
int fat_find_unused_block()
{
  int i;
  for (i = 0; i < MAX_BLOCKS; i++)
    if (zeosfat_fat[i] == ZEOS_FAT_NOT_USED)
      return i;
  return -1; // Not enough space
}

/* Deletes an entry from the directory */
int zeosfat_delete(const char * name)
{
  int i;
  for (i = 0; i < MAX_FILES; i++)
    if (zeosfat_directory[i].used >= 0)
      if (strcmp(name,zeosfat_directory[i].filename) == 0)
        {
          if (zeosfat_directory[i].used > 0) return -EBUSY;
          // Delete all the entries in the FAT!!!
          int curr_block = zeosfat_directory[i].start_block;
          while (curr_block < ZEOS_FAT_NOT_USED) {
            int del = curr_block;
            curr_block = zeosfat_fat[curr_block];
            zeosfat_fat[del] = ZEOS_FAT_NOT_USED;
          }
          zeosfat_directory[i].used = -1;
          return 0;
        }
  return -ENOFILE;
}

// name buffer must be in kernel address space
int zeosfat_create(const char * name, int type)
{
  int i;
  for (i = 0; i < MAX_FILES; i++)
    if (zeosfat_directory[i].used < 0)
      {
        int block = fat_find_unused_block();
        if (block < 0) return -ENOSPC;   // The disk is full! No more free blocks!
        zeosfat_directory[i].start_block = block;
        zeosfat_fat[block] = ZEOS_FAT_EOF; // Marks as used!
        zeosfat_directory[i].used = 0; // Used, but any process accessing
        zeosfat_directory[i].size = 0;
        zeosfat_directory[i].type = type;
        copy_data((void*)name,&zeosfat_directory[i].filename[0],FILE_NAME_SIZE+1);
        return 0;
      }

  return -ENOMEM;  // The directory is full!
}

int zeosfat_close(struct file_descriptor_struct * fd)
{
  // Just decrease the count!
  fd->entry_usage--;
  if (fd->fileid >= 0) {
    zeosfat_directory[fd->fileid].used--;
  }else{
    // This is a PIPE (does not use an inode)
    // Check broken pipe (we closed the read or write end)
    // If there is no one reading, any attempt to write will SIGPIPE
    // It there is no one writing, all reads will return 0 
    int pipe = -fd->fileid;

    if (sys_pipes[pipe].broken == 0) {
      if (sys_pipes[pipe].read_desc->entry_usage == 0 || sys_pipes[pipe].write_desc->entry_usage == 0) {
        sys_pipes[pipe].broken = 1;  // Mark the pipe as broken
        // Search for locked processes that were waiting for reading/writing
        check_read_pipe(pipe);
        check_write_pipe(pipe);
      }
    }
    if (sys_pipes[pipe].read_desc->entry_usage == 0 && sys_pipes[pipe].write_desc->entry_usage == 0) {
      // Free the PIPE!
      sys_pipes[pipe].used = 0;
    }
  }
  return 0;
}

// name buffer in kernel space
int zeosfat_open (const char * name, int flags, struct file_descriptor_struct * fd)
{
  int i;
  for (i = 0; i < MAX_FILES; i++)
    if (zeosfat_directory[i].used >= 0)
      if (strcmp(name,zeosfat_directory[i].filename) == 0)
        {
          if ((flags & O_CREAT) != 0 && (flags & O_EXCL) != 0)
          {
            // Trying to overwrite the file, error!
             return -EEXIST;
          }

          // Trying to Read an unreadable device?
          if ((flags&O_RDONLY) != 0 && (device_operations[zeosfat_directory[i].type].rw&O_RDONLY) == 0) return -EACCES;
          // Trying to Write an unwritable device?
          if ((flags&O_WRONLY) != 0 && (device_operations[zeosfat_directory[i].type].rw&O_WRONLY) == 0) return -EACCES;

          // Found the file, proceed to fill the File Descriptor
          fd->curr_position = 0;
          fd->mode = flags & 0x3; // R/W bits
          fd->fileid = i;
          fd->file_op = &device_operations[zeosfat_directory[i].type];
          zeosfat_directory[i].used++;
          return 0;
        }

  if ((flags & O_CREAT) != 0)
  {
    if ((flags & O_EXCL) == 0)
    {
      // Create the file!!!
      int ret_code = zeosfat_create(name,TYPE_FILE);
      if (ret_code < 0) return ret_code; // Couldn't create the file!
      return zeosfat_open (name, flags, fd); // Now open the file (it DOES exits)
    }
    else
    {
      // Trying to create a file but exists!
      return -EEXIST;
    }
  }

  return -ENOFILE;  // File does not exists!
}


int zeosfat_read (struct file_descriptor_struct * fd, char *buffer, int size)
{
  int curr_block = zeosfat_directory[fd->fileid].start_block;
  int pos = fd->curr_position;
  if (fd->curr_position >= zeosfat_directory[fd->fileid].size) return 0; // EOF
  // We don't want to read more than the file size
  if (zeosfat_directory[fd->fileid].size - pos < size) size = zeosfat_directory[fd->fileid].size - pos;

  // Seek to the block!
  int inpos = pos & 0xFF; // (% 256)
  while (pos >= 256)
  {
    // Go to the next block
    curr_block = zeosfat_fat[curr_block];
    pos = pos - 256;
  }
  
  // Start reading
  int bytes_read = 0;
  while (size > 0 && curr_block != ZEOS_FAT_EOF) {
    int can_copy = intmin(256-inpos,size);    
    copy_to_user(&zeosfat_data[curr_block*256+pos],buffer,can_copy);

    buffer += can_copy;
    size -= can_copy;
    fd->curr_position += can_copy;
    bytes_read += can_copy;
    inpos = 0;
    curr_block = zeosfat_fat[curr_block];
  }

  return bytes_read;
}

int zeosfat_write (struct file_descriptor_struct * fd, char *buffer, int size)
{
  if (size == 0) return 0;
  int curr_block = zeosfat_directory[fd->fileid].start_block;
  int pos = fd->curr_position;

  // Seek to the block and create new blocks if the position
  // is after the current position!
  int inpos = pos & 0xFF; // (% 256)
  while (pos >= 256)
  {
    // Go to the next block
    int nextb = zeosfat_fat[curr_block];
    if (nextb == ZEOS_FAT_EOF) {
      // Allocate new block!
      int newblock = fat_find_unused_block();
      if (newblock < 0) return -ENOSPC; // Not enough space!
      zeosfat_fat[curr_block] = newblock;
      zeosfat_fat[newblock] = ZEOS_FAT_EOF;
      nextb = newblock;
    }
    curr_block = nextb;
    pos = pos - 256;
  }

  int bytes_written = 0;
  while (size > 0) {
    int can_copy = intmin(256-inpos,size);    
    copy_from_user(buffer,&zeosfat_data[curr_block*256+pos],can_copy);

    buffer += can_copy;
    size -= can_copy;
    fd->curr_position += can_copy;
    if (fd->curr_position > zeosfat_directory[fd->fileid].size) zeosfat_directory[fd->fileid].size = fd->curr_position;
    bytes_written += can_copy;
    inpos = 0;
    
    int nextb = zeosfat_fat[curr_block];
    if (nextb == ZEOS_FAT_EOF) {
      // Allocate new block!
      int newblock = fat_find_unused_block();
      if (newblock < 0) return bytes_written; // Not enough space!
      zeosfat_fat[curr_block] = newblock;
      zeosfat_fat[newblock] = ZEOS_FAT_EOF;
      nextb = newblock;
    }
    curr_block = nextb;
  }

  return bytes_written;
}


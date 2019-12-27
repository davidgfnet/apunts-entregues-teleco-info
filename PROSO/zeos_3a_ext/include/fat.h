

#ifndef __H__FAT_
#define __H__FAT_

#define MAX_BLOCKS          128
#define ZEOS_FAT_EOF        0xFFFFFFFF
#define ZEOS_FAT_NOT_USED   0xFFFFFFFE
#define MAX_FILES           10
#define FILE_NAME_SIZE      10

extern char * zeosfat_data; //[MAX_BLOCKS][256];
extern int zeosfat_fat[MAX_BLOCKS];
struct dir_entry {
  int used;                          // Entry being used by any process, if its empty value = -1
  char filename[FILE_NAME_SIZE+1];   // File name
  unsigned int start_block;          // The first block containing data
  int size;                          // The size of the file
  int type;                          // The file type (remember it can be a device!)
};
extern struct dir_entry zeosfat_directory[MAX_FILES];

struct file_descriptor_struct;

// Initializes the system
int initZeOSFat(void);
// Creates a file in the FAT system of a given type
int zeosfat_create(const char * name, int type);
// Opens a file and fills the descriptor
int zeosfat_open (const char * name, int flags, struct file_descriptor_struct * fd);
// Reads data from the file
int zeosfat_read (struct file_descriptor_struct * fd, char *buffer, int size);
// Writes data to the file
int zeosfat_write (struct file_descriptor_struct * fd, char *buffer, int size);
// Closes the file
int zeosfat_close(struct file_descriptor_struct * fd);
// Deletes a file
int zeosfat_delete(const char * name);

#endif


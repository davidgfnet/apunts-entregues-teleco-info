
#define NUM_COLUMNS 80
#define NUM_ROWS    25

#include <io.h>
#include <devices.h>
#include <sched.h>
#include <fat.h>
#include <utils.h>
#include <errno.h>
#include <mm.h>

// Keyboard Buffer
struct keyboard_fifo kbd_buffer;

// The devices
struct file_operations device_operations[NUM_DEVICES_TYPE] = {
  {zeosfat_read,zeosfat_write,O_RDWR},
  {0,console_write,O_WRONLY},
  {keyboard_read,0,O_RDONLY},
  {pipe_read,pipe_write,O_RDWR}
 };

// Inits the KBD FIFO
void InitializeDevices()
{
  kbd_buffer.valid_data = 0;
  kbd_buffer.read_ptr = 0;
  kbd_buffer.write_ptr = 0;
  int i;
  for (i = 0; i < NR_PIPES; i++)
    sys_pipes[i].used = 0;
}

#define MIN(a,b) (((a) < (b)) ? (a) : (b))

#define PIPE_WRITE(pipe,buf,size) \
  { \
    char * tempbuf = buf; \
    int write_pos = (pipe.pos+pipe.length)%PIPE_SIZE; \
    int size2 = MIN(size,PIPE_SIZE-write_pos); \
    copy_from_user(tempbuf,&pipe.buffer[write_pos],size2);  \
    tempbuf += size2; \
    copy_from_user(tempbuf,&pipe.buffer[0],size-size2); \
    pipe.length += size; \
  }

#define PIPE_READ(pipe,bu,size) \
  { \
    char * tempbuf = bu; \
    int size2 = MIN(size,PIPE_SIZE-pipe.pos); \
    copy_to_user(&pipe.buffer[pipe.pos],tempbuf,size2);  \
    tempbuf += size2; \
    copy_to_user(&pipe.buffer[0],tempbuf,size-size2); \
    pipe.length -= size; \
    pipe.pos = (pipe.pos+size)%PIPE_SIZE; \
  }


// Checks if the pipe has some blocked processes reading it 
// and unlocks them if possible
void check_read_pipe(int pipe) {
  int done = 0;
  if (sys_pipes[pipe].broken) {
    while (!list_empty(&sys_pipes[pipe].readl)) {
      struct task_struct * t = LIST_TO_TASK(sys_pipes[pipe].readl.next);
      ((union task_union*)t)->saved_regs.eax = 0;
      list_del(&t->plist);
      list_add_tail(&t->plist,&runqueue);
    }
  }else{
    while (sys_pipes[pipe].length > 0 && !list_empty(&sys_pipes[pipe].readl)) {
      done = 1;
      struct task_struct * t = LIST_TO_TASK(sys_pipes[pipe].readl.next);
      map_task_pages(t);
      int avaliable = MIN(sys_pipes[pipe].length,t->req_bytes);
      PIPE_READ(sys_pipes[pipe],t->req_buffer,avaliable)

      // Return the read bytes
      ((union task_union*)t)->saved_regs.eax = avaliable;

      // Delete from list
      list_del(&t->plist);
      list_add_tail(&t->plist,&runqueue);

      //printk("Unblock reading process\n");
    }
    if (done) {
      struct task_struct * curr;
      current_task_addr(curr);
      map_task_pages(curr);
    }
  }
}

// Checks if the pipe has some blocked processes writing it 
// and unlocks them if possible
void check_write_pipe(int pipe) {
  int done = 0;
  // In case of a broken pipe return -EPIPE except if we already wrote something
  // "If write() is interrupted by a signal after it successfully writes
  //     some data, it shall return the number of bytes written."
  // The specification does not clarify if we have to send a SIGPIPE, we just send it
  if (sys_pipes[pipe].broken) {
    while (!list_empty(&sys_pipes[pipe].writel)) {
      struct task_struct * t = LIST_TO_TASK(sys_pipes[pipe].writel.next);
      if (((union task_union*)t)->saved_regs.eax != 0)
        ((union task_union*)t)->saved_regs.eax = -EPIPE;
      list_del(&t->plist);
      list_add_tail(&t->plist,&runqueue);
      sys_kill(sys_getpid(),SIGPIPE);
    }
  }else{
    while (sys_pipes[pipe].length < PIPE_SIZE && !list_empty(&sys_pipes[pipe].writel)) {
      done = 1;
      struct task_struct * t = LIST_TO_TASK(sys_pipes[pipe].writel.next);
      map_task_pages(t);
      int avaliable = MIN(PIPE_SIZE-sys_pipes[pipe].length,t->req_bytes);
      PIPE_WRITE(sys_pipes[pipe],t->req_buffer,avaliable)

      // Return the written bytes
      ((union task_union*)t)->saved_regs.eax += avaliable;
      t->req_bytes -= avaliable;
      t->req_buffer += avaliable;

      // Delete from list only if we could satisfy the demand
      if (t->req_bytes == 0) {
        list_del(&t->plist);
        list_add_tail(&t->plist,&runqueue);
      }
    }
    if (done) {
      struct task_struct * curr;
      current_task_addr(curr);
      map_task_pages(curr);
    }
  }
}

int pipe_write (struct file_descriptor_struct * fd, char *buffer, int size) {
  struct task_struct * curr_task;
  current_task_addr(curr_task);
  if (curr_task->pid == 0) return -1;

  int pipe = -fd->fileid;

  if (sys_pipes[pipe].broken) {
    // Attempted to write to a broken pipe! SIGPIPE!
    ((union task_union*)curr_task)->saved_regs.eax = -EPIPE;
    sys_kill(sys_getpid(),SIGPIPE);
    return -EPIPE;
  }

  //printk("Writing to a PIPE\n");

  // Try to write as much as possible
  int can_write = MIN(PIPE_SIZE - sys_pipes[pipe].length,size);
  if (can_write > 0) {
    PIPE_WRITE(sys_pipes[pipe],buffer,can_write)

    check_read_pipe(pipe);
    return can_write;
  }else{
    // Pipe full, block us!
    curr_task->req_bytes = size;
    curr_task->req_buffer = buffer;
    ((union task_union*)curr_task)->saved_regs.eax = 0;
    list_del(&curr_task->plist);
    list_add_tail(&curr_task->plist,&sys_pipes[pipe].writel);
    task_switch((union task_union*)runqueue.next,0);
  }

  return 0;
}

int pipe_read (struct file_descriptor_struct * fd, char *buffer, int size) {
  struct task_struct * curr_task;
  current_task_addr(curr_task);
  if (curr_task->pid == 0) return -1;

  int pipe = -fd->fileid;

  //printk("Reading from a PIPE\n");

  if (sys_pipes[pipe].broken) {
    // Attempted to read from a broken pipe! Return 0
    return 0;
  }

  // Try to write as much as possible
  int can_read = MIN(sys_pipes[pipe].length,size);

  if (can_read > 0) {
    PIPE_READ(sys_pipes[pipe],buffer,can_read)

    check_write_pipe(pipe);
    return can_read;
  }else{
    // Pipe empty, block us!
    curr_task->req_bytes = size;
    curr_task->req_buffer = buffer;
    ((union task_union*)curr_task)->saved_regs.eax = 0;
    list_del(&curr_task->plist);
    list_add_tail(&curr_task->plist,&sys_pipes[pipe].readl);
    task_switch((union task_union*)runqueue.next,0);
  }

  return 0;
}


int console_write (struct file_descriptor_struct * fd, char *buffer, int size)
{
  return sys_write_console(buffer,size);
}


int keyboard_read (struct file_descriptor_struct * fd, char *buffer, int size)
{
  struct task_struct * curr_task;
  current_task_addr(curr_task);
  if (curr_task->pid == 0) return -1;
  if (size > KEYBOARD_BUFFER_SIZE) size = KEYBOARD_BUFFER_SIZE;

  // Check if there is enough data and no one is waiting
  if (list_empty(&keyboardqueue) && kbd_buffer.valid_data >= size) {
    // Just copy the data, no need to block the process!
    int endpos = kbd_buffer.read_ptr+size;
    if (endpos > KEYBOARD_BUFFER_SIZE) {
      copy_to_user(&kbd_buffer.buffer[kbd_buffer.read_ptr],buffer,KEYBOARD_BUFFER_SIZE-kbd_buffer.read_ptr);
      kbd_buffer.read_ptr = 0;
      int rem_size = size - (KEYBOARD_BUFFER_SIZE-kbd_buffer.read_ptr);
      buffer += (KEYBOARD_BUFFER_SIZE-kbd_buffer.read_ptr);
      copy_to_user(&kbd_buffer.buffer[kbd_buffer.read_ptr],buffer,rem_size);
      kbd_buffer.read_ptr += rem_size;
    }else{
      copy_to_user(&kbd_buffer.buffer[kbd_buffer.read_ptr],buffer,size);
      kbd_buffer.read_ptr += size;
    }
    kbd_buffer.valid_data -= size;
    return size;
  }
  else
  {
    // Add to queue
    curr_task->req_bytes = size;
    curr_task->req_buffer = buffer;
    list_del(&curr_task->plist);
    list_add_tail(&curr_task->plist,&keyboardqueue);
    task_switch((union task_union*)runqueue.next,0); // Jump to next process
    return 0;
  }

  return 0;
}


extern Byte x,y;

int sys_write_console (char *buffer, int size)
{
  char local_buffer[16];
  int rem = size;
  while (rem > 0) {
    int todo = 16;
    if (rem < 16) todo = rem;

    copy_from_user(buffer,local_buffer,todo);
    buffer += todo;
    rem -= todo;
    
    int i;
    for (i = 0; i < todo; i++) {
      if (local_buffer[i] == '\n')
      {
        y++;
        x = 0;
        // Check if the screen is full and scroll it up!
        if (y == NUM_ROWS)
        {
          scroll_screen();
          y = NUM_ROWS-1;
        }
      }
      else
      {
        short ch = (short) (local_buffer[i] & 0x00FF) | 0x0F00;
        short * screen = (short*)(0xb8000 + (y * NUM_COLUMNS + x) * 2);
        *screen = ch;
        x++;
        if (x >= NUM_COLUMNS)
        {
          x = 0;
          y++;
          if (y == NUM_ROWS)
          {
            scroll_screen();
            y = NUM_ROWS-1;
          }
        }
      }
    }
  }
  return size;
}



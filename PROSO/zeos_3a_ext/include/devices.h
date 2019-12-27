#ifndef DEVICES_H__
#define  DEVICES_H__

#include <io.h>
#include <sys.h>

void InitializeDevices();

/**** KEYBOARD ****/
#define KEYBOARD_BUFFER_SIZE  16
struct keyboard_fifo {
  unsigned char buffer [KEYBOARD_BUFFER_SIZE];
  int read_ptr;
  int write_ptr;
  int valid_data;
};
extern struct keyboard_fifo kbd_buffer;

/***** DEVICE DESCRIPTORS *******/
struct file_descriptor_struct;
struct file_operations {
  // Pointer to the specific functions of the device
  int (*read) (struct file_descriptor_struct * fd, char *buffer, int size);
  int (*write) (struct file_descriptor_struct * fd, char *buffer, int size);
  int rw;           // If the devices is readable/writable
};
extern struct file_operations device_operations[NUM_DEVICES_TYPE];


/****** DEVICE SPECIFIC FUNCTIONS *******/
int sys_write_console(char *buffer,int size);
int console_write (struct file_descriptor_struct * fd, char *buffer, int size);
int keyboard_read (struct file_descriptor_struct * fd, char *buffer, int size);

// PIPES

int pipe_write (struct file_descriptor_struct * fd, char *buffer, int size);
int pipe_read (struct file_descriptor_struct * fd, char *buffer, int size);
void check_write_pipe(int pipe);
void check_read_pipe(int pipe);

#endif /* DEVICES_H__*/

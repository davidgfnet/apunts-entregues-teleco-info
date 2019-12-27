/*
 * sys.c - Syscalls declaration
 */

#ifndef __SYS__H__
#define __SYS__H__

#define WNOHANG 1

#define READING  0
#define WRITING  1

#include <types.h>
#include <stats.h>
#include <mm_address.h>
#include <list.h>

/****** SYSTEM CALLS *******/
int sys_getpid();
int sys_fork();
int sys_exit();
int sys_ni_syscall();
int sys_nice(int quantum);

int sys_sem_init(int n_sem, unsigned int value);
int sys_sem_wait(int n_sem);
int sys_sem_signal(int n_sem);
int sys_sem_destroy(int n_sem);

int sys_get_stats(int pid, struct stats * st);

int sys_open( const char *path, int flags);
int sys_close( int fd);
int sys_write(int fd,char *buffer, int size);
int sys_read(int fd,char *buffer, int size);

int sys_dup(int fd);

int sys_unlink (const char * name);

sighandler_t sys_signal(int signum, sighandler_t handler);
int sys_kill (int pid, int sig);

// Internal signal sending function!
union task_union;
void task_signal(union task_union *t,int sig);

/******** FILE SYSTEM ********/
#define     O_RDONLY   0x1
#define     O_WRONLY   0x2
#define     O_RDWR     (O_RDONLY | O_WRONLY)
#define     O_CREAT    0x4
#define     O_EXCL     0x8

#define     NUM_DEVICES_TYPE  4

#define     TYPE_FILE      0x0
#define     TYPE_SCREEN    0x1
#define     TYPE_KEYBOARD  0x2
#define     TYPE_PIPE      0x3

struct file_descriptor_struct {
  int curr_position;        // In a seekable stream, the position, otherwise -1
  int mode;                 // Read, write, etc
  int fileid;               // The id to pass the specific functions
  struct file_operations * file_op; // Pointer to the device descriptor

  int entry_usage; // Indicates the entry usage (may be shared by father and child)
};
extern struct file_descriptor_struct system_fd[NR_FD_SYSTEM];

struct file_descriptor_struct * get_free_fd();
void InitializeFD();

/*********** PIPES **********/
#define PIPE_SIZE 1024
#define NR_PIPES  12
struct struct_pipe {
  int used;
  int pos;
  int length;
  int broken;

  struct file_descriptor_struct * read_desc;
  struct file_descriptor_struct * write_desc;

  struct list_head readl;
  struct list_head writel;
  unsigned char buffer[PIPE_SIZE];
};
struct struct_pipe sys_pipes[NR_PIPES];

#endif



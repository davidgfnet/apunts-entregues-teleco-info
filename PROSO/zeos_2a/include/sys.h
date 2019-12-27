/*
 * sys.c - Syscalls declaration
 */

#ifndef __SYS__H__
#define __SYS__H__

#define READING  0
#define WRITING  1

#include <stats.h>

int sys_write(int fd,char *buffer, int size);
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

#endif



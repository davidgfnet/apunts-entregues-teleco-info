/*
 * sys.c - Syscalls declaration
 */

#ifndef __SYS__H__
#define __SYS__H__

#define READING  0
#define WRITING  1

int sys_write(int fd,char *buffer, int size);
int sys_ni_syscall();

#endif



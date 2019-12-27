/*
 * libc.h - macros per fer els traps amb diferents arguments
 *          definició de les crides a sistema
 */
 
#ifndef __LIBC_H__
#define __LIBC_H__

#include <stats.h>

int write(int fd,char *buffer,int size);
void itoa(int num, char *buffer);
int strlen (char * str);
void perror(void);

#endif  /* __LIBC_H__ */

/*
 * libc.c 
 */

#include <libc.h>
#include <errno.h>

int errno = 0;

/* Wrapper of  write system call */
int write(int fd,char *buffer,int size)
{
  int return_value;
  __asm__ volatile (
  "pushl %%ebx\n"

  "movl $4,%%eax\n"
  "movl %1,%%ebx\n"
  "movl %2,%%ecx\n"
  "movl %3,%%edx\n"
  "int $0x80\n"

  "popl %%ebx\n"
  "movl %%eax,%0\n"
  :"=m"(return_value):"m"(fd),"m"(buffer),"m"(size):"eax");

  if (return_value < 0)
  {
    errno = -return_value;
    return_value = -1;
  }
  return return_value;
}


/* Creates a string given a number */
void itoa(int num, char *buffer)
{
  if (num == 0)
  {
    buffer[0] = '0';
    buffer[1] = 0;
    return;
  }
  char digits[32]; int counter = 0;
  if (num < 0) *buffer++ = '-';
  while (num > 0)
  {
    digits[counter++] = num%10;
    num = num/10;
  }
  while (counter-- > 0)
    *buffer++ = '0'+digits[counter];
  *buffer = 0;
}

/* Calculates the length of a string */
int strlen (char * str) {
  int len = 0;
  while (*str++ != 0) len++;
  return len;
}

/* perror aux function */
void perror(void)
{
  switch (errno) {
  case EFAULT:  write(1,"Adresa incorrecta\n",18); break;
  case EINVAL:  write(1,"Valor incorrecte\n",17); break;
  case EBADF:   write(1,"Descriptor de fitxer no valid\n",30); break;
  case ENOSYS:  write(1,"Syscall inexistent\n",19); break;
  };
}



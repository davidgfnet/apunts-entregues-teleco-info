/*
 * libc.c 
 */

#include <libc.h>
#include <errno.h>

int errno = 0;

/* Code for a generic syscall wrapper 
   It saves the state and writes the possible 
   parameters to the registers ebx-edi and
   sets eax to "num" value.
   It also takes care about errno management.
*/
#define GENERIC_WRAPPER(num) \
  int return_value; \
  __asm__ volatile ( \
  "pushl %%ebx\n" \
  "pushl %%ecx\n" \
  "pushl %%edx\n" \
  "pushl %%esi\n" \
  "pushl %%edi\n" \
  "movl %1,%%eax\n" \
  "movl 8(%%ebp),%%ebx\n" \
  "movl 12(%%ebp),%%ecx\n" \
  "movl 16(%%ebp),%%edx\n" \
  "movl 20(%%ebp),%%esi\n" \
  "movl 24(%%ebp),%%edi\n" \
  "int $0x80\n" \
  "popl %%edi\n" \
  "popl %%esi\n" \
  "popl %%edx\n" \
  "popl %%ecx\n" \
  "popl %%ebx\n" \
  "movl %%eax,%0\n" \
  :"=m"(return_value):"c"(num)); \
  if (return_value < 0) \
  { \
    errno = -return_value; \
    return_value = -1; \
  } \
  return return_value; \


/* Wrapper for the system calls */
int fork(void) { GENERIC_WRAPPER(2) }
int write(int fd,char *buffer,int size) { GENERIC_WRAPPER(4) }
int getpid() { GENERIC_WRAPPER(20) }
int exit(void) { GENERIC_WRAPPER(1) }
int nice(int quantum) { GENERIC_WRAPPER(34) }

int sem_init(int n_sem, unsigned int value) { GENERIC_WRAPPER(21) }
int sem_wait(int n_sem) { GENERIC_WRAPPER(22) }
int sem_signal(int n_sem) { GENERIC_WRAPPER(23) }
int sem_destroy(int n_sem) { GENERIC_WRAPPER(24) }
int get_stats(int pid, struct stats *st) { GENERIC_WRAPPER(35) }



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
  case ESRCH:   write(1,"No existeix el proces\n",22); break;
  case EFAULT:  write(1,"Adresa incorrecta\n",18); break;
  case EINVAL:  write(1,"Valor incorrecte\n",17); break;
  case EBADF:   write(1,"Descriptor de fitxer no valid\n",30); break;
  case ENOSYS:  write(1,"Syscall inexistent\n",19); break;
  case ENOMEM:  write(1,"Memoria insuficient\n",20); break;
  case EBUSY:   write(1,"Dispositiu o recurs ocupat\n",27); break;
  };
}



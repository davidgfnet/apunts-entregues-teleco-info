/*
 * libc.c 
 */

#include <libc.h>
#include <errno.h>

int errno = 0;

/* Code for a generic syscall wrapper 
   It saves the state and writes the possible 
   parameters to the registers ebx-edx and
   sets eax to "num" value.
   It also takes care about errno management.
   It takes at maximum 3 parameters
*/


#define SYSCALL_WRAPPER(type,num) \
  __asm__ volatile ( \
  "pushl %0\n" \
  "jmp syscall_wrapper\n" \
  ::"c"(num)); \
  return (type)0;

#define GENERIC_WRAPPER(num) SYSCALL_WRAPPER(int,num)

/* Wrapper for the system calls */
int fork(void)    { GENERIC_WRAPPER(2) }
int getpid()      { GENERIC_WRAPPER(20) }
int getppid()     { GENERIC_WRAPPER(64) }
int exit(void)    { GENERIC_WRAPPER(1) }
int nice(int quantum) { GENERIC_WRAPPER(34) }

int write(int fd,char *buffer,int size)   { GENERIC_WRAPPER(4) }
int read(int fd,char *buffer,int size)    { GENERIC_WRAPPER(3) }
int open(const char * path, int flags)    { GENERIC_WRAPPER(5) }
int close (int fd)                        { GENERIC_WRAPPER(6) }
int unlink(const char *path)              { GENERIC_WRAPPER(10) }
int dup (int c)                           { GENERIC_WRAPPER(41) }
int dup2 (int c, int c2)                  { GENERIC_WRAPPER(63) }

int sem_init(int n_sem, unsigned int value) { GENERIC_WRAPPER(21) }
int sem_wait(int n_sem)                     { GENERIC_WRAPPER(22) }
int sem_signal(int n_sem)                   { GENERIC_WRAPPER(23) }
int sem_destroy(int n_sem)                  { GENERIC_WRAPPER(24) }
int get_stats(int pid, struct stats *st)    { GENERIC_WRAPPER(35) }
int waitpid(int pid, int options)           { GENERIC_WRAPPER(7) }

sighandler_t signal(int signum, sighandler_t handler)  { SYSCALL_WRAPPER(sighandler_t,48) }
int kill (int pid, int sig)                            { GENERIC_WRAPPER(37) }
unsigned int alarm(unsigned int sec)                   { GENERIC_WRAPPER(27) }

int pipe(int fildes[2])  { GENERIC_WRAPPER(42) }



/* perror aux function */
void perror(void)
{
  switch (errno) {
  case ESRCH:   printf("No existeix el proces\n"); break;
  case EFAULT:  printf("Adresa incorrecta\n"); break;
  case EINVAL:  printf("Valor incorrecte\n"); break;
  case EBADF:   printf("Descriptor de fitxer no valid\n"); break;
  case ENOSYS:  printf("Syscall inexistent\n"); break;
  case ENOMEM:  printf("Memoria insuficient\n"); break;
  case EBUSY:   printf("Dispositiu o recurs ocupat\n"); break;
  case EACCES:  printf("Permis denegat\n"); break;
  case ECHILD:  printf("No hi ha proces fill\n"); break;
  case EEXIST:  printf("El fitxer ja existeix\n"); break;
  case EMFILE:  printf("Massa arxius oberts\n"); break;
  case ENFILE:  printf("Massa arxius oberts al sistema\n"); break;
  case ENAMETOOLONG: printf("Nom d'arxiu massa llarg\n"); break;
  case ENOFILE: printf("No existeix el fitxer\n"); break;
  case ENOSPC:  printf("No hi ha espai lliure\n"); break;
  case EPERM:   printf("Operacio no permesa\n"); break;
  case EPIPE:   printf("Broken pipe\n"); break;
  };
}



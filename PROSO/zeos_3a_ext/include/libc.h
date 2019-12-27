/*
 * libc.h - macros per fer els traps amb diferents arguments
 *          definició de les crides a sistema
 */
 
#ifndef __LIBC_H__
#define __LIBC_H__

#define WNOHANG 1

typedef void (*sighandler_t)(int);

#define SIG_DFL ((sighandler_t)0)
#define SIG_IGN ((sighandler_t)1)
#define SIG_ERR ((sighandler_t)-1)

#define	SIGHUP		1
#define	SIGINT		2
#define	SIGQUIT		3
#define	SIGILL		4
#define	SIGTRAP		5
#define	SIGABRT		6
#define	SIGIOT		6
#define	SIGBUS		7
#define	SIGFPE		8
#define	SIGKILL		9
#define	SIGUSR1		10
#define	SIGSEGV		11
#define	SIGUSR2		12
#define	SIGPIPE		13
#define	SIGALRM		14
#define	SIGTERM		15
#define	SIGSTKFLT	16
#define	SIGCLD		SIGCHLD
#define	SIGCHLD		17
#define	SIGCONT		18
#define	SIGSTOP		19

#include <stats.h>

int getpid();
int getppid();
int fork(void);
int exit(void);
int nice(int quantum);

int sem_init(int n_sem, unsigned int value);
int sem_wait(int n_sem);
int sem_signal(int n_sem);
int sem_destroy(int n_sem);

int get_stats(int pid, struct stats *st);

int write(int fd,char *buffer,int size);
int read(int fd,char *buffer,int size);
int open(const char * path, int flags);
int close (int fd);
int dup (int c);
int dup2 (int c1,int c2);
int unlink(const char *path);

int waitpid(int pid, int options);

sighandler_t signal(int signum, sighandler_t handler);
int kill (int pid, int sig);
unsigned int alarm(unsigned int sec);

int pipe(int fildes[2]);

void itoa(int num, char *buffer);
void itohex(unsigned int num, char *buffer, int mayus);
int strlen (char * str);
void printf(const char * format, ...);

#endif  /* __LIBC_H__ */

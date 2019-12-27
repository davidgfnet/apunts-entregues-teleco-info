/*
 * sys.c - Syscalls implementation
 */

#include <devices.h>
#include <io.h>
#include <utils.h>
#include <errno.h>
#include <sys.h>

// Comprovador de decriptor de canal
// caldrà modificar-lo ja que ha de comprar l'existència del canal
int comprova_fd(int fd, int operacio)
{
  return (fd == 1 && operacio == WRITING);
}

/* Write syscall. Currently just writes to stdout or stderr (screen) */
/* TODO: Check if the buffer pointer is a valid user address */
int sys_write(int fd,char *buffer, int size)
{
  if (buffer == 0) return -EFAULT;
  if (size < 0) return -EINVAL;

  if (comprova_fd(fd,WRITING))
  {
    // Not memory enough to coyp the data (page fault by stack overflow)
    //char tempo_buffer[size];
    //copy_from_user(buffer,tempo_buffer,size);
    sys_write_console (buffer, size);
  }
  else
    return -EBADF;

  return size;
}

/* Empty function for empty syscalls */
int sys_ni_syscall()
{
  return -ENOSYS;
}



/*
 * sys.c - Syscalls implementation
 */

#include <devices.h>
#include <io.h>
#include <utils.h>
#include <errno.h>
#include <sched.h>
#include <stats.h>
#include <sys.h>
#include <list.h>
#include <mm.h>
#include <fat.h>
#include <mm_address.h>

extern void signal_return_routine(void);
// All the system file descriptors
struct file_descriptor_struct system_fd[NR_FD_SYSTEM];
// A list (ppid,pid) of dead processes
#define NR_DEAD 1024
int dead_processes[NR_DEAD][2] = {{-1,-1}};

int check_waitpid_queue(int exit_pid, int exit_ppid);
int any_children(int ppid);
int exit_process(struct task_struct * etask);

// Checks if a pointer is inside the User logical space
int comprova_usr_ptr(int init, int size) {
  return !(init < L_USER_START || (init+size) > USER_END);
}

struct file_descriptor_struct * get_free_fd()
{
  int i;
  for (i = 0; i < NR_FD_SYSTEM; i++)
    if (system_fd[i].entry_usage == 0)
      {
        system_fd[i].entry_usage = 1;
        return &system_fd[i];
      }
  return 0;
}


int sys_open(const char *path, int flags)
{
  if (!comprova_usr_ptr((int)path,FILE_NAME_SIZE+1)) return -EFAULT;
  char namebuf[FILE_NAME_SIZE+1];
  copy_from_user((void*)path,namebuf,FILE_NAME_SIZE+1);
  if (strlen(namebuf) > 10) return -ENAMETOOLONG; // Name too long!
  char * fname = (char*)namebuf;
  if (*fname == '/') fname++; // Remove the directory
  if ((flags & O_RDWR) == 0) return -EINVAL;
  if ((flags & (~(0xF))) != 0) return -EINVAL;

  struct task_struct * curr_task;
  current_task_addr(curr_task);

  // Search for a free channel in the PCB
  int i;
  for (i = 0; i < NR_FD; i++)
    if (curr_task->file_descriptors[i] == 0)
    {
      curr_task->file_descriptors[i] = get_free_fd();
      if (curr_task->file_descriptors[i] == 0) return -ENFILE;  // Maximum system FD
      int ret_val = zeosfat_open (fname, flags, curr_task->file_descriptors[i]);
      if (ret_val < 0) {
        curr_task->file_descriptors[i] = 0;
        return ret_val;
      }
      
      return i;
    }

  return -EMFILE;  // Maximum task FD
}

int sys_close(int fd)
{
  if (fd < 0 || fd >= NR_FD) return -EBADF;
  struct task_struct * curr_task;
  current_task_addr(curr_task);
  if (curr_task->file_descriptors[fd] == 0) return -EBADF;

  // Close the file and mark the task descriptor as unused
  int retval = zeosfat_close(curr_task->file_descriptors[fd]);
  curr_task->file_descriptors[fd] = 0;
  return retval;
}

int sys_read(int fd,char *buffer, int size)
{
  if (size < 0) return -EINVAL;
  if (size == 0) return 0;
  if (fd < 0 || fd >= NR_FD) return -EBADF;
  struct task_struct * curr_task;
  current_task_addr(curr_task);
  if (curr_task->file_descriptors[fd] == 0) return -EBADF;
  if (!comprova_usr_ptr((int)buffer,size)) return -EFAULT;

  if (curr_task->file_descriptors[fd]->file_op->read == 0) return -EBADF;
  return (curr_task->file_descriptors[fd]->file_op->read)(curr_task->file_descriptors[fd],buffer,size);
}

int sys_write(int fd,char *buffer, int size)
{
  if (size < 0) return -EINVAL;
  if (size == 0) return 0;
  if (fd < 0 || fd >= NR_FD) return -EBADF;
  struct task_struct * curr_task;
  current_task_addr(curr_task);
  if (curr_task->file_descriptors[fd] == 0) return -EBADF;
  if (!comprova_usr_ptr((int)buffer,size)) return -EFAULT;

  if (curr_task->file_descriptors[fd]->file_op->write == 0) return -EBADF;
  return (curr_task->file_descriptors[fd]->file_op->write)(curr_task->file_descriptors[fd],buffer,size);
}

int sys_unlink (const char * name)
{
  if (!comprova_usr_ptr((int)name,FILE_NAME_SIZE+1)) return -EFAULT;
  char namebuf[FILE_NAME_SIZE+1];
  copy_from_user((void*)name,namebuf,FILE_NAME_SIZE+1);
  if (strlen(namebuf) > 10) return -ENAMETOOLONG; // Name too long!
  char * fname = (char*)namebuf;
  if (*fname == '/') fname++; // Remove the directory

  return zeosfat_delete(name);
}

int sys_dup(int fd)
{
  if (fd < 0 || fd >= NR_FD) return -EBADF;
  struct task_struct * curr_task;
  current_task_addr(curr_task);
  if (curr_task->file_descriptors[fd] == 0) return -EBADF; // Unused channel!

  // Search for a free channel in the PCB
  int i;
  for (i = 0; i < NR_FD; i++)
    if (curr_task->file_descriptors[i] == 0)
    {
      curr_task->file_descriptors[i] = curr_task->file_descriptors[fd];
      curr_task->file_descriptors[fd]->entry_usage++;
      if (curr_task->file_descriptors[i]->fileid >= 0) zeosfat_directory[curr_task->file_descriptors[i]->fileid].used++;
      return i;
    }

  return -EMFILE;
}

int sys_dup2(int fd, int newfd) 
{
  if (fd < 0 || fd >= NR_FD) return -EBADF;
  if (newfd < 0 || newfd >= NR_FD) return -EBADF;
  struct task_struct * curr_task;
  current_task_addr(curr_task);
  if (curr_task->file_descriptors[fd] == 0) return -EBADF; // Unused channel!

  if (curr_task->file_descriptors[fd] != 0) {  // Dest channel used! Close it!
    sys_close(newfd);
  }

  // Copy the channel info
  curr_task->file_descriptors[newfd] = curr_task->file_descriptors[fd];
  curr_task->file_descriptors[fd]->entry_usage++;
  if (curr_task->file_descriptors[newfd]->fileid >= 0) zeosfat_directory[curr_task->file_descriptors[newfd]->fileid].used++;

  return newfd;
}

int sys_pipe(int fildes[2]) {
  if (!comprova_usr_ptr((int)fildes, sizeof(int)*2)) return -EFAULT;

  struct task_struct * curr_task;
  current_task_addr(curr_task);

  // Search an unused PIPE
  int pipe;
  for (pipe = 1; pipe < NR_PIPES; pipe++)
    if (sys_pipes[pipe].used == 0)
      break;
  if (pipe == NR_PIPES) return -ENOMEM;
 
  int fd1 = -1, fd2 = -1;

  int i;
  for (i = 0; i < NR_FD; i++)
    if (curr_task->file_descriptors[i] == 0)
    {
      if (fd1 >= 0) {
        fd2 = i;
        break;
      }else{
        fd1 = i;
      }
    }
  
  if (fd1 < 0 || fd2 < 0) return -EMFILE;
  
  curr_task->file_descriptors[fd1] = get_free_fd();
  if (curr_task->file_descriptors[fd1] == 0) return -ENFILE;
  curr_task->file_descriptors[fd2] = get_free_fd();
  if (curr_task->file_descriptors[fd2] == 0) {
    curr_task->file_descriptors[fd1]->entry_usage--;
    return -ENFILE;
  }

  sys_pipes[pipe].used = 1;
  sys_pipes[pipe].pos = 0;
  sys_pipes[pipe].length = 0;
  sys_pipes[pipe].broken = 0;
  sys_pipes[pipe].read_desc = curr_task->file_descriptors[fd1];
  sys_pipes[pipe].write_desc = curr_task->file_descriptors[fd2];

  INIT_LIST_HEAD(&sys_pipes[pipe].readl);
  INIT_LIST_HEAD(&sys_pipes[pipe].writel);

  curr_task->file_descriptors[fd1]->curr_position = 0;
  curr_task->file_descriptors[fd2]->curr_position = 0;

  curr_task->file_descriptors[fd1]->mode = O_RDONLY;
  curr_task->file_descriptors[fd2]->mode = O_WRONLY;

  curr_task->file_descriptors[fd1]->fileid = -pipe;
  curr_task->file_descriptors[fd2]->fileid = -pipe;

  curr_task->file_descriptors[fd1]->file_op = &device_operations[TYPE_PIPE];
  curr_task->file_descriptors[fd2]->file_op = &device_operations[TYPE_PIPE];

  copy_to_user(&fd1,&fildes[0],sizeof(int));
  copy_to_user(&fd2,&fildes[1],sizeof(int));

  return 0;
}

int sys_getpid()
{
  struct task_struct * curr_task;
  current_task_addr(curr_task);
  return curr_task->pid;
}

int sys_getppid()
{
  struct task_struct * curr_task;
  current_task_addr(curr_task);
  return curr_task->ppid;
}

int sys_fork()
{
  union task_union * curr_task;
  current_task_addr(curr_task);

  // Create a new process but continue executing the parent
  int i;
  union task_union * ftask = reserve_pcb(pid_number_counter+1);
  if (ftask == 0) return -ENOMEM;

  // Copy all the PCB + kernel stack
  copy_data((void*)curr_task,((void*)ftask),sizeof(union task_union));
  ftask->saved_regs.eax = 0;  // Modify eax for the child 

  // Set the pid, the quantum and add it to the runqueue
  ftask->task.ppid = ftask->task.pid;  // Copy the parent pid to ppid
  ftask->task.pid = (++pid_number_counter);
  ftask->task.p_stats.remaining_tics = ftask->task.init_quantum;
  ftask->task.p_stats.total_trans = 0;
  ftask->task.p_stats.total_tics = 0;

  // Duplicate the channels, just add +1 to the fat usage!
  for (i = 0; i < NR_FD; i++)
    if (ftask->task.file_descriptors[i] != 0) {
      if (ftask->task.file_descriptors[i]->fileid >= 0)
        zeosfat_directory[ftask->task.file_descriptors[i]->fileid].used++;  // File usage
      ftask->task.file_descriptors[i]->entry_usage++; // System FD table usage
    }

  // Now reserve some physical pages for the data and save those page numbers in the PCB
  for (i = 0; i < NUM_PAG_DATA; i++) {
    ftask->task.phy_data_pages[i] = alloc_frame();
    if (ftask->task.phy_data_pages[i] < 0) {
      free_pcb(ftask);
      int j;
      for (j = 0; j < i; j++) free_frame(ftask->task.phy_data_pages[j]);
      return -ENOMEM;
    }
  }

  list_add_tail(&ftask->task.plist,&runqueue);

  // Finally copy the data pages, to do that we need to map
  // the new process data block in to unused logical addresses
  for (i = 0; i < NUM_PAG_DATA; i++)
    set_ss_pag((AUXILIAR_LOGIC_ZONE>>12)+i,ftask->task.phy_data_pages[i]);
  set_cr3();

  copy_data((void*)(L_USER_START+NUM_PAG_CODE*0x1000),(void*)AUXILIAR_LOGIC_ZONE,NUM_PAG_DATA*0x1000);
  // Now remove the mapping and flush TLB
  for (i = 0; i < NUM_PAG_DATA; i++)
    del_ss_pag((AUXILIAR_LOGIC_ZONE>>12)+i);
  set_cr3();

  return pid_number_counter;
}

int sys_exit()
{
  struct task_struct * curr_task;
  current_task_addr(curr_task);

  int ret_code = exit_process(curr_task);
  if (ret_code < 0) return ret_code;

  task_switch(LIST_TO_UNION(runqueue.next),0);
  return 0;
}

// This func terminates any process
int exit_process(struct task_struct * etask) {
  if (etask->pid == 0)
    return -1;

  // Close all the files!!!
  int i;
  for (i = 0; i < NR_FD; i++)
    if (etask->file_descriptors[i] != 0)
      zeosfat_close(etask->file_descriptors[i]);

  // Destroy their semaphores!
  for (i = 0; i < NR_SEM; i++) 
    if (sem_list[i].owner == etask->pid)
      sys_sem_destroy(i);

  // Unblock the processes that may be waiting on this
  // process exit!

  if (check_waitpid_queue(etask->pid,etask->ppid) == 0) {
    // Add the process to the dead list just in case the
    // parent asks for a waitpid
    if (etask->ppid != 0) {
      for (i = 0; i < NR_DEAD; i++)
        if (dead_processes[i][0] < 0) {
          dead_processes[i][0] = etask->ppid;
          dead_processes[i][1] = etask->pid;
          break;
        }
    } // Process 0 won't wait for us!
  } // Else, we don't need to use dead table as the parent is waiting
  
  // Mark the process PCB as unused by PID=-1
  etask->p_stats.remaining_tics = 0; // Force the process to abandon the CPU
  // Now delete all the physical pages used by the process
  for (i = 0; i < NUM_PAG_DATA; i++)
    free_frame(etask->phy_data_pages[i]);

  struct task_struct * curr_task;
  current_task_addr(curr_task);

  list_del(&etask->plist);
  free_pcb(TASK_TO_UNION(etask));

  return 0;
}

int sys_nice(int quantum)
{
  if (quantum <= 0) return -EINVAL;
  struct task_struct * curr_task;
  current_task_addr(curr_task);
  int last = curr_task->init_quantum;
  curr_task->init_quantum = quantum;
  return last; 
}

int sys_sem_init(int n_sem, unsigned int value)
{
  int mypid = sys_getpid();
  // Invalid semaphore
  if (n_sem < 0 || n_sem >= NR_SEM) return -EINVAL;

  if (sem_list[n_sem].used == 0)
  {
    sem_list[n_sem].owner = mypid;
    sem_list[n_sem].used = 1;
    sem_list[n_sem].value = value;
    INIT_LIST_HEAD(&sem_list[n_sem].sem_queue);
    return 0;
  }
  else
  {
    return -EBUSY;
  }
}

int sys_sem_wait(int n_sem)
{
  if (n_sem < 0 || n_sem >= NR_SEM) return -EINVAL;
  if (sys_getpid() == 0) return -1; // Can't block init
  if (sem_list[n_sem].used == 0) return -EINVAL; // Unitialized

  struct task_struct * curr_task;
  current_task_addr(curr_task);

  if (sem_list[n_sem].value == 0) {
    // Block process
    list_del(&curr_task->plist);
    list_add_tail(&curr_task->plist,&sem_list[n_sem].sem_queue);
    // Put a 0 in EAX (OK)
    (TASK_TO_UNION(curr_task))->saved_regs.eax = 0;
    curr_task->p_stats.remaining_tics = 0;

    task_switch(LIST_TO_UNION(runqueue.next),0);
  }else{
    // Just decrement
    sem_list[n_sem].value--;
  }
  return 0;
}

int sys_sem_signal(int n_sem)
{
  if (n_sem < 0 || n_sem >= NR_SEM) return -EINVAL;
  if (sem_list[n_sem].used == 0) return -EINVAL; // Unitialized

  if (list_empty(&sem_list[n_sem].sem_queue)) {
    // No processes blocked just increment
    sem_list[n_sem].value++;
  }else{
    // There's a process blocked
    struct list_head * unblock = sem_list[n_sem].sem_queue.next;
    list_del(unblock);
    list_add_tail(unblock,&runqueue);
  }
  return 0;
}

int sys_sem_destroy(int n_sem)
{
  // Destroy the semaphore and put all the processes in the runqueue
  int mypid = sys_getpid();
  if (n_sem < 0 || n_sem >= NR_SEM) return -EINVAL;
  if (sem_list[n_sem].used == 0) return -EINVAL;
  if (sem_list[n_sem].owner != mypid) return -EPERM;

  while (!list_empty(&sem_list[n_sem].sem_queue)) {
    // Put a -1 in the process EAX
    LIST_TO_UNION(sem_list[n_sem].sem_queue.next)->saved_regs.eax = -1;
    // Now signal to unblock it
    sys_sem_signal(n_sem);
  }

  sem_list[n_sem].owner = -1;
  sem_list[n_sem].used = 0;
  return 0;
}

int sys_get_stats(int pid, struct stats *st) {
  if (pid < 0) return -EINVAL;
  if (comprova_usr_ptr((int)st,sizeof(struct stats))) {
    struct task_struct * task = get_task_by_pid(pid);
    if (task == 0)  return -ESRCH;
    copy_to_user(&task->p_stats,st,sizeof(struct stats));
    return 0;    
  }
  else
  {
    return -EFAULT;
  }
}

// Assign a handler to a signal and return the last one
sighandler_t sys_signal(int signum, sighandler_t handler) {
  if (signum < 1 || signum > 31) return SIG_ERR;

  struct task_struct * curr_task;
  current_task_addr(curr_task);

  sighandler_t old = curr_task->handler_vector[signum];
  curr_task->handler_vector[signum] = handler;

  return old;
}

// Sends a signal to a process. It processes the signal, so
// in case of a process die it kills it (removes the pcb and
// all the stuff). In case the user uses a handler it prepares
// the process so the handler will be run at the process run time.
// IF the CURRENT PROCESS is KILLED, we perform a task_switch to
// another one (the next queued)
int sys_kill (int pid, int sig) {
  if (sig < 1 || sig > 31) return -EINVAL;
  if (pid <= 0) return -EINVAL;  // Just one process at a time, no init kill

  struct task_struct * task = get_task_by_pid(pid);
  if (task != 0) {
    pid = -1;
    task_signal(TASK_TO_UNION(task),sig);
  }

  if (pid >= 0) return -ESRCH;  // PID not found
  return 0;
}

#define USER_PUSH_INT(union,value) \
  union->saved_regs.oldesp -= 4; \
  copy_to_user(&value,(int*)union->saved_regs.oldesp,4);

#define USER_PUSH_CHARBUFFER(union,pointer,size) \
  union->saved_regs.oldesp -= size; \
  copy_to_user(pointer,(char*)union->saved_regs.oldesp,size);


// Given a task and a signal it processes the signal action
// Prepares the handler stack and HW state as well as changes EIP.
// It handles STOP/CONT by moving the process to a stopped queue.
// It handles a process death by deleting entirely it.
// In case of death or stop of the CURRENT PROCESS, task_switch 
// to the next queued!!!
void task_signal(union task_union *t,int sig) {
  struct task_struct * curr_task;
  current_task_addr(curr_task);

  if (t->task.handler_vector[sig] == SIG_DFL || ((t->task.handler_vector[sig] != SIG_DFL) && (SIG_NOT_IGNORABLE&(1<<sig)))) {
    // Default action is to kill the process (use exit!)
    // or stop/continue in case of SIGSTOP SIGCONT
    switch(sig) {
    case SIGCONT:
		continue_process(t);
		break;
    case SIGSTOP:
		pause_process(t);
        // We may have terminated the current process, if so switch to the next
        if (&t->task == curr_task)
          task_switch(LIST_TO_UNION(runqueue.next),0);

		break;
    case SIGCHLD: break; // Ignore by default action
    default:
      exit_process(&t->task);
      // We may have terminated the current process, if so switch to the next
      if ((&t->task) == curr_task)
        task_switch(LIST_TO_UNION(runqueue.next),0);

      break;
    };
  }
  else if (t->task.handler_vector[sig] == SIG_IGN) {
    // Do nothing
  }
  else {
    // The user installed a signal handler, what we have to do??
    // Install a payload to return and restore the state, see docs.

    map_task_pages(&t->task);

    // Current position
    USER_PUSH_INT(t,t->saved_regs.eip)

    // State of the process
    USER_PUSH_INT(t,t->saved_regs.eflags)
    USER_PUSH_INT(t,t->saved_regs.edx)
    USER_PUSH_INT(t,t->saved_regs.ecx)
    USER_PUSH_INT(t,t->saved_regs.eax)

    // The false EIP to point the above code
    USER_PUSH_INT(t,sig)       // Elimina pop algo
	int fake_eip = (int)signal_return_routine;
	USER_PUSH_INT(t,fake_eip)

    // Now modify the eip to jump to handler
    t->saved_regs.eip = (int)t->task.handler_vector[sig];

    // Set the handler back to default!
    t->task.handler_vector[sig] = SIG_DFL;

    // Unmap!
    map_task_pages(curr_task);
  }

}

// alarm call for the CURRENT task
// Sets up/disables the alarm
unsigned int sys_alarm(unsigned int sec) {
  struct task_struct * curr_task;
  current_task_addr(curr_task);

  // Retorna 0 en cas que no n'hi hagi o bé el temps que queda si n'hi ha
  unsigned int last_alarm = curr_task->init_alarm;
  if (last_alarm != 0) last_alarm = curr_task->rem_alarm;

  // Cancelar tota alarma previa!
  curr_task->init_alarm = sec*TICKS_PER_SEC;
  curr_task->rem_alarm = sec*TICKS_PER_SEC;

  return last_alarm/TICKS_PER_SEC;
}

// Put the CURRENT PROCESS in the waitpid queue
// and switch process waiting for a child to die
// In case a children already died do NOT block and return
// children PID. In case of error (pid not valid, no
// children, etc.) return immediatly with an error.
int sys_waitpid(int pid, int options) {
  int i;
  int mypid = sys_getpid();
  if (mypid == 0) return -1; // Can't block init!

  for (i = 0; i < NR_DEAD; i++) {
    if (dead_processes[i][0] == mypid) {
      if (pid < 0) { // Waiting for any PID
        // Delete the dead and return child pid
        int ret = dead_processes[i][1];
        dead_processes[i][0] = -1;
        dead_processes[i][1] = -1;
        return ret;
      }
      else if (pid == dead_processes[i][1]) {
        dead_processes[i][0] = -1;
        dead_processes[i][1] = -1;
        return pid;
      }
    }
    else if (pid > 0 && dead_processes[i][1] == pid) {
      // The user requested a waitpid on a dead process but
      // the process is not the parent!!!
      return -ECHILD;
    }
  }

  struct task_struct * curr_task;
  current_task_addr(curr_task);

  // Maybe the process does not have any children at all, so 
  // no need to block... Check it!
  if (!any_children(curr_task->pid)) {
    return -ECHILD;
  }

  if ((options & WNOHANG) != 0) {
    // The process has some children, not dead by now
    // but user wants to avoid blocking, just return 0
    return 0;
  }

  // No dead children by now! Block the process till an
  // exit occurs!
  curr_task->waitpid = pid;
  list_del(&curr_task->plist);
  list_add_tail(&curr_task->plist,&wpqueue);

  task_switch(LIST_TO_UNION(runqueue.next),0);
  
  return -1; // Never goes here! Just warings...
}

// Given a process going-to-die with exit_pid and exit_ppid
// find if there is a parent waiting (in waitqueue)
// and if so, just UNLOCK the process with EAX = exit_pid
int check_waitpid_queue(int exit_pid, int exit_ppid) {
  if (list_empty(&wpqueue)) return 0;

  struct list_head * iterator = wpqueue.next;
  int found = 0;
  do {
    struct task_struct * itask = (struct task_struct*)iterator;
    if (itask->waitpid < 0) {
      if (itask->pid == exit_ppid) found = 1;
    }else{
      if (itask->waitpid == exit_pid) found = 1;
    }
    if (!found) iterator = iterator->next;
  } while (&wpqueue != iterator && !found);

  if (found) {
    union task_union * itask = (union task_union*)iterator;
    // Update EAX!
    itask->saved_regs.eax = exit_pid;

    list_del(iterator);
    list_add_tail(iterator,&runqueue);
    return 1;
  }
  return 0;
}

int any_children(int ppid) {
  int i;
  for (i = 0; i < NR_TASKS; i++)
    if (task[i].t.task.ppid == ppid) return 1;

  return 0;
}

/* Empty function for empty syscalls */
int sys_ni_syscall()
{
  return -ENOSYS;
}

// Initializes the system FD and the task 0 FD
void InitializeFD() {
  // Initialize the file descriptors
  int i;
  for (i = 0; i < NR_FD_SYSTEM; i++)
  {
    system_fd[i].entry_usage = 0;
    system_fd[i].curr_position = 0;
    system_fd[i].mode = 0;
    system_fd[i].fileid = -1;
    system_fd[i].file_op = 0;
  }

  // And for the task 0
  for (i = 0; i < NR_FD; i++)
    task[0].t.task.file_descriptors[i] = 0;

  // Create the directory entries for the devices
  zeosfat_create("KEYBOARD", TYPE_KEYBOARD);
  zeosfat_create("DISPLAY", TYPE_SCREEN);

  // Allocate a sys FD for the stdin,stdout,stderr
  task[0].t.task.file_descriptors[0] = get_free_fd();
  task[0].t.task.file_descriptors[1] = get_free_fd();
  task[0].t.task.file_descriptors[2] = get_free_fd();
  // Just open the devices
  zeosfat_open ("KEYBOARD", O_RDONLY, task[0].t.task.file_descriptors[0]);
  zeosfat_open ("DISPLAY", O_WRONLY, task[0].t.task.file_descriptors[1]);
  zeosfat_open ("DISPLAY", O_WRONLY, task[0].t.task.file_descriptors[2]);
}



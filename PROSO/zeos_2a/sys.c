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
#include <mm_address.h>

extern struct protected_task_struct task[NR_TASKS];
extern int pid_number_counter;
extern struct list_head * runqueue;

// Comprovador de decriptor de canal
// caldrà modificar-lo ja que ha de comprar l'existència del canal
int comprova_fd(int fd, int operacio)
{
  return (fd == 1 && operacio == WRITING);
}

int comprova_usr_ptr(int init, int size) {
  return !(init < L_USER_START || (init+size) > USER_END);
}

/* Write syscall. Currently just writes to stdout or stderr (screen) */
int sys_write(int fd,char *buffer, int size)
{
  if (buffer == 0) return -EFAULT;
  if (!comprova_usr_ptr((int)buffer,size)) return -EFAULT;
  if (size < 0) return -EINVAL;

  if (comprova_fd(fd,WRITING))
  {
    // Not memory enough to coyp the data (page fault by stack overflow)
    //char tempo_buffer[size];
    //copy_from_user(buffer,tempo_buffer,size);
    return sys_write_console (buffer, size);
  }
  else
    return -EBADF;
}

int sys_getpid()
{
  struct task_struct * curr_task;
  current_task_addr(curr_task);
  return curr_task->pid;
}

int sys_fork()
{
  union task_union * curr_task;
  current_task_addr(curr_task);

  // Create a new process but continue executing the parent
  int i;
  union task_union * ftask = reserve_pcb();
  if (ftask == 0) return -ENOMEM;

  // Copy all the PCB + kernel stack
  copy_data((void*)curr_task,((void*)ftask),sizeof(union task_union));
  ftask->saved_regs.eax = 0;  // Modify eax for the child 

  // Set the pid, the quantum and add it to the runqueue
  ftask->task.pid = (++pid_number_counter);
  ftask->task.p_stats.remaining_tics = ftask->task.init_quantum;
  ftask->task.p_stats.total_trans = 0;
  ftask->task.p_stats.total_tics = 0;

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

  // Add to RUN queue
  list_add_tail(&ftask->task.plist,runqueue);

  return pid_number_counter;
}

int sys_exit()
{
  struct task_struct * curr_task;
  current_task_addr(curr_task);

  if (curr_task->pid == 0)
    return -1;

  // Destroy their semaphores!
  int i;
  for (i = 0; i < NR_SEM; i++) 
    if (sem_list[i].owner == curr_task->pid)
      sys_sem_destroy(i);
  
  // Mark the process PCB as unused by PID=-1
  curr_task->pid = -1;
  curr_task->p_stats.remaining_tics = 0; // Force the process to abandon the CPU
  // Now delete all the physical pages used by the process
  for (i = 0; i < NUM_PAG_DATA; i++)
  {
    free_frame(curr_task->phy_data_pages[i]);
  }

  runqueue = runqueue->next;
  list_del(&curr_task->plist);
  free_pcb((union task_union*)curr_task);
  task_switch((union task_union*)runqueue,0);
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
    sem_list[n_sem].sem_queue = 0;
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
    if (sem_list[n_sem].sem_queue == 0) {
      runqueue = curr_task->plist.prev;
      sem_list[n_sem].sem_queue = &curr_task->plist;
      list_del(&curr_task->plist);
      INIT_LIST_HEAD(&curr_task->plist);
    }else{
      runqueue = curr_task->plist.prev;
      list_del(&curr_task->plist);
      list_add_tail(&curr_task->plist,sem_list[n_sem].sem_queue);
    }
    // Put a 0 in EAX (OK)
    ((union task_union*)curr_task)->saved_regs.eax = 0;
    curr_task->p_stats.remaining_tics = 0;

    task_switch((union task_union*)runqueue,0);
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

  if (sem_list[n_sem].sem_queue == 0) {
    // No processes blocked just increment
    sem_list[n_sem].value++;
  }else{
    // There's a process blocked
    int last_one = (sem_list[n_sem].sem_queue == sem_list[n_sem].sem_queue->next);

    if (last_one) {
      list_add_tail(sem_list[n_sem].sem_queue,runqueue);
      sem_list[n_sem].sem_queue = 0;
    }else{
      struct list_head * unblock = sem_list[n_sem].sem_queue;
      sem_list[n_sem].sem_queue = sem_list[n_sem].sem_queue->next;
      list_del(unblock);
      list_add_tail(unblock,runqueue);
    }
  }
  return 0;
}

int sys_sem_destroy(int n_sem)
{
  // Destroy the semaphore and put all the processes in the runqueue
  int mypid = sys_getpid();
  if (n_sem < 0 || n_sem >= NR_SEM) return -EINVAL;
  if (sem_list[n_sem].used == 0) return -EINVAL;
  if (sem_list[n_sem].owner != mypid) return -1;

  while (sem_list[n_sem].sem_queue != 0) {
    // Put a -1 in the process EAX
    ((union task_union *)sem_list[n_sem].sem_queue)->saved_regs.eax = -1;
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
    int i;
    for (i = 0; i < NR_TASKS; i++) {
      if (task[i].t.task.pid == pid) {
        copy_to_user(&task[i].t.task.p_stats,st,sizeof(struct stats));
        return 0;
      }
    }
    return -ESRCH;
  }
  else
  {
    return -EFAULT;
  }
}

/* Empty function for empty syscalls */
int sys_ni_syscall()
{
  return -ENOSYS;
}



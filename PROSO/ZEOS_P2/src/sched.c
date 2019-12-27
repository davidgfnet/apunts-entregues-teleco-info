/*
 * sched.c - initializes struct for task 0
 */

#include <sched.h>
#include <mm.h>
#include <sys.h>
#include <segment.h>
#include <mm_address.h>
#include <devices.h>
#include <fat.h>
#include <utils.h>

int pid_number_counter = 0;
struct list_head runqueue;
struct list_head keyboardqueue;
struct list_head emptyqueue;
struct list_head wpqueue;
struct list_head stoppedqueue;

struct sem_struct sem_list[NR_SEM];

struct protected_task_struct task[NR_TASKS]
  __attribute__((__section__(".data.task")));

/* Erases all the process table
   and sets the default values. 
   Also inits the runqueue */
void initialize_tasks()
{
  INIT_LIST_HEAD(&keyboardqueue);
  INIT_LIST_HEAD(&wpqueue);
  INIT_LIST_HEAD(&stoppedqueue);
  int i,j;
  for (i = 0; i < NR_TASKS; i++)
  {
    task[i].t.task.pid = -1;
    task[i].t.task.ppid = -1;
    task[i].t.task.rem_alarm = 0;
    task[i].t.task.init_alarm = 0;
    task[i].t.task.init_quantum = INITIAL_QUANTUM;
    task[i].t.task.p_stats.remaining_tics = INITIAL_QUANTUM;
    task[i].t.task.p_stats.total_trans = 0;
    task[i].t.task.p_stats.total_tics = 0;
    INIT_LIST_HEAD(&task[i].t.task.plist);
    for (j = 0; j < NR_FD; j++)
      task[i].t.task.file_descriptors[j] = 0;
  }
  task[0].t.task.pid = 0;
  INIT_LIST_HEAD(&runqueue);
  list_add(&task[0].t.task.plist,&runqueue);
  // The task 0 has the code and data pages following the kernel pages
  for (i = 0; i < NUM_PAG_DATA; i++)
    task[0].t.task.phy_data_pages[i] = NUM_PAG_KERNEL+NUM_PAG_CODE+i;

  // Initialize semaphore table
  for (i = 0; i < NR_SEM; i++)
  {
    sem_list[i].value = 0;
    sem_list[i].owner = -1;
    sem_list[i].used  = 0;
    INIT_LIST_HEAD(&sem_list[i].sem_queue);
  }

  // Initialize signal handler vector
  for (i = 0; i < NUM_SIGNALS; i++) {
    task[0].t.task.handler_vector[i] = SIG_DFL;
  }

  // Init the empty process list
  INIT_LIST_HEAD(&emptyqueue);
  for (i = 1; i < NR_TASKS; i++) {
    list_add_tail(&task[i].t.task.plist,&emptyqueue);
  }

  for (i = 0; i < PID_HASH_TABLE_SIZE; i++) {
    pid_hash_table[i].pid = -1;
    pid_hash_table[i].task = 0;
  }
  pid_hash_table[0].pid = 0;
  pid_hash_table[0].task = &task[0].t.task;
}

void init_task0(void)
{
  /* Initializes paging for the process 0 adress space */
  initialize_P0_frames();
  set_user_pages();
  set_cr3();

  // Init the other tasks
  initialize_tasks();
}

void update_process_stats()
{
  struct task_struct * curr_task;
  current_task_addr(curr_task);
  curr_task->p_stats.total_tics++;
  curr_task->p_stats.remaining_tics--;
}

/* Checks if a process change is needed and then
   changes the logical address mapping to the process
   Returns the kernel stack base pointer (for TSS)
   so it can be updated
   If block_current it just removes the current
   from the runqueue and picks the following
*/
void processes_scheduler() {
  // Check if the quantum has expired!
  struct task_struct * curr_task;
  current_task_addr(curr_task);

  curr_task->p_stats.total_tics++;
  if (curr_task->p_stats.remaining_tics <= 0)
  {
    // Take deleted tasks from the queue
    // Change to the next process
    struct list_head * deleted = runqueue.next;
    list_del(deleted);
    list_add_tail(deleted,&runqueue);
    curr_task = LIST_TO_TASK(runqueue.next);
    // Change the page mappings
    task_switch ((union task_union *)curr_task,1);
  }
}


void task_switch(union task_union *t, int eoi) {
    struct task_struct * curr_task;
    current_task_addr(curr_task);
    curr_task->p_stats.total_trans++;
    curr_task->p_stats.remaining_tics = curr_task->init_quantum;

    map_task_pages(&t->task);

  if (eoi) {
    __asm__ __volatile__ (
    "movb $0x20, %al\n"
    "outb %al, $0x20\n"
    );
  }

  __asm__ __volatile__ (
  // ESP and ESP0 change
  "movl %0,%%esp\n"
  "add  %1,%%esp\n"
  "movl $(tss),%%ecx\n"
  "movl %%esp,4(%%ecx)\n"
  "add $(-16*4),%%esp\n"
  // State resore
  "popl %%ebx\n"
  "popl %%ecx\n"
  "popl %%edx\n"
  "popl %%esi\n"
  "popl %%edi\n"
  "popl %%ebp\n"
  "popl %%eax\n"
  "popl %%ds\n"
  "popl %%es\n"
  "popl %%fs\n"
  "popl %%gs\n"
  
  "iret\n"
  ::"r"(t),"c"(KERNEL_STACK_SIZE*4));
}


union task_union * reserve_pcb(int pid) {
  if (list_empty(&emptyqueue)) return 0; // No more PCBs avaliable
  union task_union * freeone = (union task_union *)emptyqueue.next;

  list_del(emptyqueue.next);

  int search = PID_HASH_TABLE_SIZE;
  int pos = pid%PID_HASH_TABLE_SIZE;
  while (search-- > 0) {
    if (pid_hash_table[pos].pid == -1) {
      pid_hash_table[pos].pid = pid;
      pid_hash_table[pos].task = &freeone->task;
      break;
    }
    pos = (pos+1)%PID_HASH_TABLE_SIZE;
  }

  return freeone;
}

void free_pcb(union task_union * pcb) {
  list_add(&pcb->task.plist, &emptyqueue);

  int search = PID_HASH_TABLE_SIZE;
  int pos = pcb->task.pid%PID_HASH_TABLE_SIZE;
  while (search-- > 0) {
    if (pid_hash_table[pos].pid == pcb->task.pid) {
      pid_hash_table[pos].pid = -1;
      pid_hash_table[pos].task = 0;
      break;
    }
    pos = (pos+1)%PID_HASH_TABLE_SIZE;
  }
  pcb->task.pid = -1;
}

struct task_struct * get_task_by_pid(int pid) {
  int search = PID_HASH_TABLE_SIZE;
  int pos = pid%PID_HASH_TABLE_SIZE;
  while (search-- > 0) {
    if (pid_hash_table[pos].pid == pid) {
      return pid_hash_table[pos].task;
    }
    pos = (pos+1)%PID_HASH_TABLE_SIZE;
  }
  return 0;
}

void pause_process(union task_union * pcb) {
  // Remove from runqueue
  list_del(&pcb->task.plist);
  list_add_tail(&pcb->task.plist,&stoppedqueue);
}

void continue_process(union task_union * pcb) {
  // Add to runqueue
  list_del(&pcb->task.plist);
  list_add_tail(&pcb->task.plist,&runqueue);
}

void update_alarms() {
  struct task_struct * curr_task;
  current_task_addr(curr_task);

  int i;
  for (i = 0; i < NR_TASKS; i++) {
    if (task[i].t.task.pid > 0 && curr_task != &task[i].t.task) {
      if (task[i].t.task.rem_alarm > 0) {
        task[i].t.task.rem_alarm--;
        if (task[i].t.task.rem_alarm == 0) {
          // Raise alarm!
          task_signal(&task[i].t,SIGALRM);
        }
      }
    }
  }

  // Now do the curr process just in case it dies (it will taskswtich us)
  if (curr_task->rem_alarm > 0) {
    curr_task->rem_alarm--;
    if (curr_task->rem_alarm == 0) {
      // Raise alarm!
      task_signal((union task_union *)curr_task,SIGALRM);
    }
  }
}


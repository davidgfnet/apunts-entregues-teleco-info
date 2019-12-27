/*
 * sched.h - Estructures i macros pel tractament de processos
 */

#ifndef __SCHED_H__
#define __SCHED_H__

#include <list.h>
#include <stats.h>
#include <io.h>
#include <types.h>

#define INITIAL_QUANTUM 4
#define NR_TASKS      10

struct sem_struct {
  int used;
  int owner;
  unsigned int value;
  struct list_head sem_queue;
};
extern struct sem_struct sem_list[NR_SEM];

struct task_struct {
  struct list_head plist;

  int pid, ppid;
  int init_quantum;
  struct stats p_stats;
  struct file_descriptor_struct * file_descriptors[NR_FD];

  // Data saved for blocked process
  int req_bytes;
  char * req_buffer;
  // waitpid
  int waitpid;
  // Signaling
  sighandler_t handler_vector[NUM_SIGNALS];
  // Alarms
  unsigned int rem_alarm, init_alarm;

  // Need to save the physical pages in order
  // to change between processes
  int phy_data_pages[NUM_PAG_DATA];
};

struct struct_stack_registers {
  int padding[1024-16];
  int ebx,ecx,edx,esi,edi,ebp,eax;
  int ds,es,fs,gs,eip,cs;
  int eflags,oldesp,oldss;
};

union task_union {
  struct task_struct task;
  unsigned long stack[KERNEL_STACK_SIZE];    /* pila de sistema, per procés */
  struct struct_stack_registers saved_regs;
};

struct protected_task_struct {
  unsigned long task_protect[KERNEL_STACK_SIZE];  /* This field protects the different task_structs, so any acces to this field will generate a PAGE FAULT exeption */
  union task_union t;
};

extern struct protected_task_struct task[NR_TASKS];
extern int pid_number_counter;
void processes_scheduler();
void clock_interrupt_routine();
void update_process_stats();

/* Inicialitza les dades del proces inicial */
void init_task0(void);
void task_switch(union task_union *t, int eoi);

extern struct list_head keyboardqueue;
extern struct list_head runqueue;
extern struct list_head wpqueue;
union task_union * reserve_pcb(int pid);
void free_pcb(union task_union * pcb);
struct task_struct * get_task_by_pid(int pid);

void pause_process(union task_union * pcb);
void continue_process(union task_union * pcb);

void update_alarms();

#define PID_HASH_TABLE_SIZE NR_TASKS
struct struct_pid_hash_table {
  int pid;
  struct task_struct * task;
} pid_hash_table[PID_HASH_TABLE_SIZE];

/* Returns the address of the current task_struct */
#define current_task_addr(variable) \
	__asm__ __volatile__ ( \
	"movl $(0xFFFFF000),%0\n" \
	"and  %%esp,%0\n" \
	:"=r"(variable));

#endif  /* __SCHED_H__ */

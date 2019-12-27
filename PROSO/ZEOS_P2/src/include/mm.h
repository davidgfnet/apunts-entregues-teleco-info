/*
 * mm.h - Capçalera del mòdul de gestió de memòria
 */

#ifndef __MM_H__
#define __MM_H__

#include <types.h>
#include <mm_address.h>
#include <sched.h>
 
#define FREE_FRAME 0
#define USED_FRAME 1
/* Bytemap to mark the free physical pages */
extern Byte phys_mem[TOTAL_PAGES];

int init_frames( void );
int alloc_frame( void );
void free_frame( unsigned int frame );
int initialize_P0_frames(void);
void set_user_pages( void );


extern Descriptor  *gdt;

extern TSS         tss; 

void init_mm();
void set_ss_pag(unsigned page,unsigned frame);
void set_ss_pag_kernel(unsigned page,unsigned frame);
void del_ss_pag(unsigned pagina_logica);
void set_cr3();

void setGdt();

void setTSS();

void map_task_pages(struct task_struct * t);

void init_kheap();

#endif  /* __MM_H__ */

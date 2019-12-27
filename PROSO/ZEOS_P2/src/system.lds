/*
 *  ZeOS
 *  system.lds - Linker Script for ZeOS system image.
 */

ENTRY(main)
SECTIONS
{
  . = 0x10000;
    
  .text.main : { 
    /* reserved to store user code size */
    BYTE(24);
    *(.text.main) 
  }
                                     
  .text : { *(.text) }
  .rodata : { *(.rodata) }
  .data : { *(.data) }
  .bss : { *(.bss) }

  . = ALIGN(4096);
  .text.user_signal : { *(.text.user_signal) }

  . = ALIGN(4096);              /* task_structs array*/
  .data.task : { *(.data.task) }

  /* Merda! Vigilar amb el final del heap, la
     pantalla està mapejada per la puta BIOS i petaba
     Lo que ha costat trobar-ho */

  . = 0x040000;
  kernel_heap_start = ABSOLUTE(.);

  . = 0x080000;
  kernel_heap_end = ABSOLUTE(.);
}

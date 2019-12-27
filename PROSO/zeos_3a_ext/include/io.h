/*
 * io.h - Definició de l'entrada/sortida per pantalla en mode sistema
 */

#ifndef __IO_H__
#define __IO_H__

#include <types.h>
#include <mm_address.h>

/** Screen functions **/
/**********************/

Byte inb (unsigned short port);
void printc(char c);
void printk(char *string);
void screen_clear(void);
void printc_xy(int x,int y,char c);
void printf_xy(int x,int y,char * s);
void scroll_screen();

int sys_open_file (const char * name, int flags);
int sys_close_file (int fd);
int sys_read_file (int fd, char *buffer, int size);
int sys_write_file (int fd, char *buffer, int size);

int sys_open_screen (const char * name, int flags);
int sys_close_screen (int fd);
int sys_write_screen (int fd, char *buffer, int size);

int sys_open_keyboard (const char * name, int flags);
int sys_close_keyboard (int fd);
int sys_read_keyboard (int fd, char *buffer, int size);

#endif  /* __IO_H__ */


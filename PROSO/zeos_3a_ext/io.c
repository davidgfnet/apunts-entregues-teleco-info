/*
 * io.c - 
 */

#include <io.h>
#include <sys.h>
#include <utils.h>
#include <errno.h>
#include <devices.h>
#include <fat.h>

/**************/
/** Screen  ***/
/**************/

#define NUM_COLUMNS 80
#define NUM_ROWS    25

Byte x=0, y=0;

/* Read a byte from 'port' */
Byte inb (unsigned short port)
{
  Byte v;

  __asm__ __volatile__ ("inb %w1,%0":"=a" (v):"Nd" (port));
  return v;
}

void printc(char c)
{
  Word ch = (Word) (c & 0x00FF) | 0x0200;
  DWord screen = 0xb8000 + (y * NUM_COLUMNS + x) * 2;
   __asm__ __volatile__ ( "movb %0, %%al; outb $0xe9" ::"a"(c));
  if (++x >= NUM_COLUMNS)
  {
    x = 0;
    if (++y >= NUM_ROWS)
      y = 0;
  }
  __asm__ __volatile__("movw %0, (%1)" : : "g"(ch), "g"(screen));
}

void printk(char *string)
{
  int i;
  for (i = 0; string[i]; i++) {
    if (string[i] == '\n')
    {
      y++;
      x = 0;
      // Check if the screen is full and scroll it up!
      if (y == NUM_ROWS)
      {
        scroll_screen();
        y = NUM_ROWS-1;
      }
    }
    else
    {
      printc(string[i]);
    }
  }
}

/* Scrolls the screen by deleting the first line and moving all the lines up */
void scroll_screen()
{
  unsigned short * prev_line = (unsigned short*)0xb8000;
  unsigned short * next_line = prev_line+NUM_COLUMNS;
  int ly;
  for (ly = 1; ly < NUM_ROWS; ly++)
  {
    int lx;
    for (lx = 0; lx < NUM_COLUMNS; lx++)
    {
      *prev_line++ = *next_line++;
    }
  }
  // Empty the last line
  int lx;
  for (lx = 0; lx < NUM_COLUMNS; lx++)
  {
    *prev_line++ = 32;
  }  
}

/* Empties all the screen */
void screen_clear()
{
  x = 0; y = 0;
  unsigned short * video_mem = (unsigned short*)0xb8000;
  int i;
  for (i = 0; i < NUM_COLUMNS*NUM_ROWS; i++)
  {
	  // Fill the screen with spaces
	  *video_mem++ = 32;
  }
}

/* Prints the character c in (x,y) position */
void printc_xy(int x,int y,char c)
{
  short * screen = (short*)(0xb8000 + (y * NUM_COLUMNS + x) * 2);
  *screen = (short)((0xFF & c) | 0x0f00 );
}

/* Prints the string s in (x,y) position */
void printf_xy(int x,int y,char * s)
{
  short * screen = (short*)(0xb8000 + (y * NUM_COLUMNS + x) * 2);
  while (*s != 0)
    *screen++ = (short)((0xFF & *s++) | 0x0f00 );
}



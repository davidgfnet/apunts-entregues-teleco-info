
#define NUM_COLUMNS 80
#define NUM_ROWS    25

#include <io.h>

extern Byte x,y;

int sys_write_console (char *buffer, int size)
{
  int i;
  for (i = 0; i < size; i++) {
    if (buffer[i] == '\n')
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
      short ch = (short) (buffer[i] & 0x00FF) | 0x0F00;
      short * screen = (short*)(0xb8000 + (y * NUM_COLUMNS + x) * 2);
      *screen = ch;
      x++;
      if (x > NUM_COLUMNS)
      {
        x = 0;
        y++;
        if (y == NUM_ROWS)
        {
          scroll_screen();
          y = NUM_ROWS-1;
        }
      }
    }
  }  
  return size;
}


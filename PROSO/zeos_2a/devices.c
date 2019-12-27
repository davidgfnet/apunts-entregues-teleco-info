
#define NUM_COLUMNS 80
#define NUM_ROWS    25

#include <io.h>
#include <utils.h>

extern Byte x,y;

int sys_write_console (char *buffer, int size)
{
  char local_buffer[16];
  int rem = size;
  while (rem > 0) {
    int todo = 16;
    if (rem < 16) todo = rem;

    copy_from_user(buffer,local_buffer,todo);
    buffer += todo;
    rem -= todo;
    
    int i;
    for (i = 0; i < todo; i++) {
      if (local_buffer[i] == '\n')
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
        short ch = (short) (local_buffer[i] & 0x00FF) | 0x0F00;
        short * screen = (short*)(0xb8000 + (y * NUM_COLUMNS + x) * 2);
        *screen = ch;
        x++;
        if (x >= NUM_COLUMNS)
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
  }
  return size;
}



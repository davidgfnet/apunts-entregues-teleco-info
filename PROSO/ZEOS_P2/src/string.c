
#include <libc.h>

// Ultra simple printf!
void printf(const char *format, ...) {
	int * numbers = (int*)&format;
	char temp_buffer[32];
	
	while (*format != 0) {
		if (*format == '%') {
			format++;
			switch(*format) {
				case 'd':
					++numbers;
					itoa(*numbers,temp_buffer);
					write(1,temp_buffer,strlen(temp_buffer));
					break;
				case 'x': case 'X':
					++numbers;
					itohex(*numbers,temp_buffer,(*format) == 'X');
					write(1,temp_buffer,strlen(temp_buffer));
					break;
				default: break;
			};
		}
		else {
			write(1,(void*)format,1);
		}
		format++;
	}
}


/* Creates a string given a number */
void itoa(int num, char *buffer)
{
  if (num == 0)
  {
    buffer[0] = '0';
    buffer[1] = 0;
    return;
  }
  char digits[32]; int counter = 0;
  if (num < 0) {
    *buffer++ = '-';
    num = -num;
  }
  while (num > 0)
  {
    digits[counter++] = num%10;
    num = num/10;
  }
  while (counter-- > 0)
    *buffer++ = '0'+digits[counter];
  *buffer = 0;
}

/* Calculates the length of a string */
int strlen (char * str) {
  int len = 0;
  while (*str++ != 0) len++;
  return len;
}

/* Creates a string given a number */
void itohex(unsigned int num, char *buffer, int mayus)
{
  buffer[0] = '0';
  buffer[1] = 'x';
  buffer += 2;

  if (num == 0)
  {
    buffer[0] = '0';
    buffer[1] = 0;
    return;
  }
  char digits[32]; int counter = 0;
  if (num < 0) *buffer++ = '-';
  while (num > 0)
  {
    digits[counter++] = num&0xF;
    num = num>>4;
  }
  char lookuptable[2][16] = { 	{'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'},
								{'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'} };
  while (counter-- > 0)
    *buffer++ = lookuptable[mayus][(int)digits[counter]];
  *buffer = 0;
}



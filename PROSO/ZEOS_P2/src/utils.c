#include <utils.h>
#include <types.h>
void copy_data(void *start, void *dest, int size)
{
  DWord *p = start, *q = dest;
  Byte *p1, *q1;
  while(size > 4) {
    *q++ = *p++;
    size -= 4;
  }
  p1=(Byte*)p;
  q1=(Byte*)q;
  while(size > 0) {
    *q1++ = *p1++;
    size --;
  }
}
/* Copia de espacio de usuario a espacio de kernel, devuelve 0 si ok y -1 si error*/
int copy_from_user(void *start, void *dest, int size)
{
  DWord *p = start, *q = dest;
  Byte *p1, *q1;
  while(size > 4) {
    *q++ = *p++;
    size -= 4;
  }
  p1=(Byte*)p;
  q1=(Byte*)q;
  while(size > 0) {
    *q1++ = *p1++;
    size --;
  }
  return 0;
}
/* Copia de espacio de kernel a espacio de usuario, devuelve 0 si ok y -1 si error*/
int copy_to_user(void *start, void *dest, int size)
{
  DWord *p = start, *q = dest;
  Byte *p1, *q1;
  while(size > 4) {
    *q++ = *p++;
    size -= 4;
  }
  p1=(Byte*)p;
  q1=(Byte*)q;
  while(size > 0) {
    *q1++ = *p1++;
    size --;
  }
  return 0;
}

/* access_ok: Checks if a user space pointer is valid
 * @type:  Type of access: %VERIFY_READ or %VERIFY_WRITE. Note that
 *         %VERIFY_WRITE is a superset of %VERIFY_READ: if it is safe
 *         to write to a block, it is always safe to read from it
 * @addr:  User space pointer to start of block to check
 * @size:  Size of block to check
 * Returns true (nonzero) if the memory block may be valid,
 *         false (zero) if it is definitely invalid
 */
int access_ok(int type, const void * addr, unsigned long size)
{
  return 0;
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
  if (num < 0) *buffer++ = '-';
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
int strlen (const char * str) {
  int len = 0;
  while (*str++ != 0) len++;
  return len;
}

/* Compares two strings */
int strcmp(const char * s1, const char * s2)
{
  while (*s1 != 0 && *s2 != 0)
  {
    if (*s1 < *s2) return -1;
    else if (*s1 > *s2) return 1;
    s1++; s2++;
  }
  if (*s1 == 0 && *s2 == 0) return 0;
  else if (*s1 == 0) return 1;
  return -1;
}

int intmax(int a, int b) {
  if (a > b) return a;
  return b;
}

int intmin(int a, int b) {
  if (a < b) return a;
  return b;
}


/* Creates a string given a number */
void itohex(unsigned int num, char *buffer)
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
  char lookuptable[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
  while (counter-- > 0)
    *buffer++ = lookuptable[(int)digits[counter]];
  *buffer = 0;
}



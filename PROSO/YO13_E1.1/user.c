#include <libc.h>

void runjp();

int __attribute__ ((__section__(".text.main")))
  main(void)
{

  runjp();

  while(1);
  return 0;
}



#include <libc.h>

/*
  Resumen:
  Implementado fork (crea proceso con retrorno 0)
  pero no bloquea el proceso que lo ejecuta.
  Implementado exit y fallo de página provoca exit
  también.
  Implementado round robin con posibilidad de usar
  nice para bajar o subir el quantum
  Implementados semáforos que bloquean y desbloquean
  procesos en función de su valor y lo hacen por orden
  de llegada al sem_wait. Se pueden bloquear todos los
  procesos que se quieran simultáneamente excepto el 0.
*/

void runjp();

int __attribute__ ((__section__(".text.main")))
  main(void)
{

  /* // STRESS TEST
  while (1) {
    if (fork() == 0) {
      char tempb[32];
      write(1,"\nSTRESS TEST\nMY PID IS: ",26);
      itoa(getpid(),tempb);
      write(1,tempb,strlen(tempb));
      exit();
    }
  }
  */
  

/*
 // DEMO PAGE FAULT
 // Tienes un hijo mu malo!
 if (fork() == 0) {
   *((int*)0x0) = 0;
 }
 write(1,"HOLA\n",5);
 if (fork() == 0) {
   *((int*)0xFFFFFFF0) = 0;
 }
 write(1,"HOLA\n",5);
 if (fork() == 0) {
   __asm__ __volatile__ ("jmp 0xFFFFFF00\n");
 }
 write(1,"HOLA\n",5);
*/

/*
 // DEMO SIGNALS, 2 PROCESSES WAITING SAME SEMAPHORE
  sem_init(1,0);
  write(1,"HOLA\n",5);
  if (fork() == 0) {
    fork();
    sem_wait(1);
  }else{
    int i,j;
    for (j = 0; j < 2; j++) {
    for (i = 0; i < 10000000; i++)
       __asm__ __volatile__ ("nop");
    sem_signal(1);
    write(1,"SIGN\n",5);
    }
    while(1);
  }

  if (fork() == 0) {
    write(1,"HIJO\n",5);
  }else{
    write(1,"PADRE\n",6);
  }
*/

/*
 //DEMO SIGNALS, 2 PROCESSES WAITING SAME SEMAPHORE, DESTROY
  sem_init(0,0);
  write(1,"HOLA\n",5);
  if (fork() == 0) {
    fork();
    sem_wait(0);
  }else{
    int i;
    for (i = 0; i < 10000000; i++)
       __asm__ __volatile__ ("nop");
    sem_destroy(0);
    write(1,"SIGN\n",5);
    while(1);
  }

  if (fork() == 0) {
    write(1,"HIJO\n",5);
  }else{
    write(1,"PADRE\n",6);
  }
*/

  runjp();

  while (1);
  return 0;
}



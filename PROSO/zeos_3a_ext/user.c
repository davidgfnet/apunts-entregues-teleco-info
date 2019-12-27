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


/*
void sigpipe(int sig) {
  printf("Received a SIGPIPE. Next SIGPIPE I'm dead!\n");
}

void myhandler2(int si) {
  printf("HANDLER!\n");
}

void myhandler(int a) {
  static int counter = 0;
  counter++;
  printf("We are in, signal is %d!\n",a);
  if (counter < 10) {
    signal(SIGALRM,myhandler);
    alarm(2);
  }else{
    printf("END!\n");
  }
}

void demo_pipe() {
  // DEMO PIPES
  if (fork() == 0) {
    int p[2];
    pipe(p);
    if (fork() == 0) {
      close(p[1]);
      char buf[11];
      read(p[0],&buf[0],1);
      read(p[0],&buf[1],10);
      write(1,buf,11);
      exit();
    }else{
      close(p[0]);
      signal(SIGPIPE,sigpipe);
      while(1) {
        int ret = write(p[1],"HELLO WORLD",11);
        printf("Write result: %d",ret);
//      int i; for (i = 0; i < 1000000; i++) __asm__ __volatile__ ("nop");
      }
    }
  }
  while(1);
}

void demo_alarm() {
  if (fork() == 0) {
    signal(SIGALRM,myhandler);
    alarm(2);
	while (1) {
		printf("Working...\n");

		int i;
		for (i = 0; i < 1000000; i++) __asm__ __volatile__ ("nop");
	}
  }
}

void demo_stop() {
  // STOPPING AND RESUMING PROCESSES
  if (fork() == 0) {
    int pid = fork();
    if (pid == 0) {
      int i,j;
      for (i = 0; i < 10; i++) {
        printf("Child working!\n");
        for (j = 0; j < 800000; j++) __asm__ __volatile__ ("nop");
      }
    }else{
      int i; for (i = 0; i < 1000000; i++) __asm__ __volatile__ ("nop");
      kill(pid,SIGSTOP);
      for (i = 0; i < 10000000; i++) __asm__ __volatile__ ("nop");
      kill(pid,SIGCONT);
      for (i = 0; i < 1000000; i++) __asm__ __volatile__ ("nop");
      kill(pid,SIGSTOP);
      for (i = 0; i < 10000000; i++) __asm__ __volatile__ ("nop");
      kill(pid,SIGCONT);
    }
  }
  while(1);
}

void demo_signal() {
  // SIGNAL HANDLER!!! Yeah!
  // Install hanlder!
  if (fork() == 0) {

    signal(SIGUSR1, myhandler2);
    signal(SIGUSR2, myhandler2);
    int pid = fork();
    if (pid == 0) {

      printf("HOLA HOLITA\n");

    }else{
      printf("Children PID %d\n",pid);
      kill(pid,SIGUSR2);
      kill(pid,SIGUSR2);
      kill(pid,SIGUSR1);

    }
    exit();
  }

  // Try to handle a KILL signal

  if (fork() == 0) {
    signal(SIGKILL, myhandler);
    kill(getpid(),SIGKILL);
    printf("Vivo! Error!\n");

    exit();
  }

  // Try to ignore a KILL signal

  if (fork() == 0) {
    signal(SIGKILL, SIG_IGN);
    kill(getpid(),SIGKILL);
    printf("Vivo! Error!\n");

    exit();
  }
  while(1);
}

void demo_waitpid() {
  // DEMO WAITPID!
  printf("Probando a llamar a waitpid sin hijos\n");
  if (fork() == 0) {
    waitpid(-1,0);
    printf("OK!\n");
    exit();
  }
  int i; for (i = 0; i < 1000000; i++) __asm__ __volatile__ ("nop");

  printf("Probando padre se bloquea y espera hijo\n");
  if (fork() == 0) {
    printf("Mi padre es %d\n",getppid());
    if (fork() == 0) {
      printf("Soy el hijo y mi padre es %d\n",getppid());
      exit();
    }else{
      int cpid = waitpid(-1,0);
      printf("Soy el padre con hijo PID: %d y mi padre es %d\n",cpid,getppid());
      exit();
    }
  }


  for (i = 0; i < 10000000; i++) __asm__ __volatile__ ("nop");
  printf("Probando el caso en que el padre no se llega a bloquear\n");
  if (fork() == 0) {

    if (fork() == 0) {
      printf("Soy el hijo con PID %d y mi padre es %d\n",getpid(),getppid());
      exit();
    }else{

      for (i = 0; i < 10000000; i++) __asm__ __volatile__ ("nop");
      printf("Fin espera, ahora no me bloqueo! Soy %d con padre %d\n",getpid(),getppid());
      int cpid = waitpid(-1,0);
      printf("Soy el padre con hijo PID: %d\n",cpid);

      exit();
    }
  }
  while(1);
}

void demo_signal_stress() {
/// SIGNAL STRESS TEST

  printf("Last test\n");
  // Stress test!
  int i;
  for (i = 0; i < 200; i++) {

    int pid = fork();
    printf("Fork return %d\n",pid);
    if (pid == 0) while(1);
    if (pid < 0) {

      printf("Error forking\n");
    }else{
      printf("killing %d\n",pid);
      kill (pid,SIGKILL);
    }

  }
  printf("JP END\n");
  while(1);
}

void demo_signal2() {
  // DEMO SIGNALS

  if (fork() == 0) {
    // Suicide!
    kill(getpid(),SIGKILL);
    printf("Error!\n");
    exit();

  }
  printf("Test 1 done\n");

  if (fork() == 0) {

    int pid = fork();
    if (pid == 0) {
      while (1) printf("CHILD ");
    }else{

      kill(pid,SIGKILL);
      exit();
    }
  }

  printf("Test 2 done\n");

  if (fork() == 0) {
    int pid1 = fork();

    if (pid1 == 0) while(1);

    int pid2 = fork();
    if (pid2 == 0) while(1);


    int pid3 = fork();
    if (pid3 == 0) while(1);

    kill(pid1,SIGKILL);

    kill(pid2,SIGKILL);
    kill(pid3,SIGKILL);
    kill(getpid(),SIGKILL);
  }

  printf("Test 3 done\n");
  while(1);
}


void demo_sem() {
 //DEMO SEM SIGNALS, 2 PROCESSES WAITING SAME SEMAPHORE, DESTROY
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
  while(1);
}

void demo_sem2() {
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
  while(1);
}


void demo_pagefault() {
  // DEMO PAGE FAULT
 // Tienes un hijo mu malo!
 if (fork() == 0) {
   *((int*)0x0) = 0;
 }
 write(1,"HOLA\n",5);
 if (fork() == 0) {
   void (*ptr) (void);
   ptr = 0;
   ptr();
 }
 write(1,"HOLA\n",5);
  while(1);
}
*/

int __attribute__ ((__section__(".text.main")))
  main(void)
{

  //demo_sem();
  //demo_sem2();
  //demo_signal_stress();
  //demo_waitpid();
  //demo_signal();
  //demo_signal2();
  //demo_alarm();
  //demo_pipe();
  //demo_stop();
  //demo_pagefault();

  runjp();
  while(1);

  while(1);
  return 0;
}



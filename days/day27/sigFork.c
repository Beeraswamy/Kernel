#include<stdio.h>
#include<signal.h>
#include<sys/types.h>

static int alarm_fired = 0;

void sigHandler(int sigNo)
{
  printf("SigNO: %d\n", sigNo);
  alarm_fired = 1;
}  

main()
{
  pid_t pid;
  printf("Alarm Specification starting\n");
  pid = fork();

  if(pid == 0)
  {
   sleep(5);
   alarm(5);
   kill(getppid(), SIGALRM);
   exit(0);
  }
  printf("Waiting for alarm to go off\n");
  signal(SIGALRM, sigHandler);

  pause();  /*  suspend execution until a signal occurs */
  if(alarm_fired)
   printf("Doing alarm\n");
  
  printf("Done\n");
  exit(0);
}

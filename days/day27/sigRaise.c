#include<stdio.h>
#include<signal.h>
#include<sys/types.h>

void sigHandler(int sigNo)
{
  printf("sigNo: %d\n", sigNo);
  //pause();
//  raise(SIGINT);
}

main( )
{
  pid_t pid;
  int stat;
  printf("pid = %d\n", getpid()); // It will get parent pid
  pid = fork();
  
  // printf("pid = %d\n", getpid());  //It will get child pid
  if(pid == 0)
  {
   printf("New process pid, pid= %d\n", getpid());
   sleep(3);
   printf("Going to call raise()\n");
//   alarm(1);
   signal(SIGALRM, sigHandler);
   raise(SIGALRM);
   //pause();
   printf("I am child, last statement\n");
  }
  
  else
  {
   wait(&stat);

   printf("pid = %d\n", getpid());
  // alarm(3);
   
   raise(SIGALRM);
  // pause();
   printf("I am parent\n");
  }
}

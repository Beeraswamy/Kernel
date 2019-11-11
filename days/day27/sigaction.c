#include<stdio.h>
#include<signal.h>
/*
struct sigaction {     //The minimum no. of members of sigaction
  void(*)(int) sa_handler;
  sigset_t sa_mask;
  int sa_flags;
};
*/
void sigHandler(int sigNo)
{
  printf("SigNO: %d\n", sigNo);
printf("Hello I am in sigHnadler\n");
printf("I am still working on blocking call\n");
	sleep(5);
   signal(SIGINT, SIG_DFL);/** This will get default action ***/
	
}

main()
{
 int sigNo;
	sigset_t sa_mask;
  struct sigaction act;

  act.sa_handler = sigHandler;
  act.sa_flags = 0;  
  act.sa_mask;
 
   sigemptyset(&act.sa_mask);
   sigaddset(&act.sa_mask, SIGILL);
		  /*specifies mask of signals which should be blocked during execution of signal handler*/
  sigaction(SIGINT, &act, 0);
 //signal(SIGINT, sigHandler);
  
  while(1)
  {
   printf("Hello, world\n");
   sleep(1);
  }
}


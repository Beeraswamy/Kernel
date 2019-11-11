#include <sys/types.h>
#include <sys/wait.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
int main()
{
	pid_t chpid, child1, child2;
	int i,stat;
	
	printf("I am a process my processs id is %d\n",getpid());
	printf("I am creating two child processes & make them run some code\n");
	
	child1 = fork();
	if(child1 == 0)
	{
		printf("I am first child, my pid is %d\n", getpid());
		printf("I first child going to execute following loop for 6 times\n");
		for(i=0;i<6;i++)
		{
			printf("I am child 1, this is iteration %d of loop\n",i+1);
			printf("I am tired, sleeping for 10 seconds\n");
			sleep(1);
		}
		exit(2);
	}
	child2 = fork();
	if(child2 == 0)
	{
		printf("I am second child, my pid is %d\n", getpid());
		printf("I second child going to execute following loop for 6 times\n");
		for(i=0;i<6;i++)

		{
			printf("I am child 2, this is iteration %d of loop\n",i+1);
			printf("I am tired, sleeping for 5 seconds\n");
			sleep(1);
		}
		exit(3);
	//	return 255;
	}
	printf("I am parent, my childeren are working & sleeping, i wait for them\n");
	chpid = wait(&stat);
	if(chpid == child1)
		printf("My first child terminated with status %d\n",WEXITSTATUS(stat));
	if(chpid == child2)
		printf("My second child terminated with status %d\n",WEXITSTATUS(stat));
	

	chpid = wait(&stat);
	if(chpid == child1)
		printf("My first child terminated with status %d\n",WEXITSTATUS(stat));
	if(chpid == child2)
		printf("My second child terminated with status %d\n",WEXITSTATUS(stat));

	printf("Both children got terminated, now i will do the same\n");
}
	


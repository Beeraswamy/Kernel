#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
int main()
{
	pid_t pid;
	int option, stat;
	while(1)
	{
		printf("Enter 1 to exec 'ls' program in child process and 0 to exit\n");
		scanf("%d", &option);
		if(!option)
			exit(0);
		printf("\n");
		if(fork()==0)
		{
			execl("/bin/ls","ls","-l",0);

			exit(5);		
		}
		pid = wait(&stat);
		printf("Child with pid %d is terminated\n",pid);
	}
}

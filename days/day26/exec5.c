/*The program shows the application of fork(), eecv() and wait() system calls in implementing our own shell program. This shell is not allowing any command line arguments. You can exten this shell program to take command line arguments to*/

#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
	pid_t pid;
	int option, stat;
	char cmdbuf[80];
	char cmdbuf1[50];
	char *cmdargs[4];
	
	while(1)
	{	
		printf("myshell>");
		gets(cmdbuf);
		cmdargs[0]=cmdbuf;
		//gets(cmdbuf1);		
		//cmdargs[1]=cmdbuf1;
		cmdargs[2]=0;
		if(strcmp(cmdbuf,"ver",3)==0)
		{
			printf("Simple shell version 1.00, Nov24,2010\n");
			continue;
		}
		if(strcmp(cmdbuf,"quit",4)==0)
			exit(0);
		gets(cmdbuf1);		
		cmdargs[1]=cmdbuf1;
		if(fork()==0)
		{
			execvp(cmdbuf,cmdargs);
			exit(0);		
		}
		pid = wait(&stat);
	}
}

	

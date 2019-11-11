#include<sys/shm.h>
#include<stdio.h>
#include<string.h>

int main()
{
	char *ptr;
	int shmid,pid;

	/* Create shared memory area */

	shmid=shmget((key_t)1,20,IPC_CREAT | 0666);

        /* Attach pointer to shared memory area */
	ptr=(char*)shmat(shmid,(char*)0,0);

	pid=fork();
	if(pid==0) {
		/* Copy data in the child process */
		strcpy(ptr,"Shared Memory\n");
	}
	else
	{
		wait(0);
		/* Read data from parent */
		printf("parent reads  ...%c\n",*(ptr+3));
		printf("parent reads %s\n",ptr);
	}
}


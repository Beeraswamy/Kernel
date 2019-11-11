#include<sys/shm.h>
#include<stdio.h>
#define SIZE 16
int main()
{
	char *ptr;
	int shmid,pid,i;
	/* Create */
	shmid=shmget((key_t)1,20,IPC_CREAT | 0666);

        /* Attach ptr */
        ptr=(char*)shmat(shmid,(char*)0,0);

	pid=fork();
	//ptr="EmbWiz";
	if(pid==0)
	{
		//strcpy(ptr,"Shared Memory\n");
		/* read data to STDOUT */
		i=read(0,ptr,SIZE);
		if(i==-1)
		{
			printf("\nRead failed\n");
		}
		else
			printf("Child reads %s\n",ptr);
	}
	else
	{
		/* Write data from STDOUT */
		write(1,ptr,SIZE);
		wait(0);
		printf("parent reads  ...%s",ptr);
		/* Destroys the memory */
		shmctl(shmid,IPC_RMID,NULL);
	}
}


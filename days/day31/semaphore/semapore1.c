#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
int get_semaphore(void);
int release_semaphore(void);
int sem_id;


union semun {
     int              val;    /* Value for SETVAL */
     struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
     unsigned short  *array;  /* Array for GETALL, SETALL */
     struct seminfo  *__buf;  /* Buffer for IPC_INFO
                                           (Linux specific) */
};

struct sembuf sem_op;//refer man page
union semun sem_union; /* Used internally by the kernel */

int main()
{
	int i;
	sleep(3);
	sem_id=semget((key_t)1234,1,0666|IPC_CREAT);
	
/* parm1: 1234-semaphore key that can be used by other process to share the same semaphore
 
 * parm 2:(1):No of semaphores i.e if u have more than one resources that has to be synchronized u can give a value other than one here
 
 * parm 3:flags that gives perms and to create a semaphore with those perms */
	
	sem_union.val=1;
	if(semctl(sem_id,0,SETVAL,sem_union)<0) /* semaphore initialization -- id,semnum,cmd,obj to sem_union */
		printf("error\n");
for(i=0;i<=5;i++)
{
	get_semaphore();
	printf("%d:got the semaphore\n",getpid());
	//sleep(1);
	getchar();
	printf("%d:released the semapore\n",getpid());
	release_semaphore();
	sleep(1);
	
}
if(semctl(sem_id,0,IPC_RMID,sem_union)<0)
	printf("Failed to delete the semaphore\n");
else
	printf("Semaphore deleted\n");
}


int get_semaphore(void)
{

    sem_op.sem_num=0;
    
    //gets the nth no of semaphore specified in sem_num, here its zero,i.e the zeroth semaphore in the semaphore array
    
    sem_op.sem_op=-1;
    
    /*decrements the nth semaphore by one.
    The 'n' value is specified by the variable sem_num in sembuf stucture,
    here the n value is zero (refer the previous statement)*/
    
    sem_op.sem_flg=SEM_UNDO;
	    
	    //this flag is optional but its wise to set this flag
	    //it tells the kernel to automatically release the semaphore 
	    //if this process terminates without releasing the semaphore...
	    //it can also have the flag IPC_NOWAIT(refer man)
    if(semop(sem_id,&sem_op,1)<0)
    {
	    printf("Failed to get the sempahore\n");
	    return -1;
    }
    /* param 1:Semaphore_id retured by semget systemcall
     * param 2:pointer to sem_buf structure(refer man)
     * param 3:no of semphore operations stuctures since we are using only one semphore we have the value 1 here*/
 return 0;
     
}
int release_semaphore(void)
{
  sem_op.sem_num=0;
  sem_op.sem_op=1; //same as above but here instead of incrementing we are decrementing the semaphore to release it
  sem_op.sem_flg=SEM_UNDO;
  if(semop(sem_id,&sem_op,1)<0)
  {
	  printf("Failed to release semaphore\n");
	  return -1;
  }
  return 0;
}

	
	
	

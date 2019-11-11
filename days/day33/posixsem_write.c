////*Using a mutex to protect access to global variable*//////
/* This program is a modified version of the previous program. It uses a mutex to protect access to the global variable glob. When we run this program with a similar command line to that used earlier, we see the glob is always reliably incremented*/
#include <pthread.h>
#include <semaphore.h>
sem_t sem;
static int glob = 0;


static void* threadFunc(void *arg)
{
	int loops = *((int *)arg);
	int loc, j, s;
	for(j=0;j<loops;j++)
	{
		/*Sem_wait function decrements(decreases by 1) the value of the semaphore referred to by sem
		If the semaphore currently has a value greater than o, sem_wait() returns immediately. if the value of the semaphore is currently 0, sem_wait blocks until the seamphore raise above 0.*/
		if (sem_wait(&sem) == -1)
			return;
		loc = glob;
		loc++;
		glob = loc;
		//The sem_post() function increments(increases by 1) the value of the semaphores referred to by sem.		
		if (sem_post(&sem) == -1)
			return;
		
	}
	return NULL;
}

int main(int argc, char *argv[])
{
	pthread_t t1, t2;
	int loops, s;
	
	//loops = getInt(argv[1], GN_GT_0, "num-loops") : 10000000;

	//The second argument - 0 Semaphore has to be shared between threads
	//			1 Semaphore has to be shared between process 
	//Third argument - intializes the tocken count to the value
	if (sem_init(&sem, 0, 1) == -1)
		return;
	loops = 100000;
	s = pthread_create(&t1, NULL, threadFunc, &loops);
	if(s != 0)
	{
		printf("pthread_create 1 ERROR\n");
		return;
	}
	s = pthread_create(&t2, NULL, threadFunc, &loops);
	if(s != 0)
	{
		printf("pthread_create 2 ERROR\n");
		return;
	}
	
	s=pthread_join(t1,NULL);
	if(s!=0)
	{
		printf("pthread_join 1 ERROR\n");
		return;
	}
	s=pthread_join(t2,NULL);
	if(s!=0)
	{
		printf("pthread_join 2 ERROR\n");
		return;
	}
	printf("glob = %d\n", glob);
	return 0;
}
	


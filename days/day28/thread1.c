#include <pthread.h>
#include <stdio.h>

int cnt;
pthread_t th; /*Thread id*/

void *mythfun(void *arg);

int main()
{
	char ch;
	int exitstat;
	void *retptr;
	
	printf("I am main thread, going to create new thread\n");
	
	pthread_create(&th, NULL, mythfun, (void*)2);
	
	while(1)
	{
		printf("I am main thread\n");
		ch = getchar();
		if(ch == 'c')
			printf("cnt = %c\n",cnt);
		if(ch == 'x')
			exit(2);
		if(ch == 'r')
		{
			printf("I am going wait till my child thread is terminated\n");
			pthread_join(th, &retptr);
			printf("my child terminated, the pointer returned is %d\n", retptr);
		}
	}
}


void *mythfun(void *arg)
{
	int sleepTime = (int)arg;
	while(1)
	{
		printf("I am sleeping %d seconds\n",sleepTime);
		sleep(sleepTime);
		cnt++;
		if(cnt == 10)
		{
			printf("Child process has terminated\n");			
			return (void*) 25;
		}
	}
}
		


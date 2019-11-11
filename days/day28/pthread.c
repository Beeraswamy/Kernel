#include <stdio.h>
#include <pthread.h>
//#include "tlpi_hdr.h"
//static void* threadFunc(void *arg)
	void* threadFunc(void *arg)
{
	char *s = (char *) arg;
	printf("%s\n",s);
	sleep(5);
	return (void*) strlen(s);
	
} 

int main(int argc, char *argv[]
)
{	
	pthread_t t1;
	void *res;
	int s;
	
	s=pthread_create(&t1, NULL, threadFunc, "Hello world");
printf("hi\n");	
if(s != 0)
//	errExitEn(s,"pthread_create");
//	printf("Message from main()\n");
//	s=pthread_join(t1,&res);
//if(s != 0)
//	errExit(s,"pthread_join");
//	printf("Thread returned %ld \n",(long)res);
//	exit(Exit_SUCCESS);
//	}
	{
		printf("pthread_create error %d\n",s);
		return;
	}
	
	printf("Messages from main()\n");
	sleep(5);
	s = pthread_join(t1, &res);
if(s !=0)
{
	printf("pthread_join error %d\n",s);
		return;
	}
	printf("Thread returned %ld\n", (long) res);
	pthread_exit(0);

} 

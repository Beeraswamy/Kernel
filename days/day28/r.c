#include<stdio.h>
#include<pthread.h>
//static pthread_mutex_t mtx=PTHREAD_MUTEX_INITIALIZER;
int global=0;
//pthread_mutex_init();
pthread_mutex_t mtx;
void *fun(void *arg)
{
int val,i,loc;
val=*((int *)arg);
for(i=0;i<val;i++)
	{
		pthread_mutex_lock(&mtx);
		loc=global;
		loc++;
		global=loc;	
		pthread_mutex_unlock(&mtx);	
	}

}

void *fun1(void *arg)
{
int i,val,loc;
val=*((int *)arg);
for(i=0;i<val;i++)
	{
		pthread_mutex_lock(&mtx);
		loc=global;
		loc++;
		global=loc;
		pthread_mutex_unlock(&mtx);
	}

}

main()
	{
		int loop=100000;
		pthread_t tid1,tid2;
		if(pthread_mutex_init(&mtx,NULL)<0)
	printf("init error\n");
	//int loop=100000;
	//pthread_t tid1,tid2;
	pthread_create(&tid1,NULL,fun,(void*)&loop);
	pthread_create(&tid2,NULL,fun1,(void*)&loop);

	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	
	printf("global val=%d\n",global);
//	sleep(100000);
//	pthread_exit(NULL);

}

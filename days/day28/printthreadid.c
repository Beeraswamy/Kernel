#include <pthread.h>

pthread_t ntid;

void printids(char *s)
{
	pid_t pid;
	pthread_t tid;
	printf("From main %u\n ",ntid);
	pid = getpid();
	tid = pthread_self();	
printf("\n%s pid \n%u tid \n%u (0x%x)\n",s,(unsigned int)pid,(unsigned int)tid, (unsigned int)tid);
}

void *thr_fn(void *arg)
{
	printids("new thread: ");
	return((void *)0);
}

int main(void)
{
	int err;	
	err = pthread_create(&ntid, NULL, thr_fn, NULL);
	if(err != 0)
		printf("can't create thread: %s\n", strerror(err));
	printids("main thread: ");
	sleep(1);
	exit(0);
}

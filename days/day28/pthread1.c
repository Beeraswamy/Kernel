////*Using a mutex to protect access to global variable*//////
/* This program is a modified version of the previous program. It uses a mutex to protect access to the global variable glob. When we run this program with a similar command line to that used earlier, we see the glob is always reliably incremented*/
#include <pthread.h>

static int glob = 0;
static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
static void* threadFunc(void *arg)
{
	int loops = *((int *)arg);
	int loc, j, s;
	for(j=0;j<loops;j++)
	{
		s = pthread_mutex_lock(&mtx);
		if(s!=0)
		{
			printf("pthread_mutex_lock 1 ERROR\n");
			return;
		}
		loc = glob;
		loc++;
		glob = loc;

		s = pthread_mutex_unlock(&mtx);
		if(s!=0)	
		{
			printf("pthread_mutex_lock 2 ERROR\n");
			return;
		}
	}
	return NULL;
}
int main(int argc, char *argv[])
{
	pthread_t t1, t2;
	int loops, s;
	
	//loops = (argc > 1) ? (getInt(argv[1],GN_GT_0,"num-loops") : 10000000;
	loops = 700000;
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
	

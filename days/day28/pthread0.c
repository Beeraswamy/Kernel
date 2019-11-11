//*Incorrectly incrementing a global variable from two threads*//
/*This program creates two threads, each of which executes same function. The function executes a loop that repeatedly increments a global variable, glob, by copying glob into the local variable loc, incrementing loc, and copying loc back to glob.(Since loc is an automatic variable allocated on per-thread stack, each thread has its own copy of this variable). The number of iteration of the loop is determined by the command-line argument supplied to the program, or by a default value, if no argument is specified.When we run the program in Listing 30-1 specifying that each thread should incre-
ment the variable 1000 times, all seems well:
$ ./thread_incr 1000
glob = 2000
However, what has probably happened here is that the first thread completed all of its work and terminated before the second thread even started. When we ask both threads to do a lot more work, we see a rather different result:
$ ./thread_incr 10000000
glob = 16517656
At the end of this sequence, the value of glob should be 20 million. The problem here results from execution sequences such as the following.
1. Thread 1 fetches the current value of glob into its local variable. Lets assume that the current value of glob is 2000.
2. The scheduler time slice for thread1 expires, and thread 2 commences execution.
3. Thread 2 performs multiple loops in which it fetches the current value of glob into its local variable loc, increments loc, and assigns the result to glob. In first of these loops, the value fetched from glob will be 2000. Lets suppose that the time the time slice for thread 2 has expired, glob has been increased to 3000.
4.Thread 1 receives another time slice and resumes execution where it left off. Having previously(step 1) copied the value of glob(2000) into tis loc, it now increments loc and assigns the result (2001) to glob. At this point the effect of the increment operation performed by thread 2 is lost.   

Note: The nondeterministic behaviour is a consequence of the vagaries of the kernel's CPU scheduling decisions. In complex programs, this non deterministic behaviour means that such errors may occur only rarely, be hard to reproduce and therefore difficult to find.
It might seem that we could eliminate the problem by replacing the 3 statements inside the for loop in the threadFunc() function with statement 
g++ *************
However, on many hardware architectures (RISC Architecture), the compiler would still need to convert the single statement into machine code whose steps are equivalent to the three statements inside the loop in threadFunc(). In other words despite its simple appearance, even a C increment operator may not be atomic and it might demonstrate the behaviour that we described above*/

#include <pthread.h>

static int glob = 0;

static void* threadFunc(void *arg)
{
	int loops = *((int *)arg);
	int loc, j;
	for(j=0;j<loops;j++)
	{	
		loc = glob;
		loc++;
		glob = loc;
	}
	return NULL;
}
int main(int argc, char *argv[])
{
	pthread_t t1, t2;
	int loops, s;
	
	//loops = (argc > 1) ? (getInt(argv[1],GN_GT_0,"num-loops") : 10000000;
	loops = 100;
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
	

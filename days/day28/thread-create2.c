#include <pthread.h>
#include <stdio.h>

/*Parameters to print_function*/
struct char_print_parms
{
	/*the character to print*/
	char character;	
	/*The number of times to print*/
	int count;
};

/*Prints a number of characters to stderr, as given by PARAMETERS, which is a pointer to a struct char_print_parms*/

void *char_print(void *parameters)
{
	/*Cast the cookie pointer to the right type*/
	struct char_print_parms *p= (struct char_print_parms *)parameters;
	int i;
	for(i=0;i < p->count;++i)
		putc(p->character,stderr);
	return NULL;
}

int main()
{
	pthread_t thread1_id;
	pthread_t thread2_id;
	
	struct char_print_parms thread1_args;
	struct char_print_parms thread2_args;
	
	/*Create a new thread to print 30,000 'x's*/
	thread1_args.character = 'x';
	thread1_args.count = 300;
	pthread_create(&thread1_id, NULL, &char_print, &thread1_args);
	/*Create a new thread to print 20,000 'o's*/
	thread2_args.character = 'o';
	thread2_args.count = 200;
	pthread_create(&thread2_id, NULL, &char_print, &thread2_args);
	return 0;
}


/*The program has a serious bug in it.The main thread (which
runs the main function) creates the thread parameter structures (thread1_args and
thread2_args) as local variables, and then passes pointers to these structures to the
threads it creates. the memory containing the thread parameter structures
will be deallocated while the other two threads are still accessing it.*/


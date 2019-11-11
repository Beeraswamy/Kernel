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
	thread1_args.count = 30;
	pthread_create(&thread1_id, NULL, &char_print, &thread1_args);
	/*Create a new thread to print 20,000 'o's*/
	thread2_args.character = 'o';
	thread2_args.count = 20;
	pthread_create(&thread2_id, NULL, &char_print, &thread2_args);
	/*Make sure the first thread has finished*/
	pthread_join(thread1_id, NULL);
	/*Make sure the second thread has finished*/
	pthread_join(thread2_id, NULL);	
	return 0;
}

/*Note: Make sure that any data you pass to a thread by reference is not deallocated, even by a different thread, until you are sure that the thread is done with it. This is true for local variables which are deallocated when they go out of scope, and for heap-allocated variables, which you deallocate by calling free.*/


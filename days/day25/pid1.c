#include <stdio.h>

main()
{
	printf("I am a process, my process id is %d\n",getpid());
	printf("My parents process id is %d\n",getppid());
	sleep(10);
}

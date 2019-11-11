#include <sys/types.h>
main()
{
	pid_t pid;
	printf("Enter the process id to send the signal\n");
	scanf("%d",&pid);
	kill(pid,9);
}

#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
void main()
{
	char *args[3];
	printf("I am going to exec an 'ls' program in current process\n");
	args[0]="kill";
	args[1]="-l";
	args[2]=0;
	execv("/bin/kill",args);
	printf("I have run an exec program\n");
}

#include<stdio.h>
#include<unistd.h>
void main()
{
	int ret;	
	printf("I am going to exec an 'ls' program\n");
	ret = execl("/bin/ls","ls","-il",0);
	printf("i executed ls program %d\n",ret);
}

#include<stdio.h>
#include<string.h>
main()

{	
	char str[100];
	printf("process id %d\n",getpid());
	printf("parent process id %d\n",getppid());
	scanf("%s",str);
	printf("%s\n",str);

}

#include<stdio.h>
int main()
{
	int i,a;
	printf("haiiiiiiiiiiiii\n");
	i=fork();
	if(i==0)
	{
		printf("i am a child\n");
	}
	else
		printf("i am parent\n");
		printf("process id:%d\n",getpid());
scanf("%d",&a);
}

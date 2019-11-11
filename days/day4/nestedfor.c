#include <stdio.h>

int main()
{
	int a=0,b=0,input;
	printf("enter a value:");
	scanf("%d",&input);
	for(a=1;a<=input;a++)
	{
		for(b=1;b<=input;b++)
		{
			printf("INSIDE NESTED FOR a:%d b:%d\n",a,b);
		}
		printf("\n");
	}
}

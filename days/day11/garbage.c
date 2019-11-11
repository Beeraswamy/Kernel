#include<stdio.h>
main()
{
	char *names[6];
	int i;	

	for(i=0;i<=5;i++)
	{
		printf("Enter name:");
		scanf("%s",names[i]);
	}
}

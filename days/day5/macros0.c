#include <stdio.h>

#define ARRAY_SIZE 5
int main()
{
	int a[ARRAY_SIZE];
	/* FILL THE ARRAY */
	for(i=0;i<ARRAY_SIZE;i++)
	{
		scanf("%d",&a[i]);
	}
	/*DISPLAY THE ARRAY*/
	for(i=0;i<ARRAY_SIZE;i++)
	{
		printf("%d\n",a[i]);
	}
}

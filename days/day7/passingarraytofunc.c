#include <stdio.h>
int display(int *,int);
main()
{
	int num[]={24,34,12,44,56,17};
	display(num,6);
}
//int display(int *j,int n)
int display(int j[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("element = %d\n",*j);
		j++;
		//incrementing pointer to point to next location
	}
}

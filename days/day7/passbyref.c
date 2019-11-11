#include <stdio.h>

main()
{
	int i;
	int marks[]={55,65,75,56,78,78,90};
	
	for(i=0;i<=6;i++)
		display(&marks[i]);
	printf("\n%d\n",marks[6]);
}

display(int *n)
{
	printf("%d\n",*n);
	if(*n == 90)
		*n=30;
}

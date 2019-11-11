#include <stdio.h>
//#define arrlist
void main()
{
	int arr[10] = {11, 2,9,13,57,25,17,1,90,3};

	#ifdef arrlist
	int c[10],b;
	for(b=0;b<=5;b++)
	{
	scanf("%d\n",&c[b]);
	}
	for(b=0;b<=5;b++)
	{
	
	printf(" elements of b %d",c[b]);
	}
	#endif
	int i,num;
	
	printf("Enter number to search\n");
	scanf("%d",&num);
	
	for(i=0;i<10;i++)
	{
		if(arr[i]==num)//if(c[b] == num)
			break;
	}
	if(i==10)
		printf("Number is not present in the array\n");
	else
		printf("The number is at a position %d in the array\n",i);
}

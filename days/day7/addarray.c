/*Adding two arrays*/
#include<stdio.h>
main()
{
	int a[5]={10,20,30,40,50};
	int b[5]={1,2,3,4,5};
	int c[5],i=5;
	
	printf("Original Elements\n");
	for(i=0;i<5;i++)
		printf("%d ",a[i]);
	printf("\n");	
	for(i=0;i<5;i++)
		printf("%d  ",b[i]);
	printf("\nSum of two arrays\n");
	for(i=0;i<5;i++)
		c[i]=a[i]+b[i];
	for(i=0;i<5;i++)
	printf("%d ",c[i]);	
}		

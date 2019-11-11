/*inserting an element*/

#include <stdio.h>


main()
{
	int a[20]={1,2,3,4,5};
	int i,j,k,n,pos, item;
	n=5;//no of elements	
	printf("Enter element to be inserted\n");
	scanf("%d",&item);
	printf("Enter the position of insertion\n");
	scanf("%d",&pos);
	for(i=n;i>=pos;i--)
		a[i]=a[i-1];
	
	a[pos-1]=item;
	for(i=0;i<n+1;i++)
		printf("a[%d]=%d\n",i,a[i]);
}

#include<stdio.h>
main()
{
	int x=10;
	int *ptr;
	ptr=&x;
	printf("%p\n",ptr);
	printf("%d\n",++*ptr); //pointer will be used in the expression and then incrememnts
	printf("%d\n",*ptr);
	printf("%d\n",++*ptr); //increments value at address	
	printf("%d\n",*++ptr); //increments and dereferences the value at new location
	printf("%p %d\n",ptr,*ptr); 
}

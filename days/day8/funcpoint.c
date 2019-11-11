#include <stdio.h>
int add(int,int);
main()
{
	int a=5,b=10,sum=0;
	int (*addPtr)(int, int);
	addPtr = add;
	sum = (*addPtr)(a,b);
	printf("sum %d\n",sum);
} 
add(int x, int y)
{
	int z;
	z=x+y;
	return z;
}

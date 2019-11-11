#include <stdio.h>

main()
{
	int a=10;
	int b=20;
	swapv(a,b);
	printf("a=%d\n",a);
	printf("b=%d\n",b);
}

swapv(int x,int y)
{
	int t;
	t = x;
	x = y;
	y = t;
	
	printf("x=%d\n",x);
	printf("y=%d\n",y);
}

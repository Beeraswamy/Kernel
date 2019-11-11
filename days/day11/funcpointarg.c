#include <stdio.h>

int addition(int a,int b)
{
	return (a+b);
}

int substraction(int a, int b)
{
	return (a-b);
}
int operation(int x, int y, int (*functocall)(int,int))
{
	int g;
	g = (*functocall)(x,y);
	return g;
}

int main()
{
	int m,n;
	int (*minus)(int, int) = substraction;
	int (*plus)(int, int) = addition;
	
	m=operation(10,20,plus);
	n=operation(40,30,minus);
	printf("%d %d\n",m,n);
	return 0;
}

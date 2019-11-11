#include <stdio.h>
 int c=30;

main()
{
	printf("main c: %d %p\n",c,&c);
	fun1();
	fun2();
}

 
int fun1()
{
	printf(" %d\n",c);
}

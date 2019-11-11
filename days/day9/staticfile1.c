#include <stdio.h>
int c=30;

main()
{
	printf("main c %d\n",c);
	fun1();
	fun2();
}

fun1()
{
	printf("fun1 c %d\n",c);
}

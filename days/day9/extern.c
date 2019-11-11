#include <stdio.h>
extern int c;
int main()
{
	//extern int c; /*using extern specifer fun1 able to access variable C is defined elsewhere*/
	printf("main c %d\n",c); /* c not avaialable to main function*/
	fun1();
	fun2();
}

fun1()
{
	//extern int c; /*using extern specifer fun1 able to access variable C is defined elsewhere*/
	printf("fun1 c %d\n",c); /*output of c-30*/
}

int c=30; /*External variable - By default available to func2*/

fun2()
{
	printf("fun2 c %d\n",c); /*output c=30*/
}
	

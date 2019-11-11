#include <stdio.h>

int my_int_func(int x)
{
	printf("%d\n",x);
}

int main()
{
	int (*func_ptr)(int);
	func_ptr=my_int_func;
	printf("0x%x 0x%x\n",my_int_func,&my_int_func);
	(*func_ptr)(2);
}


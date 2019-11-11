#include <stdio.h>
void fun();
int main()
{
	printf("1\n");
	goto ONE;
		fun();
	ONE:
		printf("2\n");
	return 0;
}

void fun()
{
	goto ONE;
		printf("3\n");
	ONE:
		printf("4\n");
}

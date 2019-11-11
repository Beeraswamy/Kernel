#include <stdio.h>

main()
{
	int i;
	for(i=0;i<10;i++)
		printf("val =%d\n",inc());
}
int inc()
{
	static int val=0;
	return ++val;
}

#include <stdio.h>

main()
{
	int x=1;
	ctest1(&x);
	printf("Valx = %d\n",x);
	ctest2(&x);
	printf("Valx = %d\n",x);
	return 0;
}


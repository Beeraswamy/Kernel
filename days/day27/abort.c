#include <stdio.h>
#include <stdlib.h>
main()
{
	//void abort(void);
	printf("Before pause\n");
	abort();
	printf("After pause\n");

}

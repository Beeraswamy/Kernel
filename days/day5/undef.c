#include <stdio.h>
#define MAX 100
#undef MAX
#define MAX 10
main()
{
	printf("In main\n");
}

#include <stdio.h>
#include <assert.h>
main()
{
	int x=0x1002;
	printf("1st Statement\n");
	assert(x > 0x1000);

	printf("2nd Statement\n");
	x=0x900;
	assert(x > 0x1000);
	printf("3rd Statement\n");
}

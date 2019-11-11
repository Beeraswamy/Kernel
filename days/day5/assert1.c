#include <stdio.h>
#include <assert.h>
#define NDEBUG 0
main()
{
	int x=0x900;
	printf("1st Statement\n");
#ifdef NDEBUG
	assert(x > 0x1000);
#endif
	
}

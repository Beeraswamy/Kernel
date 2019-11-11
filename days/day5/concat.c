#include <stdio.h>
#define TOKENCONCAT(x,y) x ## y 
main()
{
	int ab=10;	
	printf("%d\n",TOKENCONCAT(a,b));
}
	

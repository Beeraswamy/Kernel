#include <stdio.h>

#define MARKS 71

main()
{
#if (MARKS>=70)
	printf("Distinction\n");
#elif ((MARKS >= 60) && (MARKS < 70))
	printf("First Class\n");
#elif ((MARKS >= 50) && (MARKS < 60))
	printf("Second Class\n");
#else
	printf("Fail\n");
#endif
}
	

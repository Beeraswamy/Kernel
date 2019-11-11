#include <stdio.h>

main()
{
	int i;
	for (i = 0; i <= 20; i++) 
	{
		if (i%2 == 0) 
		{
			continue;
			//break;
		}
		printf ("%d ", i);
	}
	printf("Out of loop\n");
}

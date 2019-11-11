#include <stdio.h>
main()
{
	static int i=5;
	while(--i)
	{
		//printf("-");		
		main();
		printf("%d ",i);
	}
}

#include <stdio.h>

main()
{
	auto int a =2;
	
	{
		auto int a =5;
		printf("a = %d\n",a); /*Variable defined outside is invisible*/
	}
	printf("a - %d\n",a);
}

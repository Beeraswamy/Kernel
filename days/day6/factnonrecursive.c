#include <stdio.h>

main()
{
	int b,a,fact;
	printf("\nEnter any number:");
	b=scanf("%d",&a);
	printf("ret value%d\n",b);
	fact = factorial(a);
	printf("Factorial Value = %d %d\n",fact,a);
}

factorial(int x)
{
	int f=1,i;
	for(i=x;i>=1;i--)
	{
		f = f*i;
		printf("%d\n ",f);
	}
	return (f);
}


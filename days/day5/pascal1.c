#include <stdio.h>

factorial(int n)
{
	if(n<=1)
		return 1;
	else	
		return n* factorial(n-1);
}
main()
{
	int i,j,val;

	for(i=0;i<=5;i++)
	{
		j=0;
		while(j<=i)
		{
			val = factorial(i)/(factorial(j)*factorial(i-j));
			printf("%d ",val);
			j++;

		}
		printf("\n");
	}
}

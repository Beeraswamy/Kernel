#include <stdio.h>

int main()
{
	int x;
	printf("Enter a number:");
	scanf("%d",&x);
	if(x%2==0)
	{
		if(x>=0)
			printf("your number is even and positive\n");
		else
			printf("your number is even and negative\n");
	}
	else
	{
		if(x>=0)
			printf("your number is odd and positive\n");
		else
			printf("you number is odd and negative\n");
	}
	return 0;
}	

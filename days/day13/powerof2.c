#include <stdio.h>

main()
{ 
	int val;
	int i=1,k=0;
	printf("Enter the number:");
	scanf("%d",&val);	
	while(val != 0) 
	{
		k=k+(val&1);		
		val = val>>i;
	}
	if(k>1)
		printf("The value is not power of 2,%d",k);
	else
		printf("The value is power of 2:%d",k);	
}	

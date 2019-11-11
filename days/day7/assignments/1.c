//W.A.P to count the no of Even and Odd numbers

#include<stdio.h>
void main()
{
	int num[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	int i,even=0,odd=0;
	
	for(i=1;i<=20;i++)
	{
		//printf("\n Enter 20 element :");	
		//scanf("%d",&num[i]);
		if(num[i]%2==0)
			even++;
		else
			odd++;
	}
	printf("\n even values=%d",even);
	printf("\n odd values=%d",odd);
	getchar();
}

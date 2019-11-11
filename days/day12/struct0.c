
#include <stdio.h>

main()
{
	char name[3][20];
	float price[3];
	int pages[3],i;
	for(i=0;i<3;i++)
	{
		__fpurge(stdin);
		printf("\n Enter the book name, price, no of pages\n");
		scanf("%s %f %d",name[i],&price[i],&pages[i]);
	}	
	printf("\nBook name, Price, No of pages are\n");
	for(i=0;i<3;i++)
	printf("\n%s %.2f %d",name[i],price[i],pages[i]);
}

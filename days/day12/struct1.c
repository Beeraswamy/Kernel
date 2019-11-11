#include <stdio.h>
struct book
{
	char name[15];
	float price;
	int nop;
};
main()
{
	struct book b1,b2,b3,b4;
	printf("Please enter book name, price and number of pages of 3 books\n");
	scanf("%s %f %d",b1.name,&b1.price,&b1.nop);
	scanf("%s %f %d",b2.name,&b2.price,&b2.nop);
	scanf("%s %f %d",b3.name,&b3.price,&b3.nop);
	
        printf("Entered book name, price and number of pages of 3 books\n");
	printf("%s %f %d\n",b1.name,b1.price,b1.nop);	
	printf("%s %f %d\n",b2.name,b2.price,b2.nop);
	printf("%s %f %d\n",b3.name,b3.price,b3.nop);
}	
	


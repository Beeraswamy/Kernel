#include <stdio.h>

int main()
{
	int month;
	printf("enter the number\n");
	scanf("%d",&month);
	switch(month)
	{
		case 2:
			printf("Month has 28 or 29 days\n");
			break;
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			printf("Month has 31 days\n");
			break;
		case 4: case 6: case 9: case 11:
			printf("Month has 30 days\n");
			break;
		default:
			printf("Dont know that month.\n");
	}
}

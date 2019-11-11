#include <stdio.h>

union data
{
	int i;
	char c[4];
};

int main()
{
	int i;	
	union data info;
	info.i=0x12345678;
	for(i=0;i<4;i++)
	{
		printf("0x%x 0x%x\n",&info.c[i],info.c[i]);
	}
	printf("\n");
}

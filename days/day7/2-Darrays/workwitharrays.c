#include <stdio.h>

int main()
{
	int a[5]={1,2,3,4,5};	
	printf("1: 0x%x\n",a);
	printf("2: 0x%x\n",&a);
	printf("3: %d\n",*a);
	printf("4: %d\n",a[0]);
	printf("5: 0x%x\n",&a[0]);
	printf("6: 0x%x\n",a+1/*a+5*/);
	printf("6: 0x%x\n",&a+1);
	return 0;
}

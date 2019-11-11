#include <stdio.h>

main()
{
	int a[2][2]={{1,2},
		     {3,4}};
#if 0	
	printf("0x%x 0x%x\n",&a[0][0],&a[0][1]);			
	printf("0x%x 0x%x\n",&a[1][0],&a[1][1]);
	printf("\n");
	printf("0x%x 0x%x\n",&a[0],a[0]);
	printf("0x%x 0x%x\n",&a[1],a[1]);
	printf("\n");
	printf("0x%x\n",a);
#endif

	printf("a[0][0] %d at address 0x%x\n",a[0][0],&a[0][0]);	
	printf("a[0][1] %d at address 0x%x\n",a[0][1],&a[0][1] );
	printf("a[1][0] %d at address 0x%x\n",a[1][0],&a[1][0]);
	printf("a[1][1] %d at address 0x%x\n",a[1][1],&a[1][1]);

	printf("0x%x\n",a+1);
	printf("0x%x\n",*a);
	printf("0x%x\n",*a+1);
	printf("%d\n",*(*a+1));
	printf("0x%x\n",&a+1);
}

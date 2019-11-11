#include <stdio.h>

main()
{	
	int a[2][3]={{1,2,3},{4,5,6}};
	int i,j;	
	for(i=0;i<2;i++)
		for(j=0;j<3;j++)
			printf("a[%d][%d] - %d is stored at 0x%x\n",i,j,a[i][j],&a[i][j]);
}


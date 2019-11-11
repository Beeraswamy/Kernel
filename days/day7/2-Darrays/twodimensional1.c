#include <stdio.h>

main()
{
	int m[3][5]={11,12,13,15,16,
			21,22,23,24,25,
			31,32,33,34,35};
	int i,j;
	for(i=0;i<3;i++)
	{
		printf("\n");
		for(j=0;j<5;j++)
			printf("%d ",m[i][j]);
	}
}

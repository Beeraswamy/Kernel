#include <stdio.h>

main()
{
	int s[4][2]={{1,5},
		     {1,3},
		     {1,0},
		     {1,7}};
	int i,j;
	diplay2d(s);
#if 0	
	for(i=0;i<=3;i++)
	{
		for(j=0;j<2;j++)
			printf("%d ",*(*(s+i)+j));
		printf("\n");
	}
#endif
}	

diplay2d(int **a)
{
	int i,j;
	//for(i=0;i<4;i++)
	//{
		//for(j=0;j<2;j++)
			printf("%d ",*(*(a+i)+j));
		printf("\n");
	//}
}

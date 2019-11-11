#include <stdio.h>

main()
{
	int a[3]={1,2,3}; /*First Method*/
	int i;
	
	/*second method*/
	for(i=0;i<3;i++)
	{
		a[i]=i;
	}
	
	/*thirdmethod*/
	a[0]=1;
	a[1]=20;
	a[2]=300;

	return 0;
}
	

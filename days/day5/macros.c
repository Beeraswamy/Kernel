#include <stdio.h>
main()
	int a[5];
{
	
	/*fill the array*/
	for(i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<5;i++)
	{
		printf("%d\n",a[i]);\
	}
}

/*If we want to change the array size 5 to some other value we need to change the value at 3 places. 
The above disadvantage can be eliminated by using symbolic constants*/

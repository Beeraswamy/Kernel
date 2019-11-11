#include <stdio.h>

main()
{
	int x,i;
        for(i=1;i<100;i++)
	
           x= fibonacci(5);
	printf("fibonacci value%d\n ",x);
	
}
fibonacci(int n)
{
	int f;
	if(n==1) return 1;
	if(n==2) return 1;
	f= fibonacci(n-1)+fibonacci(n-2);
	printf("its comming from fun:%d%d\n",n,f);
	return f;
}

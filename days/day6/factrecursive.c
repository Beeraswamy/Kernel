#include <stdio.h>
int factorial(int);
int i=0;
main()
{
	int n;
	n=factorial(5);
        printf("%d\n",n);	
}

factorial(int a)
{
	int f;
	printf("factorial(%d)\n",a); 
	//if(a==0)
		//return 1;
	//else
		 f=a*factorial(a-1);
          printf("%d\n",a);
	//printf("factorial is :   %d\n",f);
	return f;
}

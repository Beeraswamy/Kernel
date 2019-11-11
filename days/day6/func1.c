#include <stdio.h>
int incre(int);
int main()
{
	int a = 0;
	a=  incre(a);
	printf("%d\n",a);
 	
}
 incre(int x) /* function definition*/
{     
	int i;
	for(i=0;i<5;i++)	
	 x=(x+5);
 	return x;
}


#include <stdio.h>
//int incre(int);
int main()
{
	int a = 25 ;
	printf("%d\n",a); 
	incre(&a);
	printf("%d\n",a);
	return 0;
}

int incre(int *val) /* function definition*/
{	
	*val =*val + 2;
}

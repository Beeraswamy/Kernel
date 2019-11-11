#include <stdio.h>
int incre(int);
int main()
{
	int a = 5;
	a = incre(a);
	printf("%d\n",a);
	return 0;
}

incre(int a) /* function definition*/
{	printf("%d\n",a);
	return (a+1);
//printf("%d\n",a);

}

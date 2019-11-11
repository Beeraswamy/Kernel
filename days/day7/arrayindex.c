#include <stdio.h>

int main()
{
	char a[]={1,2,3,4,5};
	int i=0;
	
	/*Displaying char by char*/
	for(;i<5;i++)
	{
		printf("%d\n",a[i]);
		printf("%d\n",*(a+i));
		printf("%d\n",i[a]);
		printf("%d\n",*(i+a));
	}
}

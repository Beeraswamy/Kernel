#include <stdio.h>
void main (void)
{
	int i = 0;
	char ch = 'A';
	do 
	{
		putchar (ch);
		printf("%d \n",i);
	}
	while((i++<5) || ++ch <= 'F');
}

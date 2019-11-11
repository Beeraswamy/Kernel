#include <stdio.h>

x=x^y => 0010 1000
	 0001 0100
	-----------
      x= 0011 1100

y=x^y => 0011 1100
	 0001 0100
	-----------
      y= 0010 1000(40) 
	
x=x^y => 0011 1100
	 0010 1000
	----------
      x= 0001 0100(20)

main()
{
	int x=40,y=20;	
	x = x^y;
	//printf("x = %d\n",x);
	y = x^y;
	//printf("y = %d\n",y);
	x = x^y;
	//printf("x = %d\n",x);
	printf("x = %d y = %d\n",x,y);
}

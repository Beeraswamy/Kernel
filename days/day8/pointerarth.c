#include <stdio.h>

main()
{
	int array[5]={1,2,3,4,5};
	//short array[5]={1,2,3,4,5};
	printf("0x%x 0x%x\n",&array[4],&array[1]);	
	printf("%d",&array[4]-&array[1]);
}

//By above statement we can calculate the offset between the two memory locations pointed to by two pointers.
//You cannot substract one pointer value from another if they do not share the same data type.
 

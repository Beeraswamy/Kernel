#include <stdio.h>

main()
{
	int s[4][2]={{1234,56},
		     {1212,83},
		     {1434,80},
		     {1312,78}};
	int i,j;
	for(i=0;i<4;i++)
		printf("Address of %d 1-D array 0x%x 0x%x 0x%x\n",i,s[i],(s+i),*(s+i));

	for(j=0;j<2;j++)
		printf("First Element of %d 1-D array %d\n",j,*(*s+j);


/*First element in all rows*/
	for(i=0;i<4;i++)
		printf("First Element of %d 1-D array is %d %d\n",i,*(s[i]+0),*(s[i]));

/*Second element in all rows*//*
	for(i=0;i<3;i++)
		printf("Second Element of %d 1-D array is %d\n",i,*(s[i]+1));
*/

}
			

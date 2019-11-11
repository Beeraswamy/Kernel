#include <stdio.h>

main()
{
	int i=10,j=0;
	//char *ch=&i;
	int *ptr;
	int **dptr;
	ptr=&i;
	dptr = &ptr;	
	printf("%d 0x%x\n",i,&i);
	printf("%d 0x%x 0x%x\n",*ptr,ptr,&ptr);
	printf("%d 0x%x 0x%x\n",**dptr,*dptr,dptr);
/*	
	while(j<4)
	{
		printf("0x%x %d\n",&ch[j],ch[j]);
		j++;	
	}
*/
}

#include <stdio.h>

main()
{
	int i=0x12345678;
	char *ch = &i;
	short *sh = &i;
	int *in = &i;
	int j=0;
	printf("&i 0x%x i 0x%x\n",&i,i);
	printf("ch 0x%x *ch 0x%x\n",ch,*ch);
	printf("sh 0x%x *sh 0x%x\n",sh,*sh);

	while(j<4)
	{
		printf("0x%x 0x%x\n",ch,*ch);
		ch++;
		j++;	
	}		

}	

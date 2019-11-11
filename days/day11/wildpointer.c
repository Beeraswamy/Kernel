#include <stdio.h>
main()
{
	char *c[10];
	c=malloc(10);
	scanf("%s",c);
	printf("%p\n",c);	
	printf("%s\n",c);	
	c="nimsme";
	
	printf("%p\n",c);
	c[0]='v';	
	printf("%s\n",c);
}

#include <stdio.h>

main()
{
	char a[]="string literal";
	char *p="string literal";
	//char *p=a;
	a[2]='v';
	p[2]='v';	
	//p[4]='q';
	
	printf("%s\n",a);
	printf("%s\n",p);
}

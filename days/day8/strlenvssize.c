#include <stdio.h>
#include<strings.h>
main()
{
	char a[10]="hello";
	char *p = "hello world";
	printf ("sizeof(a):%d\n", sizeof(a));
	printf ("str:len(a):%d\n", strlen(a));
	printf ("sizeof(p):%d\n", sizeof(p));
	printf ("strlen(p):%d\n", strlen(p));

	return 0;
}

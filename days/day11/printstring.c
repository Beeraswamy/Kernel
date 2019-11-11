#include <stdio.h>

main()
{
	char name[]="vinfinet";
	char *ptr;
	
	ptr=name;
	while(*ptr!='\0')
	{
		printf("%c",*ptr);
		ptr++;
	}
}

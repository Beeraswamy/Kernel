#include <stdio.h>

int main()
{
	char a[10]={'h','e','l','l','o','\0'};
	int i=0;

	/*displaying char by char*/
	for(;i<5;i++)
	{
		printf("%c\n",a[i]);
	}
	printf("%d %d",sizeof(a),strlen(a));
	/* Displaying complete string*/
	printf("%s\n",a);
	return 0;
}

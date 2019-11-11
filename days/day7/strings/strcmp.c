#include <stdio.h>

main()
{
	char string1[]="Jerry";
	char string2[]="Ferry";
	int i,j,k;
	
	i=strcmp(string1,"Jerry");
	j=strcmp(string1,string2);
	k=strcmp(string1,"Jerry Boy");
	printf("%d %d %d\n",i,j,k);
	
	i=strcasecmp(string1,"Jerry");
	j=strcasecmp(string1,string2);	
	//j=strcasecmp(string2,string1); //F-70 J-74
	k=strcasecmp(string1,"Jerry Boy");
	printf("%d %d %d\n",i,j,k);
}

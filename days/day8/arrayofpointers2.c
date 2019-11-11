#include <stdio.h>

main()
{
	char *suit[4]={"Hearts","Diamonds","Clubs","Spades"};
	int i;	
	stringsPrint(suit,4);
	printf("PRINTING STRINGS ONE AT A TIME\n");	
	for(i=0;i<4;i++)	
		stringPrint(suit[i]);
}

stringsPrint(char **str1,int size)
{
	int i;
	/*Print all strings*/
	for(i=0;i<size;i++)
		printf("%s\n",str1[i]);
}

stringPrint(char *str2)
{
	/*Prints one string at a time*/
	printf("%s\n",str2);
}

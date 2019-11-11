#include <stdio.h>
/*
struct asciiPair
{
	char b;	
	int a;
	//short c;
};
*/

typedef struct
{
	int a;
	char b;
}asciiPair;

int main()
{
	asciiPair sVar={65,'A'};
	asciiPair *psVar = &sVar;
	asciiPair sVar1=sVar;
	//char *ch=&sVar;
	int i=0;
	//scanf("%d %c",&psVar.a,&psVar.b);
	printf("ASCII Value of '%c' is %d\n",sVar1.b,sVar1.a);
	
	//scanf("%d %c",&psVar->a,&psVar->b);
	//printf("ASCII Value of '%c' is %d\n",psVar->b,psVar->a);
	//printf("%d\n",sizeof(sVar));
	
	//printf("0x%x 0x%x 0x%x\n",&sVar.a,&sVar.b,&sVar.c);

}
 
	

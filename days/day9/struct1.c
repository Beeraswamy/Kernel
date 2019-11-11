#include <stdio.h>

struct asciiPair
{
	char b;	
	int a;	
	
	char b1;	
	short c;
};


typedef struct
{
	int a;
	char b;
}asciiPair;

int main()
{
	struct asciiPair sVar={65,'A'};
	struct asciiPair *psVar = &sVar;
	char *ch=&sVar;
	int i=0;
	//scanf("%d %c",&psVar.a,&psVar.b);
	printf("ASCII Value of '%c' is %d\n",sVar.b,sVar.a);
	
	scanf("%d %c",&psVar->a,&psVar->b);
	printf("ASCII Value of '%c' is %d\n",psVar->b,psVar->a);
	printf("%d\n",sizeof(sVar));
	
	printf("0x%x 0x%x 0x%x 0x%x\n",&sVar.a,&sVar.b,&sVar.b1,&sVar.c);

}
 
	

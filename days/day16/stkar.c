#include <stdio.h>
#define MAX_STACK_SIZE 10
#define SUCCESS 0
#define STK_FULL_ERR 2
#define STK_EMPTY_ERR 3
int stktop;

int stkArray[MAX_STACK_SIZE];

int pushItem(int num)
{
	if(stktop == MAX_STACK_SIZE)
	{
		printf("STK_FULL_ERR \n");		
		return STK_FULL_ERR;
	} 
	stkArray[stktop++]=num;
	return SUCCESS;
}

int popItem()
{
	int num;	
	if(stktop == 0)
	{
		printf("STK_EMPTY_ERR\n");
		return STK_EMPTY_ERR;
	}
	num = stkArray[--stktop];
	printf("Pop item %d\n",num);
	return SUCCESS;
}

void display()
{
	int i=0;
	printf("Displaying items in stack\n");	
	for(i=0;i<stktop;i++)
		printf("%d \n",stkArray[i]);
}

main()
{
	pushItem(5);
	pushItem(6);
	pushItem(7);
	display();
	popItem();
	popItem();
	popItem();
	display();
}

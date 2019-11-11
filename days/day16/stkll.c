/*Stack implementation using linked list*/
#include <stdio.h>

#define SUCCESS 1
#define STK_FULL_ERR 2
#define STK_EMPTY_ERR 3

struct node
{
	int data;
	struct node *pnxt;
};

struct node *pStkHd;

int pushItem(int num)
{
	struct node *pn;
	pn = malloc(sizeof(struct node));
	if(pn == NULL)
	{
		return STK_FULL_ERR;
	}
	pn->data = num;
	
	/*Add to the head of the linked list*/
	pn->pnxt = pStkHd;
	pStkHd = pn;
	return SUCCESS;
}

int popItem()
{
	struct node *pn;	
	if(pStkHd == NULL)
	{
		printf("Stack Empty\n");
		return STK_EMPTY_ERR;
	}
	pn = pStkHd;
	pStkHd = pStkHd->pnxt;
	printf("Pop item %d\n",pn->data);
	free(pn);
}

int display()
{
	struct node *pTemp;
	pTemp = pStkHd;	
	printf("Items in the Stack\n");	
	while(pTemp)
	{
		printf("%d\n",pTemp->data);
		pTemp= pTemp->pnxt;
	}		
}
main()
{
	pushItem(5);
	pushItem(6);
	pushItem(7);
	display();
	popItem();
	display();
	//popItem();
	//popItem();
	//popItem();
	display();
}		

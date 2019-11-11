/* Queue Implementation*/
#include <stdio.h>
#define SUCCESS 1
#define QUEUE_EMPTY_ERR 2

struct node
{
	int data;
	struct node *pnxt;
};

struct node *pQueHd;
struct node *pQueTl;
/*Add to Tail*/
int enqItem(int data)
{
	struct node *pn;
	pn = malloc(sizeof(struct node));
	pn->data = data;
	if(pQueTl == NULL)
		pQueTl = pQueHd = pn;
	else
	{
		pQueTl->pnxt = pn;
		pQueTl = pn;
	}
	pn->pnxt = NULL;
}

int deqItem()
{
	struct node *pn;
	if(pQueHd == NULL)
	{	
		printf("Queue Empty\n");		
		return QUEUE_EMPTY_ERR;
	}
	pn = pQueHd;
	pQueHd = pQueHd->pnxt;
	if(pQueHd == NULL)
		pQueTl=NULL;
	printf("Enqueuing data %d\n",pn->data);
	free(pn);
	return SUCCESS;
}

int display()
{
	struct node *pTemp;
	pTemp = pQueHd;	
	printf("Items in the Queue\n");	
	while(pTemp)
	{
		printf("%d\n",pTemp->data);
		pTemp= pTemp->pnxt;
	}		
}

main()
{
	enqItem(5);
	enqItem(6);
	enqItem(7);
	display();
	deqItem();
	deqItem();
	deqItem();	
	display();
}



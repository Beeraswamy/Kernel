/* Queue Implementation*/
#include <stdio.h>
#define SUCCESS 0
#define QUEUE_EMPTY_ERR 2
#define QUEUE_FULL_ERR 3
#define MAX_Q_SIZE 10

int queueArray[MAX_Q_SIZE];
int noOfItems;
int enqItem(int num)
{
	if(noOfItems == MAX_Q_SIZE)
	{
		printf("Queue Full\n");
		return QUEUE_FULL_ERR;
	}
	queueArray[noOfItems++]=num;
	return SUCCESS;
}

int deqItem()
{
	int i;
	int num;
	if(noOfItems == 0)
	{
		printf("Queue Empty\n");
		return QUEUE_EMPTY_ERR;
	}
	num = queueArray[0];
	printf("Dequeued item %d\n",num);
	for(i=1;i<noOfItems;i++)
		queueArray[i-1]=queueArray[i];
	noOfItems--;
	return SUCCESS;
}

display()
{
	int i;
	printf("Listing the items in queue\n");
	for(i=0;i<noOfItems;i++)
		printf("%d\n",queueArray[i]);
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

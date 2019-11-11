#include<stdio.h>
struct node
{
int x;
struct node *next;
};

struct node *phead;
struct node *phead1;
struct node *ptraverse;
//struct node *next;

main()
{
	int x;
	char c;
//struct node *phead1;
	int val;
	while(1)
	{
		printf("enter y or n to create a node:\n");
		__fpurge(stdin);
		scanf("%c",&c);
		if (c=='n')
		{
			printf("display\n",x);
                         phead->x;
			exit(0);
	 	}
		if (c=='y')
		{
     			if(phead==NULL)
			{
				phead= malloc(sizeof(struct node));
				printf("enter any value\n");
				scanf("%d",&val);
				phead->x=val;
				phead->next=NULL;
			}
			else
			{
				phead1=malloc(sizeof (struct node));
				printf("Enter any value\n");
				scanf("%d",&val);
				phead1->x=val;
				phead1->next=NULL;
				ptraverse=phead;
				while(ptraverse->next) 
				{
					ptraverse=ptraverse->next;
				}
				ptraverse->next=phead1;
			}
		}		
	}
}

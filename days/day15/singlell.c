
#include<stdio.h>
#include<stdlib.h>
void createnode();
void addNodeToHead();
void deletenodeattail();
void deletenodeathead();
void deletenode();
void insertnode();
void display();
struct node
{
	int x;
	struct node *next;
};
struct node *phead;
int main()
{
int y;
	while(1)
	{
		printf("\nenter your choice \n 1.Add a node at tail\n 2.Add a node at head\n 3.delete a node from tail\n 4.delete a node from head\n 5.delete a node at any position\n 6.insert a node in ascending order\n 7.display\n 8.exit\n");
		scanf("%d",&y);
		switch(y)
		{
			case 1:
				createnode(); 	//Adding node to tail
				break;
			case 2:
				addNodeToHead();	//Adding node to head
				break;
			case 3:
				deletenodeattail();
				break;
			case 4:
				deletenodeathead();
				break;
			case 5:
				deletenode();
				break;
			case 6:
				insertnode();
				break;
			case 7:
				display();
				break;
			case 8:
				exit(0);
				break;
			default:
				printf("invalid choice");
				break;
		}
	}
}
void createnode()
{
	struct node *ptemp;
	struct node *ptrav;
	ptemp=(struct node *)malloc(sizeof(struct node));
	printf("enter the data");
	scanf("%d",&ptemp->x);
	ptemp->next=NULL;
	if(phead==NULL) //THIS CONDITION IS FOR LIST IS EMPTY
	{
		phead=ptemp;
	}
	else
	{
		ptrav=phead;
		while(ptrav->next!=NULL)
		{
			ptrav=ptrav->next;
		}
		ptrav->next=ptemp;
	}
}
void addNodeToHead()
{
	struct node *ptemp;
	ptemp=(struct node *)malloc(sizeof(struct node));
	printf("enter the data");
	scanf("%d",&ptemp->x);
	ptemp->next=NULL;
	if(phead==NULL)
	{
		phead=ptemp;
	}
	else
	{
		ptemp->next=phead;
		phead=ptemp;
	}
}
void display()
{
	struct node *ptrav;
	ptrav=phead;
	if(phead==NULL)
	{
		printf("list is empty");
	}
	else
	{
		while (ptrav!=NULL)
		{
			printf(" %d \t",ptrav->x);
			ptrav=ptrav->next;
		}
	}
}
void deletenodeathead()
{
	struct node *ptemp;
	if(phead== NULL)
	{
		printf("emptydisplay list");
	}	
	else 
	{
		ptemp=phead;
		phead=phead->next;
		free(ptemp);
	}
}
void deletenodeattail()
{
	struct node *prevtrav,*ptrav;
	if(phead== NULL)
	{
		printf("empty list");
	}
	else
	{
		if(phead->next== NULL)
		{
			free(phead);
			phead=NULL;
		}
		else
		{
			ptrav=phead;
			while(ptrav->next!= NULL)
			{
				prevtrav=ptrav;
				ptrav=ptrav->next;
			}	
			free(ptrav);
			prevtrav->next= NULL;
		}
	}
}
void deletenode() 
{
	struct node *ptemp,*ptrav,*prevtrav;
	int val;
	printf("enter the value to be deleted");
	scanf("%d",&val);
	if(phead==NULL)
	{
		printf("empty list");
	}
	else
	{
		if(phead->x==val)
		{
			ptemp=phead;
			phead=phead->next;
			free(ptemp);
		}
		else
		{
			ptrav=phead;
			while(ptrav->x!=val)
			{
				prevtrav=ptrav;
				ptrav=ptrav->next;
			}
			prevtrav->next=ptrav->next;
			free(ptrav);
		}
	}
}
void insertnode()
{
	int y;
	struct node *newnode,*ptrav,*prev;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("enter the data");
	scanf("%d",&y);
	newnode->x=y;
	newnode->next=NULL;
	if(phead==NULL)			//this condition is for if the list is empty
	{
		phead=newnode;
	}
	else
	{
		if(phead->x>y)		//this condition is for if the phead data is greater than newnode
		{
			newnode->next=phead;
			phead=newnode;
		}
		else			
		{
			//prev=phead;
			ptrav=phead;
			while((ptrav->x)<y)
			{
				prev=ptrav;				
				ptrav=ptrav->next;
				if(ptrav==NULL)
				break;
			}
			if(ptrav== NULL)		//this is for if the newnode data is greater than last node
			{
				if(y>ptrav->x)
				{
				ptrav->next=newnode;
				}
				else
				{
					prev->next=newnode;
					newnode->next=ptrav;
				}
			}			
			else
			{
				//newnode->next=ptrav->next;
				prev->next=newnode;
				newnode->next=ptrav;
			}
		}
	}
	
}


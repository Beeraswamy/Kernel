#include<stdio.h>
//define NULds1.c:26:1: error: conflicting types for ‘ptrav’
ds1.c:ds1.c:26:1: error: conflicting types for ‘ptrav’
ds1.c:7:25: note: previous declaration of ‘ptrav’ was here
ds1.c:26:7: warning: initialization makes integer from pointer without a cast [enabled by default]
ds1.c:26:1: error: initializer element is not constant
ds1.c:27:1: error: expected identifier or ‘(’ before ‘while’
ds1.c:31:1: error: expected identifier or ‘(’ before ‘{’ token
viven@viven-PC:~/Desktop/chinna$ vi ds1.c
viven@viven-PC:~/Desktop/chinna$ gcc ds1.c
ds1.c:2:1: error: unknown type name ‘create’
ds1.c: In function ‘main’:
ds1.c:11:1: error: unknown type name ‘create’
ds1.c:11:13: error: expected declaration specifiers or ‘...’ before numeric constant
ds1.c:12:1: error: unknown type name ‘create’
ds1.c:12:13: error: expected declaration specifiers or ‘...’ before numeric constant
ds1.c:13:1: error: unknown type name ‘create’
ds1.c:13:13: error: expected declaration specifiers or ‘...’ before numeric constant
ds1.c: At top level:
ds1.c:15:1: error: unknown type name ‘create’
ds1.c: In function ‘node’:
ds1.c:18:6: warning: incompatible implicit declaration of built-in function ‘malloc’ [enabled by default]
ds1.c: At top level:
ds1.c:22:1: error: expected identifier or ‘(’ before ‘if’
ds1.c:27:1: warning: data definition has no type or storage class [enabled by default]
ds1.c:27:1: error: conflicting types for ‘ptrav’
ds1.c:8:25: note: previous declaration of ‘ptrav’ was here
ds1.c:27:7: warning: initialization makes integer from pointer without a cast [enabled by default]
ds1.c:27:1: error: initializer element is not constant
ds1.c:28:1: error: expected identifier or ‘(’ before ‘while’
ds1.c:32:1: error: expected identifier or ‘(’ before ‘{’ token
viven@viven-PC:~/Desktop/chinna$ vi ds1.c
viven@viven-PC:~/Desktop/chinna$ gcc ds1.c
ds1.c:2:1: error: unknown type name ‘create’
ds1.c: In function ‘main’:
ds1.c:11:1: error: unknown type name ‘create’
ds1.c:11:13: error: expected declaration specifiers or ‘...’ before numeric constant
ds1.c:12:1: error: unknown type name ‘create’
7:25: note: previous declaration of ‘ptrav’ was here
ds1.c:26:7: warning: initialization makes integer from pointer without a cast [enabled by default]
ds1.c:26:1: error: initializer element is not constant
ds1.c:27:1: error: expected identifier or ‘(’ before ‘while’
ds1.c:31:1: error: expected identifier or ‘(’ before ‘{’ token
viven@viven-PC:~/Desktop/chinna$ vi ds1.c
viven@viven-PC:~/Desktop/chinna$ gcc ds1.c
ds1.c:2:1: error: unknown type name ‘create’
ds1.c: In function ‘main’:
ds1.c:11:1: error: unknown type name ‘create’
ds1.c:11:13: error: expected declaration specifiers or ‘...’ before numeric constant
ds1.c:12:1: error: unknown type name ‘create’
ds1.c:12:13: error: expected declaration specifiers or ‘...’ before numeric constant
ds1.c:13:1: error: unknown type name ‘create’
ds1.c:13:13: error: expected declaration specifiers or ‘...’ before numeric constant
ds1.c: At top level:
ds1.c:15:1: error: unknown type name ‘create’
ds1.c: In function ‘node’:
ds1.c:18:6: warning: incompatible implicit declaration of built-in function ‘malloc’ [enabled by default]
ds1.c: At top level:
ds1.c:22:1: error: expected identifier or ‘(’ before ‘if’
ds1.c:27:1: warning: data definition has no type or storage class [enabled by default]
ds1.c:27:1: error: conflicting types for ‘ptrav’
ds1.c:8:25: note: previous declaration of ‘ptrav’ was here
ds1.c:27:7: warning: initialization makes integer from pointer without a cast [enabled by default]
ds1.c:27:1: error: initializer element is not constant
ds1.c:28:1: error: expected identifier or ‘(’ before ‘while’
ds1.c:32:1: error: expected identifier or ‘(’ before ‘{’ token
viven@viven-PC:~/Desktop/chinna$ vi ds1.c
viven@viven-PC:~/Desktop/chinna$ gcc ds1.c
ds1.c:2:1: error: unknown type name ‘create’
ds1.c: In function ‘main’:
ds1.c:11:1: error: unknown type name ‘create’
ds1.c:11:13: error: expected declaration specifiers or ‘...’ before numeric constant
ds1.c:12:1: error: unknown type name ‘create’
L 0
#define SUCCESS 1
#define UNSUCCESS 0


typedef struct singleLink_s
{
	int data;
	struct singleLink_s *next;
}single_t;

void createSingleLink(single_t *);
single_t * searchNode(single_t *);

void displaySingleLink();
//Global struture pointer
single_t *pHead=NULL;
//single_t *pTemp;
//m e n u

void menu()
{
	printf("\n1.Create\n2.Display\n3.Add To Head\n4.Add To End\n5.Insert a Node\n6.Delete a Node\n7.Search A Node\n8.Exit");
}

// m a i n

main()
{
		pHead=(single_t *)malloc(sizeof(single_t));
  	//pHead=NULL;
	single_t *pNodeHead;
	single_t *pNodeTail;
	single_t *pTemp; 
	single_t *pNode;
 
	single_t *pSearch;
 
	int ch;
	int dataDel;
  
	single_t *dN;     //Holds Deleted Node 
  
	single_t *sN;     //Holds Searche Node
	menu();
  
	printf("\nEnter ur choice\n");
	scanf("%d",&ch);
  
  
	while(ch<8)
	{
		switch(ch)
		{
			case 1:

		   	{
    				pTemp=pHead;
    				createSingleLink(pTemp);
    				break;
   			}
   			case 2:
  				//  printf("Displaying...\n");
    		 		displaySingleLink();
   	 			break;
   			case 3:
   			{
				pNodeHead=(single_t *)malloc(sizeof(single_t));
    				printf("Enter data to be added\n");
    				scanf("%d",&pNodeHead->data);
    				pNodeHead->next=NULL;
    				//printf("Adding to head\n");
    				if(addToHead(pNodeHead))
     					printf("\nGiven node is successfully added\n");
    				else
     					printf("\nAdding a node is failed\n");
    				break;
   			}
   			case 4:
   			{
    				pNodeTail=(single_t *)malloc(sizeof(single_t));
    				printf("Enter data\n");
    				scanf("%d",&pNodeTail->data);
    				pNodeTail->next=NULL;
    				if(addToTail(pNodeTail))
     					printf("\nGiven node is successfully added\n");
    				else
     					printf("\nAdding a node is failed\n");
    				break;
   			}
   			case 5:
   			{
    				pNode=(single_t*)malloc(sizeof(single_t));
    				printf("Enter data to be inserted\n");
    				scanf("%d",&pNode->data);
    				pNode->next=NULL;
    				if(insertNode(pNode))
     					printf("Insertion is completed successfully\n");
   				else 
     					printf("Insertion is failed\n");
    				break;
   			}
   			case 6:
   			{
    				printf("Enter data to be deleted\n");
    				scanf("%d",&dataDel);
    				if(delNode(dataDel,&dN))
				{
					printf("Deletion is completed successfully\n");
					printf("And the deleted node is: %u\n",*dN);
					free(dN);
				}
    				else
     					printf("Deletion is failed\n");
				
    				break;
   			}
   			case 7:
   			{
    				pSearch=(single_t *)malloc(sizeof(single_t));
				printf("Enter data to be searched\n");
				scanf("%d",&pSearch->data);
				pSearch->next=NULL;
				if(sN=searchNode(pSearch))
					printf("Node %d is found in the list at address %u\n",pSearch->data,sN);
				else
					printf("Node %d is not found int list\n",pSearch->data); 
     
   			}
  		}
  		menu();
  		printf("\n\nEnter ur choice\n");
  		scanf("%d",&ch);
 	}
}
 

void createSingleLink(single_t *pTemp)
{
	char c;
  
	printf("Enter data\n");
	scanf("%d",&pTemp->data);
	pTemp->next=NULL;
	//  printf("Do u want to create another node (Enter  ZERO - No, Other than ZERO - Yes ) \n");
	printf("Do u want to create another node(y/n)\n");
	__fpurge(stdin);
	scanf("%c",&c);
	if(c=='Y' || c=='y')
	{
		pTemp->next=(single_t *)malloc(sizeof(single_t));
		createSingleLink(pTemp->next);
	}
	// return;
}

void displaySingleLink()
{
	int count=0;
	single_t *pTemp=pHead;
	if(pTemp == NULL)
		printf("No linked list is created\n");
	printf("Displaying..\n");
	do
	{
		//printf("%d @ %u\t",pTemp->data,pTemp);
		printf("%d @ 0x%x\n",pTemp->data,pTemp);   
		pTemp=pTemp->next;
		count++;
		printf("no of node =%d\n",count);
	}while(pTemp);
	return count;
	//printf("count=%d\n",count);
	printf("\n");
}
  
int addToHead(single_t *pNode)
{
	//printf("1=%d\n",pHead->data);
	if(pHead==NULL)
	{
		pHead=pNode;
		pNode->next=NULL;
		return SUCCESS;
	}
	//printf("2=%d\n",pHead->data);
	pNode->next=pHead;
	pHead=pNode;
	return SUCCESS;
}

int addToTail(single_t *pNodeTail)
{
	single_t *pTemp=pHead;
  
	if(pTemp==NULL)
	{
		pTemp=pNodeTail;
		return SUCCESS;
	}
	while(pTemp->next)
	pTemp=pTemp->next;

	pTemp->next=pNodeTail;
	return SUCCESS;
}

int insertNode(single_t *pNode)
{
	single_t *pTemp;
  
	pTemp=pHead;
  
	if(pHead == NULL)
	{
		printf("No linked list is created to insert\n");
		return UNSUCCESS;
	}
  
	if(pHead->data > pNode->data)
	{
		pNode->next=pHead;
		pHead=pNode;
		return SUCCESS;
	}
 
	while(pTemp)
	{
		if(pTemp->next->data > pNode->data)
		{
			pNode->next=pTemp->next;
			pTemp->next=pNode;
			return SUCCESS;
		}
		pTemp=pTemp->next;
	}
  
	pTemp=pNode;
	//pNode->next=NULL;
  
	/* pTemp=pHead;
	while(pTemp)
  	{
   		if(pTemp->data == pNode->data)
   		{
    			printf("Data already exists\n");
    			return UNSUCCESS;
   		}
   		pTemp=pTemp->next;
  	}*/
	return SUCCESS;
}


int delNode(int data, single_t **dN)
{
	single_t *pTemp;
	pTemp=pHead;
	if(pTemp==NULL)
	{
		printf("No linked list is created\n");
		return UNSUCCESS;
	}
	if(pHead->data == data)
	{
		*dN=pHead;
		pHead=pHead->next;
		return SUCCESS;
	}
	while(pTemp)
	{
		if(pTemp->next->data == data)
		{
			*dN=pTemp->next;
	    		pTemp->next=pTemp->next->next;
	    		return SUCCESS;
	   	}
	   	pTemp=pTemp->next;
	}
	printf("Data is not found\n");
	return UNSUCCESS;
}


single_t * searchNode(single_t *pS)
{
	single_t *sN=pHead;
	if(pHead==NULL)
	{
		printf("No list is created, so no searching mechanism allowed\n");
		return NULL;
	}
	if(sN->data == pS->data)
		return sN;
	while(sN)
	{
		if(sN->next->data == pS->data)
		return sN->next;
		sN=sN->next;
	}
}   

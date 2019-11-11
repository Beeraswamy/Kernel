#include <stdio.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *root;

/*Inserting an element*/
void ins(struct node *n,int val, int opt)
{
	struct node *t;
	t = (struct node *)malloc(sizeof(struct node));
	t->data = val;
	t->left = t->right = NULL;
	if(opt == 1)
		n->left = t;
	else
		n->right = t;
	printf("%d is inserted ",val);
	
	if(opt == 1)
		printf("At the left\n");
	else
		printf("At the right\n");
} 

void inser(struct node *t, int x)
{
	if(t->data > x)
	{
		if(t->left == NULL)
			ins(t,x,1);
		else
			inser(t->left,x);
	}	
	else if(t->data < x)
	{
		if(t->right == NULL)
			ins(t,x,2);
		else
			inser(t->right,x);
	}	
	else
		printf("Element is already found in the list\n");
}

	 	
/*Traversing the tree in-order*/
void inorder(struct node *p)
{
	if(p!= NULL)
	{
		inorder(p->left);
		printf("%5d",p->data);
		inorder(p->right);
	}
}

/*Traversing the tree in Pre-order*/
void preorder(struct node *p)
{
	if(p!=NULL)
	{
		printf("%5d",p->data);	
		preorder(p->left);	
		preorder(p->right);
	}
}

/*Traversing the tree in post-order*/
void postorder(struct node *p)
{
	if(p!= NULL)
	{
		postorder(p->left);
		postorder(p->right);
		printf("%5d",p->data);
	}
}
				
	

main()
{
	int op,n;
	root = (struct node *)malloc(sizeof(struct node));
	root->data = 30;
	root->left = root->right = NULL;
	
	do
	{
		printf("Insertion[1]\n");
		printf("Preorder[2]\n");
		printf("Inorder[3]\n");
		printf("Postorder[4]\n");
		printf("Exit[5]\n");
		printf("Enter your choice > ");
		
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				printf("Enter the element to insert \n");
				scanf("%d",&n);
				inser(root,n);
				break;
			case 2: 
				printf("The pre-order elements are\n");	
				preorder(root);
				printf("\n");
				break;
			case 3: 
				printf("The inorder elements are\n");	
				inorder(root);
				printf("\n");
				break;
			case 4: 
				printf("The postorder elements are\n");
				postorder(root);
				printf("\n");
				break;
			default:
				printf("You have entered a wrong choice\n");
				exit(0);
			
		}
	}while(op<5);
}	



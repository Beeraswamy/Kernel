//Basic double linked list fragment

#include <stdio.h>
#include <stdlib.h>

struct dllist {
 int number;
 struct dllist *next;
 struct dllist *prev;
};

struct dllist *head, *tail;

void append_node(struct dllist *lnode);
void insert_node(struct dllist *lnode, struct dllist *after);
void remove_node(struct dllist *lnode);

int main(void)
{
	struct dllist *lnode;
	int i = 0;


	/* add some numbers to the double linked list */
	for(i = 0; i <= 5; i++)
	{
		lnode = (struct dllist *)malloc(sizeof(struct dllist));
		lnode->number = i;
		append_node(lnode);
	}

	/* print the dll list */
	for(lnode = head; lnode != NULL; lnode = lnode->next)
	{
		printf("%d\n", lnode->number);
	}

	/* destroy the dll list */
	while(head != NULL)
		remove_node(head);

	return 0;
}


void append_node(struct dllist *lnode)
{
	if(head == NULL)
	{
		head = lnode;
		lnode->prev = NULL;
	}
	else
	{
  		tail->next = lnode;
  		lnode->prev = tail;
 	}

 	tail = lnode;
 	lnode->next = NULL;
}

void insert_node()
{
	struct dlist *current_pointer, *previous_pointer, *temp;
	previous_pointer = NULL;
	current_pointer = head;
	
	temp = malloc(sizeof(struct dlist *));
	printf("Enter the element to be inserted:\n");
	scanf("%d",&temp->number);	
	while(current_pointer->number < temp->number)
	{
		previous_pointer = current_pointer;
		current_pointer = current_pointer->next;	
	}
	previous_pointer->next = temp;
	temp->prev = previous_pointer;
	current_pointer->prev = temp;
	temp->next = current_pointer;
}

void remove_node(struct dllist *lnode)
{
	if(lnode->prev == NULL)
		head = lnode->next;
	else
		lnode->prev->next = lnode->next;

	if(lnode->next == NULL)
		tail = lnode->prev;
	else
		lnode->next->prev = lnode->prev;
}

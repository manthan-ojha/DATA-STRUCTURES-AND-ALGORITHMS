#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};
void create( struct node **,int);
void traverse(struct node *);
void insert_first( struct node **,int);
void insert_end( struct node *,int);
void delete_first(struct node **);
void delete_end(struct node **);

int main()
{
	int ch,num,item;
	struct node *head = NULL;
	while(1)
	{
		printf("\n1.Create\n2.Traverse\n3.Insert At First\n4.Insert At End\n5.Delete At First\n6.Delete At End\n0.Exit\nEnter Your Choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0:exit(0);
			case 1: printf("enter the number of nodes\n");
				scanf("%d",&num);
				printf("Linked List Being Created\n");
				create(&head,num);
				break;
			case 2: traverse(head);
				break;
			case 3: printf("enter the new node\n");
				scanf("%d",&item);
				insert_first(&head,item);
				break;
			case 4: printf("enter the new node\n");
				scanf("%d",&item);
				insert_end(head,item);
				break;
			case 5: delete_first(&head);
				break;
			case 6: delete_end(&head);
				break;
			default:printf("INVALID INPUT.....!!!!\n");
		}
	}
	return (0);
}
void create( struct node **head,int num)
{	
	int i,item;
	struct node *newnode , *temp;
	if (*head != NULL)
	{
		printf("Already Created....!!!");
		return;
	}
	for(i=1;i<=num;i++)
	{
		printf("enter the information");
		scanf("%d",&item);
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->info=item;
		if( *head==NULL)
			*head=newnode;
		else
			temp->next=newnode;
		temp=newnode;
	}
	newnode->next=*head;
	return;
}			
void traverse( struct node *head)
{	
	struct node *loc;
	if (head==NULL)
	{
		printf("empty list");
		printf("\nhead = %u\n",head);
		return;
	}
	loc=head;
	printf("head = %u\n",head);
	do
	{
		printf(" %d [%u]\n ",loc->info,loc->next);
		loc=loc->next;
	}while (loc !=head);
	return;
}
void insert_first( struct node **head , int item)
{
	struct node *loc , *newnode;
	loc=*head;
	while((loc->next) != *head)
		loc=loc->next;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->info=item;
	newnode->next=*head;
	loc->next=newnode;
	*head=newnode;
	return;
}
void insert_end(struct node *head , int item)
{
	struct node *loc , *newnode;
	loc=head;
	while((loc->next) != head)
		loc=loc->next;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->info=item;
	newnode->next=head;
	loc->next=newnode;
	return;
}
void delete_first(struct node **head)
{
	struct node *loc , *temp;
	if(*head == NULL)
	{
		printf("\nError in operation!!!");
		return;
	}
	printf("\t %d deleted ",(*head)->info);
	loc = *head;
	while(loc->next != *head)
		loc=loc->next;
	temp=*head;
	if (loc==*head)
		*head==NULL;
	else
	{
		*head=temp->next;
		loc->next=*head;
	}
	temp->next=NULL;
	free(temp);
	return;
}
void delete_end( struct node **head)
{
	struct node *loc,*locp;
	if(*head == NULL)
	{
		printf("\nError in operation!!!");
		return;
	}
	printf("\t %d deleted ",(*head)->info);
	loc = *head;
	while (loc->next != *head)
	{
		locp=loc;
		loc=loc->next;
	}
	if(loc==*head)
		*head=NULL;
	else
		locp->next=*head;
	loc->next=NULL;
	free(loc);
	return;
}	
	
		

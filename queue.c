#include<stdio.h>
#include<stdlib.h>

typedef struct que
{	
	struct que *next;
	int info;
}queue;
void enqueue(queue**, queue**,int);
int dequeue(queue**,queue**);
int main()
{	queue *front=NULL;
	queue *rear=NULL;
	int item,ch;
	 while(1)
       	 {
       		 printf("\n1.Enqueue\n2.Dequeue0.Exit\nEnter your choice: ");
               	 scanf("%d",&ch);
               	//switch to display menu
       		switch(ch)
		{
                	case 1:
                    		printf("\nEnter the information");
				scanf("%d",&item);
				enqueue( &front,&rear,item);
				break;
			case 2:
				item=dequeue(&front,&rear);
				if(item!=9999)
				printf("\n information dequeued: %d",item);
				break;
			case 0:
				exit(0);
			default:
				printf("invalid...\n");
		}
	}

	return(0);						
			                                                           	
}
void enqueue( queue **front,queue **rear ,int item)
{
	queue *newnode;
	newnode=(queue*)malloc(sizeof(queue));
	newnode->info=item;
	newnode->next=NULL;
	if (*front==NULL)
	{
		*front=newnode;
		*rear=newnode;
	}
	else
	{
		(*rear)->next=newnode;
		*rear=newnode;
	}
	return;
}
int dequeue(queue **front,queue **rear)
{	int item;
	queue *temp;
	if ((*front==NULL)&&(*rear==NULL))
	{
		printf("underflow");
		return(-9999);
	}
	item=(*front)->info;
	temp=*front;
	*front=temp->next;
	temp->next=NULL;
	if (temp==*rear)
	{
		*rear=NULL;
	}
	free(temp);
	return item;
}

#include<stdio.h>
#include<stdlib.h>

#define QUEUESIZE 5

struct queue
{
	int info [QUEUESIZE];
	int front;
	int rear;
};
int queue_full(struct queue*);
int queue_empty(struct queue*);
void enqueue(struct queue* ,int);
int dequeue(struct queue*);

void main()
{
	int ch, item;
	struct queue *pq ,q;
	pq=&q;
	pq-> front =-1;
	pq->rear= -1;
	while(1)
	{
		printf("\n1.Enqueue\n2.Dequeue\n0.Exit\n3.Enter Your Choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the information");
				scanf("%d",&item);
				enqueue(pq,item);
				break;
			case 2: item=dequeue(pq);
				if (item!=  -9999)
					printf("\nElement Dequeued : %d",item);
				break;
			case 0: exit(0);
			default:
				printf("INVALID INPUT.........!!!!");
			
		}
	}
	return;
}
int queue_full(struct queue *pq)
{
	if (pq->front==0 && pq->rear == QUEUESIZE-1 || pq->front==pq->rear + 1)
		return 1;
	else
		return 0;
}
int queue_empty(struct queue *pq)
{
	if (pq->front==-1 && pq->rear==-1)
		return 1;
	else
		return 0;
}
void enqueue(struct queue *pq,int item)
{
	if (queue_full(pq))
	{
		printf("OVERFLOW!!");
		return;
	}
	if (queue_empty(pq))
	{
		pq->front=0;
		pq->rear=0;
	}
	else if(pq->rear==QUEUESIZE-1)
		pq->rear=0;
	else
		pq->rear=pq->rear+1;

	pq->info[pq->rear] = item;
	return;
}
int dequeue(struct queue *pq)
{
	int item;
	if (queue_empty(pq))
	{
		printf("UNDERFLOW");
		return (-9999);
	}
	item=pq->info[pq->front];
	if(pq->front == pq->rear)
	{
		pq->front=-1;
		pq->rear=-1;
	}
	else if (pq->front==QUEUESIZE-1)
		pq->front=0;
	else
		pq->front=pq->front+1;
	return item;
}

				

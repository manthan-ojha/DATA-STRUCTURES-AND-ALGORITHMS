#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

typedef struct dequ
{
	int info [SIZE];
	int left;
	int right;
}deque;

int deque_full( deque *);
int deque_empty( deque *);
void insert_left(deque *, int);
void insert_right(deque * ,int);
int  delete_left(deque *);
int delete_right(deque *);

int main()
{
	int ch,item;
	deque *dq ,q;
	dq=&q;
	dq->left=-1;
	dq->right=-1;
	while(1)
	{
		printf("\n1.Insert at Left\n2.Insret at Right\n3.Delete At Left\n4.Delete At Right\n0.Exit\nEnter Your Choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nEnter the item");
				scanf("%d",&item);
				insert_left(dq,item);
				break;
			case 2: printf("\nEnter the item");
				scanf("%d",&item);
				insert_right(dq,item);
				break;
			case 3: item=delete_left(dq);
				if (item!=-9999);
					printf("\n Item deleted:%d",item);
				break;
			case 4: item=delete_right(dq);
				if (item!=-9999)
		 			printf("\n Item deleted:%d",item);
				break;
			case 0: exit(0);
			default : printf("\ninvalid input");
		}
	}
	return 0;
}

int deque_full(deque *dq)
{
	if(dq->left==dq->right +1||(dq->left==0 && dq->right==SIZE-1))
		return 1;
	else
		return 0;
}
int deque_empty( deque *dq)
{
	if ( dq->left==-1 && dq->right==-1)
		return 1;
	else
		return 0;
}	
void  insert_left(deque *dq , int item)
{
	if (deque_full(dq))
	{
		printf("\nOVERFLOW\n") ;
		return;
	}
	if (deque_empty(dq))
	{
		dq->right=0;
		dq->left=0;
	}
	else if(dq->left==0)
		dq->left=SIZE-1;
	else
		dq->left=dq->left-1;
	dq->info[dq->left]=item;
	return;
}
void insert_right(deque *dq, int item)
{
	if (deque_full(dq))
	{
		printf("\nOVERFLOW");
		return;
	}
	if (deque_empty(dq))
	{
		dq->right=0;
		dq->left=0;
	}
	else if(dq->right==SIZE-1)
		dq->right=0;
	else 
		dq->right=dq->right+1;
	dq->info[dq->right]=item;
	return;
}
int delete_left(deque *dq)
{	int item;
	if (deque_empty(dq))
	{
		printf("underflow");
		return(-9999);
	}
	item=dq->info[dq->left];
	if(dq->left==dq->right)
	{
		dq->left=-1;
		dq->right=-1;
	}
	else if(dq->left==SIZE-1)
		dq->left=0;
	else
		dq->left=dq->left+1;
	return(item);
}
int delete_right(deque *dq)
{
	int item;
	if (deque_empty(dq))
	{
		printf("\nunderflow");
		return(-9999);
	}
	item=dq->info[dq->right];
	if(dq->left==dq->right)
	{
		dq->left=-1;
		dq->right=-1;
	}
	else if(dq->right==0)
		dq->right=SIZE-1;
	else
		dq->right=dq->right-1;
	return item;
}

#include<stdio.h>
#include<stdlib.h>

//Structure defination
typedef struct stk
{
	int info;
	struct stk *next;
}stack;

//Function prototypes
void push(stack **,int);
int pop(stack **);
int stack_empty(stack *);
void stack_top(stack *);

//Main function
int main()
{
	int item,ch;
	stack *top=NULL;
	while(1)
	{
		printf("\n1.Push\n2.Pop\n3.Print\n0.Exit\nEnter your choice: ");
		scanf("%d",&ch);
		//switch to display menu
		switch(ch)
		{
			case 1:
				printf("\nEnter the information: ");
				scanf("%d",&item);
				push(&top,item);
				break;
			case 2:
				item = pop(&top);
				if(item!=9999)
					printf("\ninformation poped: %d", item);
				break;
			case 3:
				stack_top(top);
				break;
			case 0:
				exit(0);
			default:
				printf("\nInvalid Entry!!.Try again...");
		}
	}
	return(0);
}

//Function to check whether a stack is empty or not
int stack_empty(stack *ps)
{	
	if (ps==NULL)
		return 1;
	else
		return 0;
}

//Fuction to push a element in the stack
void push(stack **ps, int item)
{	
	struct stk *newnode;
	newnode=(struct stk*)malloc(sizeof(struct stk));
	newnode->info=item;
	newnode->next=*ps;
	*ps=newnode;
	return;
}

//Fuction to pop a element in the stack
int pop(stack **ps)
{	
	int item;
	struct stk *temp;
	if (stack_empty(*ps))
	{
		printf("UNDERFLOW");
		return -9999;
	}
	item=(*ps)->info;
	temp=*ps;
	*ps=temp->next;
	temp->next=NULL;
	free(temp);
	return item;

}

//Fuction to display the top element of the stack
void stack_top(stack *ps)
{
	if (stack_empty(ps))
		printf("underflow");
	else
		printf("%d is the stack top element",ps->info);
}

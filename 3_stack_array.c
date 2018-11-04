#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

//Structure definition
typedef struct stk{
	int info[SIZE];	
	int top;
}stack;

//Function prototype
void push(stack *, int);
int pop(stack *);
int stack_empty(stack *);
int stack_full(stack *);
void stack_top(stack *);

//Main function
int main()
{
	int item,ch;
	stack s,*ps;

	ps=&s;

	ps->top=-1;

	while(1)
	{
		printf("\n1.Push\n2.Pop\n3.Print\n0.Exit\nEnter your choice:");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the information: ");
				scanf("%d",&item);
				push(ps, item);
				break;
			case 2:
				item = pop(ps);
				if(item!=-99999)
					printf("\nElement poped: %d\n", item);
				break;
			case 3:
				stack_top(ps);
				break;
			case 0:
				exit(0);
			dafault:
				printf("\nInvalid input!!!Try again....");
		}
	}

	return(0);
}

//Fuction to check whether stack is empty or not
int stack_empty(stack *ps)
{
	if (ps->top==-1)
		return 1;
	else
		return 0;

}

//Function to check whether stack is full or not
int stack_full(stack *ps)
{
	if (ps->top==SIZE-1)
		return 1;
	else
		return 0;
}

//Fucntion to push an element
void push(stack *ps,int item)
{
	if (stack_full(ps))
	{
		printf("Overflow");
		return;
	}
	ps->top=ps->top+1;
	ps->info[ps->top]=item;
	return;
}

//Fucntion to pop an element
int pop(stack *ps)
{
	int item;
	if (stack_empty(ps))
	{
		printf("UNDERFLOW");
		return -9999;
	}
	item=ps->info[ps->top];
	ps->top=ps->top-1;
	return item;

}

//Fucntion to display the top element of the stack
void stack_top(stack *ps)
{
	if (stack_empty(ps))
	{
		printf("UNDERFLOW");
	}
	else
		printf("the top element is %d",ps->info[ps->top]);
	
}



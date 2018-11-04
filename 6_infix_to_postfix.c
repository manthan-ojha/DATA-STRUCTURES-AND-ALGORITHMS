#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 30

typedef struct stk{
	char info[MAX];
	int top;
}stack;

int precedence(char);
void push(stack *, char);
char pop(stack *);
char stack_top(stack *);
int empty_stack(stack *);
void postfix(char [],char []);


int main()
{
	char in[MAX], post[MAX];
	int i=0;
	printf("\nEnter the infix expression: ");
	while((in[i++]=getchar())!='\n');
	in[--i]='\0';
	puts(in);
	postfix(in, post);
	printf("\nPostfix Expression is %s\n",post);
	return(0);
}
void postfix(char in[],char post[])
{
	char x,y;
	int len,ipos=0,ppos=0;
	stack s;
	stack *ps=&s;
	ps->top=-1;
	len=strlen(in);
	in[len]=')';
	push(ps,'(');

	while(!stack_empty(ps))
	{
		x=in[ipos++];
		if(isalpha(x))
			post[ppos++]=x;
		else if(x=='(')
			push(ps,'(');
		else if(x==')')
		{
			while(stack_top(ps)!='(')
			{
				y=pop(ps);
				post[ppos++]=y;
			}
			y=pop(ps);
		}
		else
		{
			while(precedence(stack_top(ps))>=precedence(x))
			{
				y=pop(ps);
				post[ppos++]=y;
			}
			push(ps,x);
		}
	}	
	post[ppos]='\0';
	return;
}
	

void push(stack *ps, char item)
{
	ps->top=ps->top+1;
	ps->info[ps->top]=item;
	return;
}

char pop(stack *ps)
{
	char item;
	item=ps->info[ps->top];
	ps->top=ps->top-1;
	return item;
}
char stack_top(stack *ps)
{
	char item;
	item=ps->info[ps->top];
	return item;
}
int stack_empty(stack *ps)
{
	if (ps->top==-1)
		return 1;
	else
		return 0;
}
int precedence(char c)
{
	switch(c)
	{
		case '^': return(3);
		case '*':
		case '/': return(2);
		case '+':
		case '-': return(1);
	}
	return(0);
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define SIZE 30

typedef struct stk{
	int info[SIZE];
	int top;
}stack;


void push(stack *, int);
int pop(stack *);
void eval( stack *,char *);
void calculate(stack *, char);
void result_print(stack *);
int main()
{
	int item, item1, item2, i;
	stack s,*ps;

	ps=&s;

	ps->top=-1;

	char a[30], ch;

	system("clear");
	printf("\nEnter the postfix expression: ");
	gets(a);
	eval(ps,a);
	return(0);
}
void eval( stack *ps,char *a)
{
	int len ,i;
	int num;
	char x;
	len=strlen(a);
	a[len]=')';
	for(i=0;a[i]!=')';i++)
	{
		x=a[i];
		if(x>='0'&& x<='9')
			push(ps,(x-'0'));
		else
			calculate(ps,x);
	}
	result_print(ps);	
}
void push(stack *ps, int num)
{
	ps->top=ps->top+1;
        ps->info[ps->top]=num;
        return;
	
}

int pop(stack *ps)
{	
	int num;
	num=ps->info[ps->top];
        ps->top=ps->top-1;
        return num;

}

void calculate(stack *ps, char ch)
{
	int a,b;
	a=pop(ps);
	b=pop(ps);
	switch(ch)
	{
		case '+' :push(ps,b+a);
			  break;
		case '-':push(ps,b-a);
			break;
		case '*':push(ps,b*a);
			break;
		case '/':push(ps,b/a);
			break;
		case '^':push(ps,pow(b,a));
			break;
	}
}
void result_print(stack *ps)
{
	printf("Result: %d\n",ps->info[ps->top]);
}

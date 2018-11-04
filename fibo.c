#include<stdio.h>
#include<stdlib.h>

int fibo(int);
int main()
{
	int n,a,i;
	printf("\nenter the number of terms\n");
	scanf("%d",&n);
	printf("\nthe Nth term of fibonacci series is:\n");
	for(i=0;i<n;i++)
	{
		a=fibo(i);
		printf("\n%d\n",a);
	}
	return 0;	
}

int fibo(int n)
{		
	if((n==0)||(n==1))
	{
		return(n);
	}
	return(fibo(n-2)+fibo(n-1));
}

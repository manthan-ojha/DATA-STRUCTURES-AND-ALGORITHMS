#include<stdio.h>

void heapsort(int A[],int);
void build(int A[],int);
void max(int A[],int,int);

int main()
{
        int n;
        int A[100],i;
        printf("enter the number of elements\n");
        scanf("%d",&n);
        printf("\nenter the elements to be sorted\n");
        for(i=1;i<=n;i++)
        {
                scanf("%d",&A[i]);

        }
        printf("\nThe unsorted array is\n");
        for(i=1;i<=n;i++)
        {
                printf("%d \t",A[i]);
        }
        printf("\nThe sorted array is\n");
        heapsort(A,n);
        for(i=1;i<=n;i++)
        {
                printf("%d \t",A[i]);
        }
        return 0;
}
void heapsort(int A[],int n)
{
	int temp,i;
	build(A,n);
	for(i=n;i>=2;i--)
	{
		temp=A[1];
		A[1]=A[i];
		A[i]=temp;
		max(A,1,i-1);
	}
	return;
}
void build(int A[],int n)
{	
	int i;
	for(i=(n/2);i>=1;i--)
	{
		max(A,i,n);
	}
	return;
}
void max(int A[],int i,int n)
{
	int child,item,par;
	child=2*i;
	item=A[i];
	while(child<=n)
	{
		if((child<n)&& A[child]<A[child+1])
			child=child+1;
		if(item>=A[child])
			break;
		par=child/2;
		A[par]=A[child];
		child=2*child;
	}
	par=(child/2);
	A[par]=item;
	return;
}

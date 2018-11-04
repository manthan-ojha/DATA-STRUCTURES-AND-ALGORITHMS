#include<stdio.h>
#include<stdlib.h>

void quicksort(int A[],int,int);
int partition(int A[],int,int);

int main()
{
        int n;
        int A[n],i;
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
	quicksort(A,1,n);
	for(i=1;i<=n;i++)
	{
		printf("%d \t",A[i]);
	}
	return 0;
}
void quicksort(int A[],int p,int r)
{	
	int q;
	if (p<r)
	{
		q=partition(A,p,r);
		quicksort(A,p,q-1);
		quicksort(A,q+1,r);
	}
	return;
}
int partition(int A[],int p,int r)
{
	int x=A[p];
	int temp,t,q,j;
	int i=p;
	for(j=p+1;j<=r;j++)
	{
		if (A[j]<=x)
		{
			i=i+1;
			if(i!=j)
			{
				temp=A[j];
				A[j]=A[i];
				A[i]=temp;
			}
		}
	}
	t=A[i];
	A[i]=A[p];
	A[p]=t;
	q=i;
	return q;
}
			

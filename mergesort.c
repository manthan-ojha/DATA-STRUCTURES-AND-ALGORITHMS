#include<stdio.h>
#include<stdlib.h>

void merge_sort(int A[],int ,int);
void merge(int A[],int,int,int);
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
	merge_sort(A,1,n);
	for(i=1;i<=n;i++)
	{
		printf("%d \t",A[i]);
	}
	return 0;
}
void merge_sort(int A[],int p,int r)
{	
	int q;
	if(p<r)
	{
		q=(p+r)/2;
		merge_sort(A,p,q);
		merge_sort(A,q+1,r);
		merge(A,p,q+1,r);
	}
	return;
}
void merge(int A[],int ls,int rs,int re)
{
	int k=0,j,i,temp[50];
	int le=rs-1;
	i=ls;
	j=rs;
	while((i<=le)&&(j<=re))
	{
		if(A[i]<A[j])
		{
			k=k+1;
		        temp[k]=A[i];
			i=i+1;
		}
		else
		{
			k=k+1;
			temp[k]=A[j];
			j=j+1;
		}
	}
	while(i<=le)
	{
		k=k+1;
		temp[k]=A[i];
		i=i+1;
	}
	while(j<=re)
	{
		k=k+1;
		temp[k]=A[j];
		j=j+1;
	}
	for(i=1;i<=k;i++)
	{
		A[ls-1+i]=temp[i];
	}
	return;
}

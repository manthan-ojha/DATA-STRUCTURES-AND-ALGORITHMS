#include<stdio.h>
#include<stdlib.h>
void insertsort(int A[],int);
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
        insertsort(A,n);
        for(i=1;i<=n;i++)
        {
                printf("%d \t",A[i]);
        }
        return 0;
}
void insertsort(int A[],int n)
{
	int i,j,x;
	for(i=2;i<=n;i++)
	{
		x=A[i];
		j=i-1;
		while((j>=1)&&(A[j]>x))
		{
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=x;
	}
	return;
}

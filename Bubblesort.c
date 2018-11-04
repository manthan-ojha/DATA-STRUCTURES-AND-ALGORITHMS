#include<stdio.h>
#include<stdlib.h>

void bubblesort(int A[],int);
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
        bubblesort(A,n);
        for(i=1;i<=n;i++)
        {
                printf("%d \t",A[i]);
        }
        return 0;
}
void bubblesort(int A[],int n)
{
	int i,j,temp;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<n+1-i;j++)
		{
			if(A[j]>A[j+1])
			{
				temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
			}
		}
	}
}

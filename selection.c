#include<stdio.h>
#include<stdlib.h>
void selectsort(int A[],int);
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
        selectsort(A,n);
        for(i=1;i<=n;i++)
        {
                printf("%d \t",A[i]);
        }
        return 0;
}
void selectsort(int A[],int n)
{
	int i,j,temp;
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if (A[i]>A[j])
			{
				temp=A[i];
				A[i]=A[j];
				A[j]=temp;
			}
		}
	}
}

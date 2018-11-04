#include<stdio.h>
#include<stdlib.h>

int linear(int A[],int,int);
int main()
{
        int n,key,loc;
        int A[100],i;
        printf("enter the number of elements\n");
        scanf("%d",&n);
        printf("\nenter the elements to be sorted\n");
        for(i=1;i<=n;i++)
        {
                scanf("%d",&A[i]);

        }
        printf("\nThe array is\n");
        for(i=1;i<=n;i++)
        {
                printf("%d \t",A[i]);
        }
        printf("\nEnter the element to be searched\n");
	scanf("%d",&key);
        loc=linear(A,n,key);
	if(loc!=0)
	       	printf("\n The element is at the position:%d\n",loc);
	else
		printf("not found!!");
	return 0;
}
int linear(int A[],int n,int key)
{
	int i=1;
	int loc=0;
	while(i<=n)
	{
		if(key==A[i])
		{
			loc=i;
			break;
		}
		i=i+1;
	}
	return(loc);
}	

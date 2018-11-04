#include<stdio.h>
#include<stdlib.h>

int binary(int A[],int,int,int);
int main()
{
        int n,key,loc;
        int A[100],i;
        printf("enter the number of elements\n");
        scanf("%d",&n);
        printf("\nenter the elements to be sorted\n");
        for(i=0;i<n;i++)
        {
                scanf("%d",&A[i]);

        }
        printf("\nThe array is\n");
        for(i=0;i<n;i++)
        {
                printf("%d \t",A[i]);
        }
        printf("\nEnter the element to be searched\n");
        scanf("%d",&key);
        loc=binary(A,0,n-1,key);
        if(loc!=-1)
                printf("\n The element is at the position:%d\n",loc);
        else
                printf("not found!!");
        return 0;
}
int binary(int A[],int LB,int UB,int item)
{	
	int mid;
	int beg=LB;
	int end=UB;
	int j=-1;
	while((beg<=end)&&(j==-1))
	{
		mid=(beg+end)/2;
		if(item==A[mid])
		 j=mid;
		else if(item<A[mid])
		 end=mid-1;
		else
		 beg=mid+1;
	}
	return j;
}

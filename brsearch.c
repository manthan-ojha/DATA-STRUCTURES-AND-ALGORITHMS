#include<stdio.h>
#include<stdlib.h>

int binaryr(int A[],int,int,int);
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
        loc=binaryr(A,1,n,key);
        if(loc!=0)
                printf("\n The element is at the position:%d\n",loc+1);
        else
                printf("not found!!");
        return 0;
}
int binaryr(int A[],int beg,int end,int item)
{
	if(beg>end)
		return 0;
	int mid=(beg+end)/2;
	if(item==A[mid])
		return mid;
	if(item>A[mid])
		return binaryr(A,mid+1,end,item);
	else
		return	binaryr(A,beg,mid-1,item);
}	

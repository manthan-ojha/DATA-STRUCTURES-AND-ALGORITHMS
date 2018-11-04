#include<stdio.h>

int inter(int [],int,int,int);
void sort(int [],int);
int main()
{
        int n,key,loc;
        int A[100],i;
        printf("enter the number of elements\n");
        scanf("%d",&n);
        printf("\nenter the elements to be sorted\n");
        for(i=0;i<n;i++)
                scanf("%d",&A[i]);
        printf("\nEnter the element to be searched\n");
        scanf("%d",&key);
	sort(A,n);
        loc=inter(A,0,n-1,key);
        if(loc!=0)
                printf("\n The element is at the position:%d\n",loc);
        else
                printf("not found!!");
        printf("\nThe array is\n");
        for(i=0;i<n;i++)
                printf("%d \t",A[i]);
        return 0;
}
int inter(int A[],int lb,int ub,int key)
{
	int beg=lb;
	int end=ub;
	int j=-1;
	int pos,temp;
	if(key<A[beg] || key>A[end])
		return j;
	while(beg<=end && j==-1)
	{
		pos=beg+((key-A[beg])*(end-beg))/(A[end]-A[beg]);
		
		if (key==A[pos])
			j=pos;
		else if(key<A[pos])
			end=pos-1;
		else
			beg=pos+1;
	}
	return j;
}
void sort(int A[],int n)
{
	int i,j,temp,flag;
	flag = 1;
	for(i=0;i<n && flag == 1;i++)
	{
		flag = 0;
		for(j=0;j<n-i-1;j++)
		{
			if(A[j]>A[j+1])
			{
				temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
				flag = 1;
			}
		}
	}
}

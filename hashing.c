#include<stdio.h>
#define m 13

int insert(int [],int);
int search(int[],int);

int main()
{	
	int key,keys,i,ch;
	int A[m]={0,0};
	for(i=0;i<m;i++)
		printf("%d\t",A[i]);
	do{
	printf("\nenter the elements to be inserted\n");
	scanf("%d",&key);
	insert(A,key);
	for(i=0;i<m;i++)
		printf("%d\t",A[i]);
	printf("\n 1 to continue .");
	scanf("%d",&ch);	
	}while(ch==1);
	printf("\nenter the element to be searched\n");
	scanf("%d",&keys);
	i=search(A,keys);
	if(i==-1)
		printf("\nkey not found ");
	return 0;

}


		
int insert(int A[],int k)
{
	int i=0,j;
	int u=k%m;
	do
	{
		j=(u+i)%m;
		if(A[j]==0)
		{
			A[j]=k;
			printf("the element inserted at %d\n", j);
			break;
		}
		i=i+1;
	} while(i!=m);

	return -1;
}
int search(int A[],int k)
{
	int i=0,j;
	int u=k%m;
	do
	{
		j=(u+i)%m;
		if (A[j]==k)
		{
			printf("the element found at %d", j);
			return j;
		}

		i=i+1;
	} while((A[j]!=0)||(i!=m));

	return -1;
}
	

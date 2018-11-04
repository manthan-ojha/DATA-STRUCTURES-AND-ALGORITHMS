#include<stdio.h>
#include<stdlib.h>

void queen(int,int);
int col[10];
int c;

int main()
{
	int n;
	printf("\nenter the number of queen\n");
	scanf("%d",&n);
	queen(1,n);
}
void queen (int k,int n)
{
	int i,j,z;
	int legal;
	for(j=1;j<=n;j++)
	{
		legal=1;
		for(i=1;i<=k-1;i++)
		{
			if ((col[i]==j)|| abs(col[i]-j)==abs(i-k))
			{
				legal=0;
				break;
			}
		}
		if (legal)
		{ 
			col[k]=j;
			if(k==n)
			{
				printf("\nSolv %d: ",++c);
				for(z=1;z<=n;z++)
				{
					printf("%d  ",col[z]);
				}
			}
			else
				queen(k+1,n);
		}
	}
	return;
}


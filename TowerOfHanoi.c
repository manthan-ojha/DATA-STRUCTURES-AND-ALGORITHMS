#include<stdio.h>
#include<stdlib.h>
void tower(int,char,char,char);
int main()
{
	int n;
	printf("\nEnter number of disks: ");	
	scanf("%d",&n);
	printf("\nMoves are -\n");
	tower(n,'S','A','D');
	return(0);
}
void tower(int n,char beg,char aux, char end)
{
	if(n==1)
	{
		printf("\n%c->%c",beg,end);
		return;
	}
	tower(n-1,beg,end,aux);
	printf("\n%c->%c",beg,end);
	tower(n-1,aux,beg,end);
	return;
}

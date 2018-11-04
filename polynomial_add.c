#include<stdio.h>
#include<stdlib.h>

struct poly
{
        float coeff;
        int expo;
        struct poly *next;
};
void create( struct poly **,int);
void add(struct poly **,struct poly **, struct poly **);
void insert(struct poly **,float,int);
void traverse(struct poly*);
int main()
{
        struct poly *head1 = NULL,*head2=NULL, *head3=NULL;
	printf("\ncreate the first polynomial\n");
	create(&head1,3);
	printf("\ncreate the second polynmomial\n");
	create(&head2,3);	
	printf("\nthe resulant polynomial is\n");
	add(&head1,&head2,&head3);
	traverse(head3);
	
}
void create(struct poly **head ,int n)
{
	struct poly *temp,*newnode;
	int i,e;
	float c;
	if(*head!=NULL)
	return;
	for(i=1;i<=n;i++)
	{
		printf("\nenter the coefficient\n");
		scanf("%f",&c);
		printf("\nenter the expo\n");
		scanf("%d",&e);
		newnode=(struct poly*)malloc(sizeof(struct poly));
		newnode->coeff=c;
		newnode->expo=e;
		newnode->next=NULL;
		if(*head==NULL)
			*head=newnode;
		else
			temp->next=newnode;
		temp=newnode;
	}
	return;
}
void add(struct poly **head1,struct poly **head2,struct poly **head3)
{	
	float sum;
	struct poly *loc1 , *loc2;
	loc1=*head1;
	loc2=*head2;
	while((loc1 != NULL)&&(loc2 != NULL))
	{
		if(loc1->expo==loc2->expo)
		{
			sum=(loc1->coeff)+(loc2->coeff);
			if(sum !=0)
				insert(head3,sum,loc1->expo);
			loc1=loc1->next;
			loc2=loc2->next;
		}
		else if((loc1->expo)>(loc2->expo))
		{
			insert(head3,loc2->coeff,loc2->expo);
			loc2=loc2->next;
		}
		else 
		{
			insert(head3,loc1->coeff,loc1->expo);
			loc1=loc1->next;
		}
	}
	while(loc1!=NULL)
		{
			insert(head3,loc1->coeff,loc1->expo);
			loc1=loc1->next;
		}
	while(loc2!=NULL)
		{
			insert(head3,loc2->coeff,loc2->expo);
			loc2=loc2->next;
		}
	return;
}
void insert(struct poly **head , float c, int e)
{	
	struct poly *loc,*newnode;
	newnode=(struct poly*)malloc(sizeof(struct poly));
	newnode->coeff=c;
	newnode->expo=e;
	newnode->next=NULL;
	loc=*head;
	if(loc==NULL)
		*head=newnode;
	else
		{
			while ((loc->next)!=NULL)
				loc=loc->next;
			loc->next=newnode;
		}
}
void traverse(struct poly *head)
{	
	struct poly *loc=head;
	while(loc!=NULL)
	{
		printf("%fX^%d\t",loc->coeff,loc->expo);
		loc=loc->next;
	}
}	

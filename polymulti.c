#include<stdio.h>
#include<stdlib.h>

struct poly
{
        float coeff;
        int expo;
        struct poly *next;
};
void create( struct poly **,int);
void multi(struct poly **,struct poly **, struct poly **);
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
	printf("\n1st Polynomial\n");
	traverse(head1);
	printf("\n2nd Polynomial\n");
	traverse(head2);
	printf("\n");
        multi(&head1,&head2,&head3);
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
void multi(struct poly **head1,struct poly **head2,struct poly **head3)
{	
	struct poly *loc1,*loc2;
	int e;
	float c;
	if((*head1==NULL)||(*head2==NULL))
	{
		printf("\nMultiplication is not possible\n");
		return;
	}
	loc1=*head1;
	while(loc1!=NULL)
		{
			loc2=*head2;
			while(loc2!=NULL)
			{
				c=(loc1->coeff)*(loc2->coeff);
				e=(loc1->expo)+(loc2->expo);
				insert(head3,c,e);
				loc2=loc2->next;
			}
			loc1=loc1->next;
		}
	return;
}
void insert(struct poly **head , float c, int e)
{	
	struct poly *newnode;
	struct poly *loc=*head;
	struct poly *locp=NULL;
	while((loc!=NULL)&&((loc->expo)>e))
	{
		locp=loc;
		loc=loc->next;
	}
	if((loc!=NULL)&&((loc->expo)==e))
	{
		loc->coeff=(loc->coeff)+c;
		return;
	}
	newnode=(struct poly*)malloc(sizeof(struct poly));
	newnode->coeff=c;
	newnode->expo=e;
	newnode->next=NULL;
	if(*head==loc)
	{
		newnode->next=*head;
		*head=newnode;
	}
	else
	{
		newnode->next=locp->next;
		locp->next=newnode;
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


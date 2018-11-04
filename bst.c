#include<stdio.h>
#include<stdlib.h>

struct tree
{
	struct tree *left,*right ;
	int info;	
};

typedef struct 
{
	struct tree *arr[50];
	int top;
}stack;

void insert(struct tree **, int);
void recursive_preorder(struct tree * );
void recursive_inorder(struct tree * );
void recursive_postorder(struct tree * );
void find_min_max_element(struct tree *);
int height(struct tree *);
void delete(struct tree** ,int);

void non_recursive_preorder(struct tree *);
void non_recursive_inorder(struct tree * );
void push(struct tree *,stack *);
struct tree *pop(stack *);
int stack_empty(stack *);

int  main()
{
	struct tree *root = NULL;
	int item,ch;

	while(1)
	{
		printf("\n1.Insert\n2.Traverse preorder\n3.Traverse Inorder\n4.Traverse Postorder\n5.Min & Max elements\n6.Height\n7.Delete\n8.NonRec Preorder\n9.NnoRec Inorder\n0. Exit\n\nEnter Your Choice : ");
		scanf("%d",&ch);
		switch(ch)
			{
				case 0:exit(0);
				case 1:printf("\nenter the item\n");
					scanf("%d",&item);
					insert(&root,item);
					break;
				case 2:recursive_preorder(root);
					break;
				case 3:recursive_inorder(root);
					break;
				case 4:recursive_postorder(root);
					break;
				case 5:find_min_max_element(root);
					break;
				case 6:printf("\nHeight of tree = %d",height(root));
					break;
				case 7:printf("\nenter the item to be deleted\n");
					scanf("%d",&item);
					delete(&root,item);
					break;
				case 8:non_recursive_preorder(root);
					break;
				case 9://non_recursive_inorder(root);
					break;
			}
	
	}
	
	return 0;
}
void insert(struct tree **root,int item)
{
	struct tree *par , *loc,*newnode;
	par=NULL;
	loc=*root;
	while(loc!=NULL)
	{
		if (item == (loc->info))
		{ 
			printf("\nDuplicate Item !!\n");
			return;
		}
		par=loc;
		if (item<(loc->info))
			loc=loc->left;
		else
			loc=loc->right;
	}
	newnode =(struct tree*)malloc(sizeof(struct tree));
	newnode->info=item;
	newnode->left=NULL;
	newnode->right=NULL;
	if (par==NULL)
		*root=newnode;
	else if (item<(par->info))
		par->left=newnode;
	else
		par->right=newnode;
	return;
}
void recursive_preorder( struct tree *root)
{
	if (root!=NULL)
	{
		printf("\n%d ",root->info);
		recursive_preorder(root->left);
		recursive_preorder(root->right);
	}
}
void recursive_inorder( struct tree *root)
{
	if(root!=NULL)
	{
		recursive_inorder(root->left);
		printf("\n%d ",root->info);
		recursive_inorder(root->right);
	}
}
void recursive_postorder( struct tree *root)
{
	if(root!=NULL)
	{
		recursive_postorder(root->left);
		recursive_postorder(root->right);
		printf("\n%d ",root->info);
	}
}

void find_min_max_element(struct tree * root)
{
	struct tree *loc=root;
	while(loc->left!=NULL)
		loc=loc->left;
	printf("\n Minimum element is %d",loc->info);
	loc=root;
	while(loc->right!=NULL)
		loc=loc->right;
	printf("\n Maximum element is %d",loc->info);
}
int height(struct tree *root)
{
	int l,r;
	if(root!=NULL)
	{
		l=1+height(root->left);
		r=1+height(root->right);
		if(l>r)
			return l;
		else
			return r;
	}
	return(-1);
}
void delete( struct tree **root , int item)
{
	struct tree *par , *loc ,*child;
	par=NULL;
	loc=*root;
	while((loc!=NULL)&&(loc->info!=item))
	{
		par=loc;
		if (item<(loc->info))
			loc=loc->left;
		else
			loc=loc->right;
	}
	if (loc==NULL)
	{
		printf("\nnode does not exist\n");
		return;
	}
	if ((loc->left==NULL)&&(loc->right==NULL))
		child=NULL;
	else if (loc->left==NULL)
		child=loc->right;
	else if(loc->right==NULL)
		child=loc->left;
	if(par!=NULL)
	{
		if(loc==par->left)
			par->left=child;
		else
			par->right=child;
	}
	else
		*root=child;
	loc->left=NULL;
	loc->right=NULL;
	free(loc);
	return;
}
 			
void non_recursive_preorder(struct tree *root )
{
	struct tree *temp;
	temp = root;
	stack s,*ps;
	ps = &s;
	ps->top = -1;

	while(1)
	{
		while(temp != NULL)
		{
			printf("%d, ",temp->info);
			push(temp,ps);
			temp = temp->left;
		}
		if(stack_empty(ps))
			break;
		temp = pop(ps);
		temp = temp->right;
	}
	return;
}
void non_recursive_inorder(struct tree *root)
{
	struct tree *temp;
	temp = root;
	stack s,*ps;
	ps = &s;
	ps->top = -1;

	while(1)
	{
		while(temp != NULL)
		{
			push(temp,ps);
			temp = temp->left;
		}
		if(stack_empty(ps))
			break;
		temp = pop(ps);
		printf("%d, ",temp->info);
		temp = temp->right;
	}
	return;
}

void push(struct tree *temp,stack *ps)
{
	ps->top++;
	ps->arr[ps->top] = temp;
	return;
}
struct tree *pop(stack *ps)
{
	struct tree *temp;
	temp = ps->arr[ps->top];
	ps->top--;
	return(temp);
}
int stack_empty(stack *ps)
{
	if(ps->top == -1)
		return 1;
	return 0;
}

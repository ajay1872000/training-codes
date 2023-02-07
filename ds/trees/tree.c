#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *left,*right;
	int data;};
struct node *root=NULL;
void insert(struct node *r,int n,struct node *ptr)
{
	if(root==NULL)
	{
		root=ptr;
		return;
	}
	if(r->data>n)
	{
		if(r->left==NULL)
		{
			r->left=ptr;
			return;}
		else{
			insert(r->left,n,ptr);
			return;}
	}
	else{
		if(r->data<n)
		{
			if(r->right==NULL)
			{
				r->right=ptr;
				return;
			}
			else{
				insert(r->right,n,ptr);
				return;}
		}
		else{
			free(ptr);
			printf("%d already present",n);
			return;}
	}
}
void inorder(struct node *r)
{
	if(r==NULL)
	{
		printf("tree is empty");
		return;}
	if(r->left!=NULL)
		inorder(r->left);
	if(r->right!=NULL)
	{
		printf("%d\t",r->data);
		inorder(r->right);
	}
	else{
		printf("%d\t",r->data);
		}
}
void postorder(struct node *r)
{
	if(r==NULL)
	{
		printf("tree is empty");
		return;}
	if(r->left!=NULL)
		postorder(r->left);
	if(r->right!=NULL)
	{
		postorder(r->right);
		printf("%d\t",r->data);
	}
	else{
		printf("%d\t",r->data);
		}
}
void preorder(struct node *r)
{
	if(r==NULL)
	{
		printf("tree is empty");
		return;}
	if(r->left!=NULL)
	{
		printf("%d\t",r->data);
		preorder(r->left);
	}
	else{
		printf("%d\t",r->data);
		}
	if(r->right!=NULL)
		preorder(r->right);
}
void delete(int n)
{
	if(root==NULL)
	{
		printf("tree is empty");
		return;}
	if(r->next==NULL)
	{
		if(r->prev==NULL)
		{
			if(r->data==n)
			{
				free(root);
				root=NULL;
			}
		}
	}
void main(){
	int n,opt;
	struct node *ptr;
	while(1){
		printf("\nMenu\n1.insert\n2.inorder\n3.preorder\n4.post order\nenter your choice");
		scanf("%d",&opt);
		switch(opt){
			case 0:exit(1);
			case 1:printf("enter n value");
			       scanf("%d",&n);
				ptr=(struct node*)malloc(1*sizeof(struct node));
				if(ptr==NULL){
					printf("failed to allocate memory");
					exit(1);}
				ptr->left=ptr->right=NULL;
				ptr->data=n;
			       insert(root,n,ptr);break;
			case 2:inorder(root);break;
			case 3:preorder(root);break;
			case 4:postorder(root);break;
			case 5:printf("enter a value");
			       scanf("%d",&n);
			       delete(n);break;
		}
	}
}

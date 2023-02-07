#include<stdio.h>
#include<stdlib.h>
#define S 10
struct node{
	int key;
	struct node *next;
};
struct node *aptr[S];
int hashcode(int n)
{
	return n%S;
}
void insert(int k)
{
	struct node *ptr,*p,*q;
	int i,j=1;
	ptr=(struct node *)malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{
		printf("failed to allocate memory");
		exit(1);
	}
	ptr->key=k;
	ptr->next=NULL;
	i=hashcode(k);
	if(aptr[i]==NULL)
		aptr[i]=ptr;
	else
	{
		while(aptr[i]!=NULL)
		{
			i=hashcode(hashcode(k)+j*j);
		}
		aptr[i]=ptr;

	}
	
}
void display()
{
	int i;
	struct node *p;
	for(i=0;i<S;i++)
	{
		p=aptr[i];
		while(p!=NULL)
		{
				printf("key=%5d\n",p->key);
				p=p->next;
		}
	}
}
void delete(int k)
{
	int i,c=0;
	struct node *p,*q;
	i=hashcode(k);
	p=aptr[i];
	while(p!=NULL)
	{
		if(aptr[i]->key==k)
		{
			p=aptr[i]->next;
			free(aptr[i]);
			aptr[i]=p;
			c++;
		}
		else{
			p=aptr[i]->next;
			q=aptr[i];
			if(p->key==k){
				q->next=p->next;
				free(p);
				p=q->next;
				c++;
			}
			else
				p=p->next;
		}
	}
	if(!c)
		printf("elements not found");
}
void search(int k)
{
	struct node *p;
	int i,c=0;
	i=hashcode(k);
	p=aptr[i];
	while(p!=NULL)
	{
		c++;
		if(p->key==k)
			printf("element found at %d index as %dth element",i,c);
			
		p=p->next;
	}
		printf("element not found");
}

void main()
{
	int i,opt,k;
	for(i=0;i<S;i++)
		aptr[i]=NULL;
	while(1)
	{
		printf("\nMENU\n0.exit\n1.insert\n2.display\n3.delete a particular key elements\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:exit(1);
			case 1:printf("enter key");
			       scanf("%d",&k);
			       insert(k);break;
			case 2:display();break;
			case 3:printf("enter key");
			       scanf("%d",&k);
			       delete(k);break;
			case 4:printf("enter key");
			       scanf("%d",&k);
			       search(k);break;
		}
	}
}

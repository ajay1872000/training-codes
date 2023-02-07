#include"header.h"
#include<stdlib.h>
#include<stdio.h>

struct node{
	int d;
	struct node *l;
};
struct node *sp=NULL;

void swap_data(int n,int m){
	int t;
	struct node *p1,*p2;
	p1=p2=sp;
	if(sp==NULL)
	{
		printf("list is empty");
		return;}
	if(n==m)
		return;
	while(p1!=NULL){
		if(p1->d==n)
			break;
		p1=p1->l;}
	while(p2!=NULL){
		if(p2->d==m)
			break;
		p2=p2->l;}
	if((p1==NULL)||(p2==NULL)){
		printf("data not found");
		return;}
	t=p1->d;
	p1->d=p2->d;
	p2->d=t;
}
void swap_link(int n,int m){
	struct node *p1,*p2,*t,*pp1,*pp2;
	p1=p2=sp;
	if(sp==NULL)
	{
		printf("list is empty");
		return;}
	if(n==m)
		return;
	while(p1!=NULL){
		if(p1->d==n)
			break;
		p1=p1->l;}
	while(p2!=NULL){
		if(p2->d==m)
			break;
		p2=p2->l;}
	if((p1==NULL)||(p2==NULL)){
		printf("data not found");
		return;}
	if(p1==sp){
		sp=p2;
		p1->l=p2->l;
		p2->l=p1;}
	else{
		if(p2==sp){
			sp=p1;
			p2->l=p1->l;
			p1->l=p2;}
		else{
			t=pp1->l;
			pp1->l=pp2->l;
			pp2->l=t;
			t=p1->l;
			p1->l=p2->l;
			p2->l=t;}
	}

}
void delete_dup(){
	struct node *pp=NULL,*p1,*p2;
	if(sp==NULL)
	{
		printf("list is empty");
		return;}
	for(p1=sp;p1!=NULL;p1=p1->l)
	{
		for(p2=(p1->l),pp=p1;p2!=NULL;pp=p2,p2=p2->l)
		{
			if(p1->d==p2->d)
			{
				pp->l=p2->l;
				free(p2);
				p2=pp;
			}
		}
	}
}
void del_p_n(int n){
	struct node *p,*c;
	if(sp==NULL){
		printf("list is empty");
		return;
	}
	c=sp;
	p=NULL;
	while(c!=NULL){
		if(c->d==n){
			p->l=c->l;
			free(c);
			break;}
		p=c;
		c=c->l;
	}
	printf("element not found");
}
void delete_stack(){
	struct node *c;
	c=sp;
	while(sp!=NULL){
		c=sp;
		sp=sp->l;
		free(c);
	}
}
void add_bef(int n,int m){
	struct node *p,*c,*ptr;
	if(sp==NULL){
		printf("list is empty");
		return;}
	c=sp->l;
	p=sp;
	if(sp->d==n){
		if(sp->l==NULL){
		ptr=(struct node*)malloc(1*sizeof(struct node));
		if(ptr==NULL){
			printf("failed allocate memory");
			exit(1);}
		ptr->l=sp;
		sp=ptr;
		ptr->d=m;
			return;}}

	while(c!=NULL){
		if(c->d==n)
		{
			ptr=(struct node*)malloc(1*sizeof(struct node));
		
		if(ptr==NULL){
			printf("failed allocate memory");
			exit(1);}
			ptr->l=c;
			p->l=ptr;
			ptr->d=m;
			return;
		}
		p=c;c=c->l;
	}
	printf("element is not found");
}
void add_aft(int n,int m){
	struct node *c,*ptr,*t;
	if(sp==NULL){
		printf("list is empty");
		return;}
	c=sp;
	while(c!=NULL){
		if(c->d==n){
		ptr=(struct node*)malloc(1*sizeof(struct node));
		if(ptr==NULL){
			printf("failed allocate memory");
			exit(1);}
		ptr->l=c->l;
		c->l=ptr;
		ptr->d=m;
		return;}
		c=c->l;
	}
	printf("element not found");
}
			

void createlist(int *a,int n){
	int i;
	struct node *start=NULL,*p,*ptr;
	for(i=0;i<n;i++){
		ptr=(struct node*)malloc(1*sizeof(struct node));
		if(ptr==NULL)
		{
			printf("failed to allocate memory");
			exit(1);
		}
		ptr->d=a[i];
		ptr->l=sp;
		sp=ptr;
	}
}
 
void main(){
	int opt,n,m,*ptr,i;

	while(1){
		printf("\nMenu\n0.exit\n1.push\n2.pop\n3.display\n4.count\n5.search\n6.reverse\n7.swap using data\n8.swap using link\n9.delete duplicate\n10.delete particular node\n11.delete stack\n12.add before\n13 add after\n14.create stack\nenter a choice");
		scanf("%d",&opt);
		switch(opt){
			case 0: exit(1);
			case 1:printf("enter a number");
			       scanf("%d",&n);
			       push(n);break;
			case 2:pop();break;
			case 3:display();break;
			case 4:n=count();
			       if(n>0)
				       printf("%d elements are present",n);
			       break;
			case 5:printf("enter a number");
			       scanf("%d",&n);
			       search(n);break;
			case 6:rev();break;
			case 7:printf("enter inputs");
			       scanf("%d %d",&n,&m);
			       printf("%d %d",m,n);
			       swap_data(n,m);break;
			case 8:printf("enter inputs");
			       scanf("%d %d",&n,&m);
			       printf("%d %d",m,n);
			       swap_link(n,m);break;
			case 9:delete_dup();break;
			case 10:printf("enter a number");
				scanf("%d",&n);
			       del_p_n(n);break;
			case 11:delete_stack();break;
			case 12:printf("enter inputs");
				scanf("%d %d",&n,&m);
				add_bef(n,m);break;
			case 13:printf("enter inputs");
				scanf("%d %d",&n,&m);
				add_aft(n,m);break;
			case 14:printf("enter size of list");
				scanf("%d",&n);
				ptr=(int*)malloc(n*sizeof(int));
				if(ptr==NULL){
					printf("failed to allocate memory");
					exit(1);}
				for(i=0;i<n;i++)
					scanf("%d",ptr+i);
				createlist(ptr,n);
				free(ptr);break;


		
		}
	}
}

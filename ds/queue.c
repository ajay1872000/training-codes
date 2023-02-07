#include<stdio.h>
#include<stdlib.h>
struct node{
	int d;
	struct node *l;
};
struct node *f=NULL,*r=NULL;
void insert(int n){
	struct node *ptr;
	ptr=(struct node*)malloc(1*sizeof(struct node));

	if(ptr==NULL){
		printf("failed to allocate memory");
		exit(1);}
	ptr->l=NULL;
	ptr->d=n;
	if((f==NULL)&&(r==NULL)){
		f=r=ptr;
		return;
	}
		r->l=ptr;
	r=ptr;
}
void qremove(){
	struct node *p;
	if((f==NULL)&&(r==NULL))
	{
		printf("queue is empty");
		return;}
	if(f==r)
	{
		f=r=NULL;
		return;}
	p=r;
	r=r->l;
	free(p);
}
void display(){
	struct node *p;
	if((f==NULL)&&(r==NULL))
	{
		printf("queue is empty");
		return;}
	p=f;
	while(p!=NULL){
		printf("%d\t",p->d);
		p=p->l;}
}
int count(){
	struct node *p;
	int c=0;
	if((f==NULL)&&(r==NULL))
	{
		printf("queue is empty");
		return 0;}
	p=f;
	while(p!=NULL){
		c++;
		p=p->l;}
	return c;
}
void search(int n){
	struct node *p;
	int i=0;
	if((f==NULL)&&(r==NULL))
	{
		printf("queue is empty");
		return;}
	p=f;
	while(p!=NULL){
		if(p->d==n){
		printf("element found at %d-%p\t",i,p);
		return;}
		i++;
		p=p->l;}
	printf("element not found");
}
void deletequeue(){
	struct node *t;
	if(f==NULL){
		printf("queue is empty");
		return;}
	while(f!=NULL){
		t=f;
		f=f->l;
		free(t);}
	r=NULL;
}
void createlist(int *a,int n){
	int i;
	struct node *ptr;
	for(i=0;i<n;i++){
		ptr=(struct node*)malloc(1*sizeof(struct node));
		if(ptr==NULL){
			printf("failed to allocate memory");
			exit(1);}
		if(f==NULL)
			f=ptr;
		else 
			r->l=ptr;
		ptr->d=a[i];
		r=ptr;}
}
void deletepar(int n){
	struct node *p,*t;
	if(f==NULL)
	{
		printf("list is empty");
		return;}
	if(f->d==n){
		t=f;
		f=f->l;
		if(f==NULL)
		{
			r=NULL;
		}return;}
	t=f->l;
	p=f;
	while(t!=NULL){
		if(t->d==n){
			p->l=t->l;
			free(t);
			t=p;
			return;
		}
		p=t;
		t=t->l;
	}
	printf("element not found");
}
void rev(){
	struct node *p,*c,*n;
	if(f==NULL)
	{
		printf("queue is empty");
		return;}
	if(f==r)
		return;
	c=f;
	p=NULL;
	while(c!=NULL){
		n=c->l;
		c->l=p;
		p=c;
		c=n;}
	r=f;
	f=p;
}
void swap_link(int n,int m)
{
	int pos1=0,pos2=0;
	struct node *p1,*p2,*pp1,*pp2,*t;
	if(p1==p2)
		return;
	if(f==NULL)
	{
		printf("Queue is empty");
		return;}
	if(f==r)
		return;
	p1=f;
	pp1=NULL;
	p2=f;
	pp2=NULL;
	while(p1!=NULL)
	{
		pos1++;
		if(p1->d==n)
			break;
		pp1=p1;
		p1=p1->l;
	}
	while(p2!=NULL)
	{
		pos2++;
		if(p2->d==m)
			break;
		pp2=p2;
		p2=p2->l;
	}
	if((p1==NULL)||(p2==NULL)){
		printf("data is not found");
		return;}
	if(pos1>pos2){
		t=p1;
		p1=p2;
		p2=t;
		t=pp1;
		pp1=pp2;
		pp2=t;}
	if((p1==f)&&(p2==r))
	{
		f=p2;
		pp2->l=p1;
		r=p1;}
	else{if(p1==f){
		f=p2;
		pp2->l=p1;}
		else{
			if(p2==r){
				pp1->l=p2;
				pp2->l=p1;
				r=p1;}
			else{
				pp1->l=p2;
				pp2->l=p1;}
		}
	}
	t=p1->l;
	p1->l=p2->l;
	p2->l=t;
}
void swap_data(int n,int m)
{
	int t;
	struct node *p1,*p2,*pp1,*pp2;
	if(p1==p2)
		return;
	if(f==NULL)
	{
		printf("Queue is empty");
		return;}
	if(f==r)
		return;
	p1=f;
	pp1=NULL;
	p2=f;
	pp2=NULL;
	while(p1!=NULL)
	{
		if(p1->d==n)
			break;
		pp1=p1;
		p1=p1->l;
	}
	while(p2!=NULL)
	{
		if(p2->d==m)
			break;
		pp2=p2;
		p2=p2->l;
	}
	if((p1==NULL)||(p2==NULL)){
		printf("data is not found");
		return;}
	t=p1->d;
	p1->d=p2->d;
	p2->d=t;
}


void main(){
	int opt,n,i,*ptr;
	while(1){
		printf("\nMENU\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n0.exit\n1.insert\n2.remove\n3.display\n4.count\n5.search\n6.delete queue\n7.create list\n8.delete particular node\n9.reverse\n10.swap using data\n11.swap using link\nenter your choice");
		scanf("%d",&n);
		switch(n){
			case 0:exit(1);
			case 1:printf("enter value");
			       scanf("%d",&n);
			       insert(n);break;
			case 2:qremove();break;
			case 3:display();break;
			case 4:n=count();
			       if(n)
				       printf("%d elements are present in queue",n);
			       break;
			case 5:printf("enter a value");
			       scanf("%d",&n);
			       search(n);break;
			case 6:deletequeue();break;
			case 7:printf("enter size of list");
			       scanf("%d",&n);
			       ptr=(int*)malloc(n*sizeof(int));
			       if(ptr==NULL){
				       printf("failed to allocate memory");
				       exit(1);}
			       for(i=0;i<n;i++)
				       scanf("%d",ptr+i);
			       createlist(ptr,n);free(ptr);break;
			case 8:printf("enter delete node");
			       scanf("%d",&n);
			       deletepar(n);break;
			case 9:rev();break;
			case 10:printf("enter inputs");
				scanf("%d%d",&n,&i);
				swap_data(n,i);break;
			case 11:printf("enter inputs");
				scanf("%d%d",&n,&i);
				swap_link(n,i);break;
			case 12:printf("enter a number");
				scanf

			default:printf("invalid choice");
		}
	}
}

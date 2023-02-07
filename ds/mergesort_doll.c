#include<stdio.h>
#include<stdlib.h>
struct node{
	int d;
	struct node *n,*p;};
struct node *h1=NULL,*h2=NULL,*h3=NULL;
struct node * add_at_last(struct node *h,int num)
{
	struct node *ptr,*pr;
	ptr=(struct node *)malloc(1*sizeof(struct node));
	if(ptr==NULL){
		printf("failed to allocate memory");
		exit(1);
	}
	ptr->n=NULL;
	ptr->d=num;
	if(h==NULL)
	{	h=ptr;
		ptr->p=NULL;}
	else{
		pr=h;
		while(pr->n!=NULL)
			pr=pr->n;
		pr->n=ptr;
		ptr->p=pr;
	}

	return h;
}
void display(struct node *h)
{
	struct node *t;
	if(h==NULL)
	{
		printf("list is empty");
		return;}
	t=h;
	while(t!=NULL){
		printf("%d\t",t->d);
		t=t->n;}
}
int count(struct node * h)
{
	int c=0;
	struct node *t;
	if(h==NULL)
	{
		printf("list is empty");
		return 0;}
	t=h;
	while(t!=NULL){
		c++;
		t=t->n;}
	return c;
}
void merge(){
	struct node *p1,*ptr,*p2,*p3;
	if((h1==NULL)&&(h2==NULL)){
		printf("both lists are empty");
		return;}
	for(p1=h1,p2=h2;((p1!=NULL)&&(p2!=NULL));)
	{
		ptr=(struct node*)malloc(1*sizeof(struct node));
		if(ptr==NULL)
		{
			printf("failed to allocate memory");
		       exit(1);}
		ptr->n=NULL;
	if(p1->d==p2->d)
	{
		ptr->d=p1->d;
		p1=p1->n;
		p2=p2->n;}
	else{
		if(p1->d>p2->d){
			ptr->d=p2->d;
			p2=p2->n;}
		else{
			ptr->d=p1->d;
			p1=p1->n;}}
	if(h3==NULL)
		{
			h3=ptr;
			ptr->p=NULL;}
		
	else
	{
		p3->n=ptr;
		ptr->p=p3;}
	p3=ptr;
	}
	for(;p1!=NULL;p1=p1->n){
		ptr=(struct node*)malloc(1*sizeof(struct node));
		if(ptr==NULL)
		{
			printf("failed to allocate memory");
		       exit(1);}
		ptr->n=NULL;
		ptr->d=p1->d;
		p3->n=ptr;
		ptr->p=p3;
		p3=ptr;
	}
	for(;p2!=NULL;p2=p2->n){
		ptr=(struct node*)malloc(1*sizeof(struct node));
		if(ptr==NULL)
		{
			printf("failed to allocate memory");
		       exit(1);}
		ptr->n=NULL;
		ptr->d=p2->d;
		ptr->p=p3;
		p3->n=ptr;
		p3=ptr;
	}


}

struct node* deleteall(struct node * h){
	struct node *t;
	if(h==NULL){
		printf("list is empty");
		return h;}
	while(h!=NULL){
		t=h;
		h=h->n;
		free(t);}
	printf("succesfully deleted");
	return h;
}

void main(){
	int opt,n;
	while(1){
		printf("\nmenu\n0.exit\n1.add to 1st list\n2.add to 2nd list\n3.display 1st list\n4.display 2nd list\n5.no of elements in 1st list\n6.no of elements in 2nd list\n7.merge sort\n8.delete list 1\n9.delete list 2\nenter your choice");
		scanf("%d",&opt);
		switch(opt){
			case 0:exit(0);
			case 1:printf("enter a value");
			       scanf("%d",&n);
				h1=add_at_last(h1,n);break;
			case 2:printf("enter a value");
			       scanf("%d",&n);
				h2=add_at_last(h2,n);break;
			case 3:display(h1);break;
			case 4:display(h2);break;
			case 5:n=count(h1);
			       if(n)
				       printf("%d elements are present",n);break;
			case 6:n=count(h2);
			       if(n)
				       printf("%d elements are present",n);break;
			case 7:h3=NULL;merge();display(h3);break;
			case 8:h1=deleteall(h1);break;
			case 9:h2=deleteall(h2);break;
			default :printf("invalid case");}
	}
}

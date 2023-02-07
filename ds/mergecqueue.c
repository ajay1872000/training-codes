#include<stdio.h>
#include<stdlib.h>
struct node{
	int d;
	struct node *l;};
struct node *h1=NULL,*h2=NULL,*h3=NULL;
struct node * add_at_last(struct node *h,int n)
{
	struct node *ptr,*p;
	ptr=(struct node *)malloc(1*sizeof(struct node));
	if(ptr==NULL){
		printf("failed to allocate memory");
		exit(1);
	}
	ptr->l=h;
	ptr->d=n;
	if(h==NULL)
	{
		h=ptr;
		ptr->l=h;
	}
	else{
		p=h;
		while(p->l!=h)
			p=p->l;
		p->l=ptr;}

	return h;
}
void display(struct node *h)
{
	struct node *p;
	if(h==NULL)
	{
		printf("list is empty");
		return;}
	p=h;
	do{
		printf("%d\t",p->d);
		p=p->l;}while(p!=h);
}
int count(struct node * h)
{
	int c=0;
	struct node *p;
	if(h==NULL)
	{
		printf("list is empty");
		return 0;}
	p=h;
	do{
		c++;
		p=p->l;}
	while(p!=h);
	return c;
}
void merge(){
	int f1=1,f2=1;
	struct node *p1,*ptr,*p2,*p3;
	if((h1==NULL)||(h2==NULL)){
		printf("lists are empty");
		return;}
	p1=h1;
	p2=h2;
	do{
		ptr=(struct node*)malloc(1*sizeof(struct node));
		if(ptr==NULL)
		{
			printf("failed to allocate memory");
		       exit(1);}
		ptr->l=h3;
	if(p1->d==p2->d)
	{
		ptr->d=p1->d;
		p1=p1->l;
		f1=f2=0;
		p2=p2->l;}
	else{
		if(p1->d>p2->d){
			ptr->d=p2->d;
			p2=p2->l;
			f2=0;
		}
		else{
			ptr->d=p1->d;
			p1=p1->l;
			f1=0;
		}}
	if(h3==NULL)
	{
		h3=ptr;
		ptr->l=ptr;}
	else
		p3->l=ptr;
	p3=ptr;
	}while(((p1!=h1)||f1)&&((p2!=h2)||f2));
	if(p1!=h1){
	do{
		ptr=(struct node*)malloc(1*sizeof(struct node));
		if(ptr==NULL)
		{
			printf("failed to allocate memory");
		       exit(1);}
		ptr->l=h3;
		ptr->d=p1->d;
		p3->l=ptr;
		p3=ptr;
		f1=0;
		p1=p1->l;
	}while((p1!=h1)||f1);}
	if(p2!=h2){
	do{
		ptr=(struct node*)malloc(1*sizeof(struct node));
		if(ptr==NULL)
		{
			printf("failed to allocate memory");
		       exit(1);}
		ptr->l=h3;
		ptr->d=p2->d;
		p3->l=ptr;
		f2=0;
		p3=ptr;
		p2=p2->l;
	}while((p2!=h2)||f2);}


}

struct node* deleteall(struct node * h){
	struct node *t;
	if(h==NULL){
		printf("list is empty");
		return h;}
	do{
		t=h;
		h=h->l;
		free(t);
	}while(h!=h);
	printf("succesfully deleted");
	return NULL;
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

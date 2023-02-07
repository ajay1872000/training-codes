#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *p,*n;
	int d;};
struct node *f=NULL,*b=NULL;
void insert(int num){
	struct node *ptr=(struct node*)malloc(1*sizeof(struct node));
	if(ptr==NULL){
		printf("failed to allocate memory");
		exit(1);}
	ptr->d=num;
	if(b==NULL)
	{
		f=ptr;
		ptr->p=NULL;}
	else{
		b->n=ptr;
		ptr->p=b;}
	b=ptr;}
void delete(){
	struct node *t;
	if(b==NULL){
		printf("queue is empty");
		return;}
	if(f==b){
		free(f);
		f=b=NULL;
		return;
	}
	t=b;
	b=b->p;
	b->n=NULL;
	free(t);
	printf("succesfully deleted node");
}
void display(){
	struct node *t;
	if(f==NULL){
		printf("queue is empty");
		return;}
	t=f;
	while(t!=NULL){
		printf("%d\t",t->d);
		t=t->n;}
}
int count(){
	int c=0;
	struct node *t;
	if(f==NULL){
		printf("queue is empty");
		return 0;}
	t=f;
	while(t!=NULL){
		c++;
		t=t->n;}
	return c;
}
void search(int num){
	int p=0;
	struct node *t;
	if(f==NULL){
		printf("queue is empty");
		return;}
	t=f;
	while(t!=NULL){
		if(t->d==num)
		{	printf("element found at %d",p);
			return;}
		p++;
		t=t->n;}
	printf("element not found");	
}
void deletelist(){
	struct node *t;
	if(f==NULL){
		printf("list is empty");
		return;}
	while(f!=NULL){
		t=f;
		f=f->n;
		free(t);
	}
	b=NULL;}
void deletepart(int num){
	struct node *t,*tp;
	t=f;
	while(t!=NULL)
	{
		if(t->d==num)
		{ 	tp=t;
			if(t!=f)
				t->p->n=t->n;
			else
				f=t->n;
			if(t->n==NULL)
				b=t->p;
			else
				t->n->p=t->p;
			t=t->p;
			free(tp);
			return;
		}
		t=t->n;
	}
	printf("element not found");
}
void createlist(int *ip,int num){
	int i;
	struct node *ptr;
	for(i=0;i<num;i++)
	{
		ptr=(struct node*)malloc(1*sizeof(struct node));
		ptr->d=ip[i];
		ptr->n=NULL;
		if(f==NULL)
		{
			f=ptr;
			ptr->p=NULL;}
		else{
			ptr->p=b;
			b->n=ptr;}
		b=ptr;
	}
}

void rev(){
	struct node *c,*nxt,*t;
	if(f==NULL){
		printf("queue is empty");
		exit(1);}
	c=t=f;
	while(c!=NULL){
		nxt=c->n;
		if(c==b)
			f=b;
		t=c->p;
		c->p=c->n;
		c->n=t;
		c=nxt;}
	b=t;

}
void swap_link(int num1,int num2)
{
	int po1=0,po2=0;
	struct node *p1,*p2,*t;
	if(f==NULL)
	{
		printf("list is empty");
		return;}
	if(num1==num2)
		return;
	p1=p2=f;
	while(p1!=NULL){
		if(p1->d==num1)
			break;
		po1++;
		p1=p1->n;}
	while(p2!=NULL){
		if(p2->d==num2)
			break;
		po2++;
		p2=p2->n;}
	if((p1==NULL)||(p2==NULL))
	{
		printf("data not found");
		return;}
	if(po1>po2){
		t=p1;
		p1=p2;
		p2=t;}
	if(p1==f)
		f=p2;
	else
		p1->p->n=p2;
	if(p1->n!=p2)
	{
		p1->n->p=p2;
		p2->p->n=p1;
	}
	else{
		p1->n=p1;
		p2->p=p2;
	}
	if(p2==b)
		b=p1;
	else
		p2->n->p=p1;

	t=p1->p;
	p1->p=p2->p;
	p2->p=t;
	t=p1->n;
	p1->n=p2->n;
	p2->n=t;
}
void sele_sort()
{
	struct node *p1,*p2,*t;
	if(f==NULL){
		printf("queue is empty");
		return;}
	for(p1=f;p1!=NULL;p1=p1->n)
	{
		display();
		printf("\n");
		for(p2=p1->n;p2!=NULL;p2=p2->n)
		{
			if(p1->d>p2->d)
			{
				if(p1==f)
					f=p2;
				else
					p1->p->n=p2;
				if(p1->n==p2)
				{
					p1->n=p1;
					p2->p=p2;}
				else{
					p1->n->p=p2;
					p2->p->n=p1;}
				if(p2->n!=NULL)
					p2->n->p=p1;
				else
					b=p1;
				t=p1->p;
				p1->p=p2->p;
				p2->p=t;
				t=p1->n;
				p1->n=p2->n;
				p2->n=t;
				t=p1;
				p1=p2;
				p2=t;
			}
		}
	}
}

void bubble_sort(){
	struct node *p1,*p2,*e,*t;
	if(f==NULL)
	{
		printf("queue is empty");
		return;}
	for(e=NULL;f->n!=e;e=p1)
	{
		for(p1=f;p1->n!=e;p1=p1->n)
		{
			p2=p1->n;
			if(p1->d>p2->d)
			{
				if(p1==f)
					f=p2;
				else
					p1->p->n=p2;
				if(p2==b)
					b=p2;
				else
					p2->n->p=p1;
				p1->n=p2->n;
				p2->n=p1;
				p2->p=p1->p;
				p1->p=p2;
				t=p1;
				p1=p2;
				p2=t;
			}
		}
	}
}

void main(){
	int num,opt,i,m;
	int *ip;
	while(1){
		printf("\nMenu\n0.exit\n1.insert\n2.delete\n3.display\n4.count\n5.searh\n6.delete list\n7.delete particular node\n8.create list\n9.reverse\n10.selection sort using links\n11.bubble sort using links\n12.swap using links\nenter your choice");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:exit(0);
			case 1:printf("enter a value");
			       scanf("%d",&num);
			       insert(num);
			       break;
			case 2:delete();
			       break;
			case 3:display();
			       break;
			case 4:num=count();
			       if(num)
				       printf("%d elements are present",num);
			       break;
			case 5:printf("enter n value");
			       scanf("%d",&num);
			       search(num);break;
			case 6:deletelist();break;
			case 7:printf("enter a number");
			       scanf("%d",&num);
			       deletepart(num);break;
			case 8:printf("enter size of list");
			       scanf("%d",&num);
			       ip=(int*)malloc(num*sizeof(struct node));
			       if(ip==NULL)
			       {
				       printf("failed to allocate memory");
				       exit(1);
			       }
			       for(i=0;i<num;i++)
				       scanf("%d",ip+i);
			       createlist(ip,num);break;
			case 9:rev();break;
			case 10:sele_sort();break;
			case 11:bubble_sort();break;
			case 12:printf("enter n,m values");
				scanf("%d %d",&num,&m);
				swap_link(num,m);break;
			default:printf("invalid choice");
		}
	}
}




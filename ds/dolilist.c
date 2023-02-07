#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *p;
	int d;
	struct node *n;};
struct node *head=NULL;
void add_at_begin(int n){
	struct node *ptr;
	ptr=(struct node*)malloc(1*sizeof(struct node));
	if(ptr==NULL){
		printf("failed to allocate memory");
		exit(1);}
	ptr->d=n;
	ptr->n=head;
	ptr->p=NULL;
	if(head!=NULL)
		ptr->n->p=ptr;
	head=ptr;}
void delete_at_begin(){
	struct node* t;
	if(head==NULL)
	{
		printf("list is empty");
		return;}
	t=head;
	head=head->n;
	head->p=NULL;
	free(t);}
void display(){
	struct node *t;
	if(head==NULL){
		printf("list is empty");
		return;}
	t=head;
	while(t!=NULL)
	{
		printf("%d\t",t->d);
		t=t->n;}
}
int count(){
	int c=0;
	struct node *t;
	if(head==NULL){
		printf("list is empty");
		return 0;}
	t=head;
	while(t!=NULL)
	{
		c++;
		t=t->n;}
	return c;
}
int search(int n){
	int c=0;
	struct node *t;
	if(head==NULL){
		printf("list is empty");
		return 0;}
	t=head;
	while(t!=NULL)
	{
		if(t->d==n)
			return c;
		c++;
		t=t->n;}
	printf("element not found");
	return 0;
}
void add_at_last(int n)
{
	struct node *ptr,*t;
	ptr=(struct node*)malloc(1*sizeof(struct node));
	if(ptr==NULL){
		printf("failed to allocate memory");
		exit(1);
	}
	ptr->d=n;
	ptr->n=NULL;
	if(head==NULL)
	{
		head=ptr;
		ptr->p=NULL;}
	else{
		t=head;
		while(t->n!=NULL)
			t=t->n;
		t->n=ptr;
		ptr->p=t;
	}
}
void delete_at_last()
{
	struct node *t,*p;
	if(head==NULL){
		printf("list is empty");
		exit(1);}
	while(t->n!=NULL)
	{
		p=t;
		t=t->n;}
	p->n=NULL;
	free(t);
}
void delete_dup(){
	struct node *p1,*p2,*t,*s;
	if(head==NULL){
		printf("list is empty");
		return;}
	for(p1=head;p1!=NULL;p1=p1->n)
	{
		for(p2=p1->n;p2!=NULL;p2=p2->n)
		{
			if(p1->d==p2->d)
			{
				t=p2;
				p2->p->n=p2->n;
				if(p2->n!=NULL)
					(p2->n)->p=p2->p;
				p2=p2->p;
				free(t);}
		}
	}
}
void delete_list(){
	struct node *t;
	if(head==NULL)
	{
		printf("list is empty");
		return;}
	while(head!=NULL){
		t=head;
		head=head->n;
		free(t);}
}
void add_before(int n,int m)
{
	struct node *ptr,*t;
	ptr=(struct node*)malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{
		printf("failed to allocate memory");
		exit(1);}
	ptr->d=m;
	if(head==NULL)
	{
		printf("list is empty");
		return;}
	t=head;
	while(t!=NULL){
		if(t->d==n)
			break;
		t=t->n;}
	if(t==NULL)
	{
		printf("element not found");
		return;}
	if(t==head)
	{
		ptr->n=head;
		ptr->p=NULL;
		head=ptr;}
	else{
		ptr->n=t;
		ptr->p=t->p;
		t->p->n=ptr;
		t->p=ptr;}
}
void add_after(int n,int m)
{
	struct node *ptr,*t;
	ptr=(struct node*)malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{
		printf("failed to allocate memory");
		exit(1);}
	ptr->d=m;
	if(head==NULL)
	{
		printf("list is empty");
		return;}
	t=head;
	while(t!=NULL){
		if(t->d==n)
			break;
		t=t->n;}
	if(t==NULL)
	{
		printf("element not found");
		return;}
	ptr->n=t->n;
	t->n=ptr;
	ptr->p=t;
	if(ptr->n!=NULL)
		ptr->n->p=ptr;
}
void delete_part(int n)
{
	struct node *ptr,*t;
	if(head==NULL)
	{
		printf("list is empty");
		return;}
	if(head->d==n)
	{
		if(head->n==NULL)
		{
			free(head);
			head=NULL;
			return;
		}
	}
	t=head;
	while(t!=NULL){
		if(t->d==n)
			break;
		t=t->n;}
	if(t==NULL)
	{
		printf("element not found");
		return;}
	if(t==head){
		head=head->n;
		head->p=NULL;
		free(t);}
	else{
		t->n->p=t->p;
		t->p->n=t->n;
		free(t);
	}
}
void create_list(int *iptr,int n){
	int i;
	struct node *ptr,*s=NULL,*t;
	for(i=0;i<n;i++){
		ptr=(struct node*)malloc(1*sizeof(struct node));
		if(ptr==NULL)
		{
			printf("failed to allocate memory");
			exit(1);}
		ptr->d=iptr[i];
		if(s==NULL)
		{
			s=ptr;
			ptr->p=NULL;}
		else{
			t->n=ptr;
			ptr->p=t;
		}
		t=ptr;
	}
	if(head==NULL)
		head=s;
	else{
		t=head;
		while(t->n!=NULL)
			t=t->n;
		t->n=s;
		s->p=t;
	}
}
void rev(){
	struct node *c,*nxt,*t;
	if(head==NULL){
		printf("list is empty");
		return;}
	c=head;
	while(c!=NULL)
	{
		nxt=c->n;
		if(nxt==NULL)
			head=c;
		t=c->p;
		c->p=c->n;
		c->n=t;
		c=nxt;
	}

}
void sort_select(){
	struct node *p1,*p2,*t;
	if(head==NULL)
	{
		printf("list is empty");
		return;}
	for(p1=head;p1!=NULL;p1=p1->n)
	{
		for(p2=p1->n;p2!=NULL;p2=p2->n)
		{
			if(p1->d>p2->d)
			{
				if(head==p1)
					head=p2;
				else
					p1->p->n=p2;
				if(p1->n!=p2){
					p2->p->n=p1;
					p1->n->p=p2;}
				else{
					p1->n=p1;
					p2->p=p2;}
				if(p2->n!=NULL)
					p2->n->p=p1;
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

void swap_link(int n,int m){
	int pos1=0,pos2=0;
	struct node *p1,*p2,*t;
	if(n==m)
		return;
	if(head==NULL)
	{
		printf("list is empty");
		return;}
	p1=p2=head;
	while(p1!=NULL){
		if(p1->d==n)
			break;
		pos1++;
		p1=p1->n;}
	while(p2!=NULL){
		if(p2->d==m)
			break;
		pos2++;
		p2=p2->n;}
	if((p1== NULL)||(p2==NULL))
	{
		printf("data not found");
		return;}
	if(pos1>pos2)
	{
		t=p1;
		p1=p2;
		p2=t;}
	if(head==p1)
		head=p2;
	else
		p1->p->n=p2;
	if(p1->n!=p2){
		p2->p->n=p1;
		p1->n->p=p2;}
	else{
		p1->n=p1;
		p2->p=p2;}
	if(p2->n!=NULL)
		p2->n->p=p1;
	t=p1->p;
	p1->p=p2->p;
	p2->p=t;
	t=p1->n;
	p1->n=p2->n;
	p2->n=t;
}
void bubble_sort()
{
	struct node *p1,*p2,*t,*r;
	if(head==NULL)
	{
		printf("list is empty");
		return;}
	for(t=NULL;head->n!=t;t=p2)
	{
		for(p1=head;p1->n!=t;p1=p1->n)
		{
			p2=p1->n;
			if(p1->d>p2->d)
			{
				if(head==p1)
					head=p2;
				else
					p1->p->n=p2;	
				p2->p=p1->p;
				p1->p=p2;
				if(p2->n!=NULL)
					p2->n->p=p1;
				p1->n=p2->n;
				p2->n=p1;
				r=p1;
				p1=p2;
				p2=r;
			}
		}
	}
}



void main(){
	int n,opt,m,i;
	int *p;
	while(1){
		printf("\nMENU\n0.exit\n1.add at begining\n2.delete at begining\n3.display\n4 add at last\n5.delete at last\n6.delete duplicates\n7.count\n8.search element\n9.delete list\n10.add before\n11.add after\n12.delete particular node\n13.create a list\n14.reverse the list\n15.selection sort using link\n16.swap by using link\n17.bubble sort\nenter your choice");
		scanf("%d",&opt);
		switch(opt){
			case 0:exit(0);
			case 1:printf("enter n value");
			       scanf("%d",&n);
			       add_at_begin(n);break;
			case 2:delete_at_begin();break;
			case 3:display();break;
			case 4:printf("enter n value");
			       scanf("%d",&n);
			       add_at_last(n);break;
			case 5:delete_at_last();break;
			case 6:delete_dup();break;
			case 7:n=count();
			       if(n)
				       printf("%d elements are present",n);break;
			case 8:printf("enter search element");
			       scanf("%d",&n);
			       n=search(n);
			       if(n)
				       printf("element found at %d position",n);break;
			case 9:delete_list();break;
			case 10:printf("enter n,m values");
				scanf("%d %d",&n,&m);
				add_before(n,m);
			case 11:printf("enter n,m values");
				scanf("%d %d",&n,&m);
				add_after(n,m);
			case 12:printf("enter n value");
				scanf("%d",&n);
				delete_part(n);break;
			case 13:printf("enter size of list");
				scanf("%d",&n);
				p=(int*)malloc(n*sizeof(int));
				if(p==NULL){
					printf("failed to allocate memory");
					exit(1);}
				for(i=0;i<n;i++)
					scanf("%d",p+i);
				create_list(p,n);
				free(p);break;
			case 14:rev();break;
			case 15:sort_select();break;
			case 16:printf("enter n,m values");
				scanf("%d %d",&n,&m);
				swap_link(n,m);break;
			case 17:bubble_sort();break;
			default :printf("invalid choice");
		}
	}
}



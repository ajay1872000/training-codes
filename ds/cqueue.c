#include<stdio.h>
#include<stdlib.h>
struct node{
	int d;
	struct node *p;
};
struct node *head=NULL;
void add_begin(int n)
{
	struct node *ptr,*t;
	ptr=(struct node*)malloc(1*sizeof(struct node));
	if(ptr==NULL){
		printf("failed to allocate memory");
		exit(1);}
	ptr->d=n;
	if(head==NULL)
	{
		head=ptr;
		ptr->p=ptr;}
	t=head;
	while(t->p!=head)
		t=t->p;
	t->p=ptr;
	ptr->p=head;
	head=ptr;
}
void delete_begin()
{
	struct node *t,*te;
	if(head==NULL){
		printf("list is empty");
		return;}
	t=head;
	while(t->p!=head)
		t=t->p;
	te=head;
	if(t!=head)
		head=head->p;
	else
		head=NULL;
	t->p=head;
	free(te);
}
void display()
{
	struct node *t;
	if(head==NULL){
		printf("list is empty");
		return;}
	t=head;
	do{
		printf("%d\t",t->d);
		t=t->p;}
	while(t!=head);
}
int count()
{
	int c=0;
	struct node *t;
	if(head==NULL){
		printf("list is empty");
		return 0;}
	t=head;
	do{
		c++;
		t=t->p;}
	while(t!=head);
	return c;
}
void search(int n)
{
	int p=0;
	struct node *t;
	if(head==NULL){
		printf("list is empty");
		return;}
	t=head;
	do{
		if(t->d==n)
		{
			printf("element found at %d",p);
			return;}
		p++;
		t=t->p;}
	while(t!=head);
	printf("element not found");
}
void deleteall()
{
	struct node *t,*p;
	if(head==NULL){
		printf("list is empty");
		return;}
	p=head;
	do{
		t=head;
		head=head->p;
		free(t);
	}while(t!=p);
	head=NULL;
}
void add_last(int n)
{
	struct node *t,*ptr;
	ptr=(struct node*)malloc(1*sizeof(struct node));
	if(ptr==NULL){
		printf("failed to allocate memory");
		return;}
	ptr->d=n;
	if(head==NULL){
		ptr->p=ptr;
		head=ptr;
		return;}
	t=head;
	while(t->p!=head)
		t=t->p;
	ptr->p=t->p;
	t->p=ptr;
}
void swap_link(int n,int m)
{
	int f1=0,f2=0;
	struct node *p1,*p2,*t,*pp1,*pp2;
	if(head==NULL){
		printf("list is empty");
		return;}
	if(n==m)
		return;
	p1=p2=head;
	do{
		if(p1->d==n)
		{
			f1=1;
			break;}
		pp1=p1;
		p1=p1->p;
	}
	while(p1!=head);
	do{
		if(p2->d==m)
		{
			f2=1;
			break;}
		pp2=p2;
		p2=p2->p;
	}
	while(p2!=head);
	if((f1==0)&&(f2==0))
	{
		printf("data not found");
		return;}
	if((p1==head)||(p2==head))
	{
		t=head;
		while(t->p!=head)
			t=t->p;
		if(p1==head)
			pp1=t;
		if(p2==head)
			pp2=t;
	}
	if(p1==head)
		head=p2;
	else{if(p2==head)
		head=p1;}
	pp1->p=p2;
	pp2->p=p1;
	t=p1->p;
	p1->p=p2->p;
	p2->p=t;
}
void delete_last(){
	struct node *temp;
	if(head==NULL)
	{
		printf("list is empty");
		return;}
	if(head->p==head){
		free(head);
		head=NULL;}
	temp=head;
	while(temp->p->p!=head)
		temp=temp->p;
	free(temp->p);
	temp->p=head;
}
void selection_sort()
{
	int c=0,c1=0;
	struct node *p1,*p2,*t,*l,*pp1,*pp2;
	if(head==NULL){
		printf("list is empty");
		return;}
	t=head;
	p1=head;
	do{
		
		p2=p1->p;
		pp2=p1;
		display();
		printf("\n");
		do{
			if(p1->d>p2->d)
			{
				if(p1==head)
				{
					l=head;

					while(l->p!=head)
						l=l->p;
					head=p2;	
					l->p=head;
					pp1=l;
				}
				else
					pp1->p=p2;
				pp2->p=p1;
				t=p1->p;
				p1->p=p2->p;
				p2->p=t;
				t=p1;
				p1=p2;
				p2=t;
			}
			pp2=p2;
			p2=p2->p;
		}while(p2!=head);
		pp1=p1;
		p1=p1->p;
	}while(p1->p!=head);
}
void bubble_sort()
{
	struct node *p1,*p2,*e,*t,*l,*s;
	for(e=head;head->p!=e;e=p1)
	{
		for(p1=head;p1->p!=e;s=p1,p1=p1->p)
		{
			p2=p1->p;
			if(p1->d>p2->d)
			{
				if(p1==head)
				{l=head;
					while(l->p!=head)
						l=l->p;
					head=p2;
					l->p=p2;
					e=p2;
				}
				else
					s->p=p2;
				p1->p=p2->p;
				p2->p=p1;
				t=p1;
				p1=p2;
				p2=t;
			}
		}
	}
}
			
void delete_part(int n)
{
	struct node *t,*pt;
	if(head==NULL)
	{	printf("list is empty");
		return;}
	if(head->p=head){
		if(head->d==n){
		free(head);
		head=NULL;}
		return;}
	t=head;
	do{
		if(t->d==n)
		{
			if(t==head){
				pt=head;
				while(pt->p=head)
					pt=pt->p;
				head=head->p;
				free(t);
				pt->p=head;
				return;
			}
			else{
				pt->p=t->p;
				free(t);
				return ;
			}
		}
		pt=t;
		t=t->p;
	}while(t!=head);
}

void main()
{
	int n,opt,m;
	while(1){
		printf("\nMenu\n1.add at begining\n2.delete at begining\n3.display\n4.count no of elements\n5.search\n6.delete all\n7.swap by link\n8.add at last\n9.delete at last\n10.selection sort\n11.bubble sort\n12.delete duplicates\n13.delete particular node\nenter your choice");
		scanf("%d",&opt);
		switch(opt){
			case 0:exit(0);
			case 1:printf("enter a number");
			       scanf("%d",&n);
			       add_begin(n);break;
			case 2:delete_begin();break;
			case 3:display();break;
			case 4:n=count();
			       if(n)
				       printf("%d elements are present",n);
			       break;
			case 5:printf("enter a value");
			       scanf("%d",&n);
			       search(n);break;
			case 6:deleteall();break;
			case 7:printf("enter n,m values");
			       scanf("%d %d",&n,&m);
			       swap_link(n,m);break;
			case 8:printf("enter n value");
			       scanf("%d",&n);
			       add_last(n);
			case 9:delete_last();break;
			case 10:selection_sort();break;
			case 11:bubble_sort();break;
			case 12:printf("enter n value");
				scanf("%d",&n);
			       delete_part(n);break;
			default:printf("invalid choice");
		}
	}
}


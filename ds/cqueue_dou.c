#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *next;
	int data;
	struct node *prev;
};
struct node *head=NULL;
void addatbegin(int num)
{
	struct node *ptr,*t;
	ptr=(struct node*)malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{
		printf("failed to allocate memory");
		exit(1);}
	ptr->data=num;
	if(head==NULL)
		head=ptr->prev=ptr->next=ptr;
	else{
		head->prev->next=ptr;
		ptr->prev=head->prev;
		head->prev=ptr;
		ptr->next=head;
		head=ptr;
	}
}
void deleteatbegin(){
	struct node *t;
	if(head==NULL){
		printf("list is empty");
		return;}
	t=head;
	if(head->next==head)
	{
		free(head);
		head=NULL;
		return;
	}
	if(head->next==head)
	{
		free(head);
		head=NULL;
		return;
	}
	while(t->next!=head)
		t=t->next;
	t->next=head->next;
	t=head;
	head=head->next;
	free(t);
}
void display(){
	struct node *temp;
	if(head==NULL)
	{
		printf("list is empty");
		return;}
	temp=head;
	do{
		printf("%d\t",temp->data);
		temp=temp->next;
	}while(temp!=head);
}
void addlast(int num)
{
	struct node *ptr,*t;
	ptr=(struct node*)malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{
		printf("failed to allocate memory");
		exit(1);}
	ptr->data=num;
	if(head==NULL)
		head=ptr->prev=ptr->next=ptr;
	else{
		t=head->prev;
		ptr->next=head;
		ptr->prev=t;
		t->next=ptr;
	}
}
void deletelast()
{
	struct node *t;
	if(head==NULL)
	{
		printf("list is empty");
		return;}
	if(head->next==head){
		free(head);
		head=NULL;
		return;
	}
	t=head->prev;
	t->prev->next=head;
	head->prev=t->prev;
	free(t);
}
void deleteall(){
	struct node *t,*l;
	if(head==NULL)
	{printf("list is empty");
		return;}
	t=head;
	l=head;
	do{
		t=head;
		head=head->next;
		free(t);
	}while(head!=l);
	head=NULL;
}
void addbefore(int n,int m)
{
	struct node *t,*ptr;
	if(head==NULL){
		printf("list is empty");
		return;}
	ptr=(struct node*)malloc(1*sizeof(struct node));
	if(ptr==NULL){
		printf("failed to allocate memory");
		exit(1);}
	ptr->data=m;
	t=head;
	do{
		if(t->data==n)
		{
			t->prev->next=ptr;
			if(t==head)
				head=ptr;
			ptr->prev=t->prev;
			ptr->next=t;
			t->prev=ptr;
			return;
		}
		t=t->next;
	}while(t!=head);
	printf("data not found");
}
void addafter(int n,int m)
{
	struct node *ptr,*t;
	if(head==NULL)
	{
		printf("list is empty");
		return;}
	ptr=(struct node*)malloc(1*sizeof(struct node));
	if(ptr==NULL){
		printf("failed to allocate memory");
		exit(1);}
	ptr->data=m;
	t=head;
	do{
		if(t->data==n)
		{
			ptr->prev=t;
			ptr->next=t->next;
			ptr->next->prev=ptr;
			t->next=ptr;
			return;
		}
		t=t->next;
	}while(t!=head);
	printf("data not found");
}
void rev()
{
	struct node *t,*cur,*nxt,*temp;
	if(head==NULL){
		printf("list is empty");
		return;}
	cur=t=head;
	do{
		nxt=cur->next;
		temp=cur->prev;
		cur->prev=cur->next;
		cur->next=temp;
		if(nxt==t)
			head=cur;
		
		cur=nxt;
	}while(cur!=t);
}

void selection_sort()
{
	struct node *t,*p1,*p2;
	if(head==NULL)
	{
		printf("list is empty");
		return;
	}
	p1=head;
	do{
		p2=p1->next;
		do{
			if(p1->data>p2->data)
			{
				if(head==p1)
					head=p2;
				p1->prev->next=p2;
				if(p1->next!=p2)
				{
				p1->next->prev=p2;
				p2->prev->next=p1;}
				else{
					p2->prev=p2;
					p1->next=p1;}
				p2->next->prev=p1;
				t=p1->prev;
				p1->prev=p2->prev;
				p2->prev=t;
				t=p1->next;
				p1->next=p2->next;
				p2->next=t;
				t=p1;
				p1=p2;
				p2=t;
			}
			p2=p2->next;
		}while(p2!=head);
		p1=p1->next;
	}while(p1->next!=head);
}
void bubble_sort()
{
	struct node *t,*p1,*p2,*e;
	if(head==NULL)
	{
		printf("list is empty");
		return;}
	for(e=head;head->next!=e;e=p1)
	{
		for(p1=head;p1->next!=e;p1=p1->next)
		{
			p2=p1->next;
			if(p1->data>p2->data)
			{
				if(p1==head)
				{
					head=p2;
					e=head;}
				p1->prev->next=p2;
				p2->next->prev=p1;
				p1->next=p2->next;
				p2->next=p1;
				p2->prev=p1->prev;
				p1->prev=p2;
				t=p1;
				p1=p2;
				p2=t;
			}
		}
	}
}
void swap(int n,int m)
{
	int pos1=0,pos2=0,f1=0,f2=0;
	struct node *p1,*p2,*t;
	if(head==NULL)
	{
		printf("list is empty");
		return;}
	p1=p2=head;
	do{
		if(p1->data==n)
		{
			f1=1;
			break;}
		pos1++;
		p1=p1->next;
	}while(p1!=head);
	do{
		if(p2->data==m)
		{
			f2=1;
			break;}
		pos2++;
		p2=p2->next;
	}while(p2!=head);
	if((f1==0)||(f2==0))
	{
		printf("data not found");
		return;}
	if(pos1>pos2)
	{
		t=p1;
		p1=p2;
		p2=t;}
	if(p1==head)
		head=p2;
	if(p2->next!=p1){
	p1->prev->next=p2;
	p2->next->prev=p1;}
	else{
		p1->prev=p1;
		p2->next=p2;}
	if(p1->next!=p2)
	{
		p1->next->prev=p2;
		p2->prev->next=p1;
	}
	else{
		p1->next=p1;
		p2->prev=p2;}
	t=p1->next;
	p1->next=p2->next;
	p2->next=t;
	t=p1->prev;
	p1->prev=p2->prev;
	p2->prev=t;
}
	                                                                                                                                                                                                                                                                                                 
void main()
{
	int n,opt,m;
	while(1){
		printf("\nMenu\n1.add at begining\n2.delete at begining\n3.display\n4.add at last\n5.delete at last\n6.delete all\n7.add beforenode\n8.add after node\n9.reverse\n10.selection sort\n11.bubble sort\n12.swap using links\nenter your");
		scanf("%d",&opt);
		switch(opt){
			case 0:exit(0);
			case 1:printf("enter a number");
			       scanf("%d",&n);
			       addatbegin(n);break;
			case 2:deleteatbegin();break;
			case 3:display();break;
			case 4:printf("enter a value");
			      scanf("%d",&n); 
			       addlast(n);break;
			case 5:deletelast();break;
			case 6:deleteall();break;
			case 7:printf("enter n,m value");
			       scanf("%d %d",&n,&m);
			       addbefore(n,m);break;
			case 8:printf("enter n,m value");
			       scanf("%d %d",&n,&m);
			       addafter(n,m);break;
			case 9:rev();break;
			case 10:selection_sort();break;
			case 11:bubble_sort();break;
			case 12:printf("enter n,m values");
				scanf("%d %d",&n,&m);
				swap(n,m);break;
		}
	}
}

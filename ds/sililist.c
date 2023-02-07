#include<stdio.h>
#include<stdlib.h>
struct node{
	int d;
	struct node *p;};
struct node *head=NULL;
void addbeg(int n){
	struct node *pt=(struct node*)malloc(1*sizeof(struct node));
	if(pt==NULL)
	{
		printf("failed to allocate memory");
		exit(1);}
	pt->d=n;
	pt->p=head;
	head=pt;
}
void addlast(int n){
	struct node *pt=(struct node*)malloc(1*sizeof(struct node));
	struct node *ptr;
	if(pt==NULL)
	{
		printf("failed to allocate memory");
		exit(1);}
	if(head==NULL)
		head=pt;
	else{
		for(ptr=head;ptr->p!=NULL;ptr=ptr->p);
	ptr->p=pt;}
	pt->d=n;
	pt->p=NULL;
}

void deletebeg(){
	if(head==NULL){
		printf("list is empty");
		return;}
	struct node *pt;
	pt=head;
	head=head->p;
	free(pt);
	printf("node is succesfullydeleted");
}
void display(){
	if(head==NULL)
	{
		printf("list is empty");
		return;}
	struct node *pos=head;
	while(pos!=NULL){
		printf("%d\t",pos->d);
		pos=pos->p;
	}
}
int count(){
	int c=0;
	if(head==NULL)
	{
		printf("list is empty");
		return 0;}
	struct node *pos=head;
	while(pos!=NULL){
		c++;
		pos=pos->p;
	}return c;
}
void search(int n){
	int i=0;
	if(head==NULL)
	{
		printf("list is empty");
		return ;}
	struct node *pos=head;
	while(pos!=NULL){
		if(pos->d==n)
		{
			printf("element found at index %d at %p",i,&pos->d);
			return ;}
		pos=pos->p;
		i++;
	}
	printf("element is not found");
	return;
}
void deleteall(){
	struct node *pt;
	if(head==NULL)
	{
		printf("list is empty");
		return;}
	pt=head;
	while(head!=NULL){
		pt=head;
		head=head->p;
		free(pt);}
	printf("succesfully deleted all elements");
	
}
void deletelast(){
	struct node *ptr,*t;
	if(head==NULL)
	{
		printf("list is empty");
		return;
	}
	else{if(head->p==NULL){
		t=head;
		head=t->p;
		free(t);}
		else{
			for(t=head;t->p!=NULL;ptr=t,t=t->p);
			ptr->p=t->p;
			free(t);}}
}

void deletepartnode(int n)
{struct node *pr,*c;
	if(head==NULL){
		printf("list is empty");
		return;}
	if(head->d==n){
		c=head;
		head=head->p;
		free(c);
		return;
	}
	pr=head;
	c=head->p;
	while(c!=NULL){
		if(c->d==n)
		{
			pr->p=c->p;
			free(c);
			return;
		}
		c=c->p;
	}
	printf("no element found");


}
void addaftnode(int n,int m)
{
	struct node *ptr,*t;
	if(head==NULL)
	{
		printf("list is empty");
		return;
	}
	if(head->d==n){
		ptr=(struct node*)malloc(1*sizeof(struct node));
		if(head->p==NULL){
			if(ptr==NULL)
			{
				printf("failed to allocate memory");
				exit(1);}
			ptr->d=m;
			ptr->p=head->p;
			head->p=ptr;
			return;}
	}
	t=head;
	while(t!=NULL)
	{
		if(t->d==n){
			ptr=(struct node*)malloc(1*sizeof(struct node));
			if(ptr==NULL){
				printf("failed to allocate memory");
				exit(1);
			}
			ptr->d=m;
			ptr->p=t->p;
			t->p=ptr;
		}
		t=t->p;
	}
	printf("element not found");
}


void addbefnode(int n,int m){
	struct node *ptr,*t,*c;
	if(head==NULL){
		printf("list is empty");
		return;}
	if(head->d==n){
		ptr=(struct node*)malloc(1*sizeof(struct node));
		if(ptr==NULL){
			printf("failed to allocate memory");
			exit(1);}
		ptr->d=m;
		ptr->p=head;
		head=ptr;}
	if(head->p==NULL)
		return;
	c=NULL;
	t=head;
	while(t!=NULL){
		if((t)->d==n)
		{
			ptr=(struct node*)malloc(1*sizeof(struct node));
			if(ptr==NULL)
			{
				printf("failed to allocate memory");
				exit(1);
			}
			ptr->d=m;
			ptr->p=t;
			c->p=ptr;}
		c=t;
		t=t->p;
	}
}
void rev()
{
	struct node *c,*pr,*n;
	if(head==NULL){
		printf("list is empty");
		return;}
	pr=NULL;
	c=head;
	while(c!=NULL){
		n=c->p;
		c->p=pr;
		pr=c;
		c=n;
	}
	head=pr;
}
void sort_sel_data(){
	struct node *n1,*n2;
	int t;
	if(head==NULL){
		printf("list is empty");
		return;}
	n1=head;
	while(n1!=NULL)
	{
		n2=n1->p;
		while(n2!=NULL){
			if(n1->d>n2->d){
				t=n2->d;
				n2->d=n1->d;
				n1->d=t;}
			n2=n2->p;
		}
		n1=n1->p;
	}
}
void swap_link(int n,int m){
	struct node *pt,*r,*q,*s,*t1;
	if(head==NULL){
		printf("list is empty");
		return;}
	if(n==m)
		return;
	pt=q=head;
	r=s=NULL;
	while(pt!=NULL){
		if(pt->d==n)
			break;
		r=pt;
		pt=pt->p;}
	while(q!=NULL){
		if(q->d==m)
			break;
		s=q;
		q=q->p;}
	if((pt==NULL)||(q==NULL)){
		printf("data not found");
		return;}
	if(pt==head){
		head=q;
		s->p=pt;}
	else{
		if(q==head){
			head=pt;
			r->p=q;}
		else{
			r->p=q;
			s->p=pt;}}
	t1=pt->p;
	pt->p=q->p;
	q->p=t1;

}
void swap_data(int n,int m){
	struct node *pt,*r,*q,*s;
	int t;
	if(head==NULL){
		printf("list is empty");
		return;}
	if(n==m)
		return;
	pt=q=head;
	r=s=NULL;
	while(pt!=NULL){
		if(pt->d==n)
			break;
		r=pt;
		pt=pt->p;}
	while(q!=NULL){
		if(q->d==m)
			break;
		s=q;
		q=q->p;}
	t=q->d;
	q->d=pt->d;
	pt->d=t;
}
void createlist(int *a,int n)
{
	struct node  *start=NULL,*ptr=NULL,*pre=NULL;
	int i;
	for(i=0;i<n;i++){
		ptr=(struct node*)malloc(1*sizeof(struct node));
		if(ptr==NULL){
			printf("failed to allocate memory");
			exit(1);}
		ptr->d=a[i];
		if(start==NULL)
			start=ptr;
		else
			pre->p=ptr;
		pre=ptr;
	}
	pre->p=NULL;
	if(head==NULL)
		head=start;
	else{
		pre=head;
		while(pre->p!=NULL)
			pre=pre->p;
		pre->p=start;}
}
void delete_dup(){
	struct node *p1,*pp,*p2;
	if(head==NULL){
		printf("queue is empty");
		return;}
	for(p1=head;p1!=NULL;p1=p1->p)
	{
		for(pp=p1,p2=p1->p;p2!=NULL;pp=p2,p2=p2->p)
		{
			if(p1->d==p2->d)
			{
				pp->p=p2->p;
				free(p2);
				p2=pp;}
		}
	}
}
void selection_sort_link(){
	struct  node *p1,*p2,*s,*r,*t;
	if(head==NULL){
		printf("list is empty");
		return;}
	if(head->p==NULL)
		return;
	p1=head;
	while(p1!=NULL){
		p2=p1->p;
		s=p1;
		while(p2!=NULL){
			if(p1->d>p2->d){
				if(p1==head)
					head=p2;
				else
					r->p=p2;
				s->p=p1;
				t=p1->p;
				p1->p=p2->p;
				p2->p=t;
				t=p1;
				p1=p2;
				p2=t;
			}
			s=p2;
			p2=p2->p;
		}
		r=p1;
		p1=p1->p;}
}
void bubble_sort_link(){
	struct  node *p1,*p2,*e=NULL,*r,*t;
	if(head==NULL){
		printf("list is empty");
		return;}
	if(head->p==NULL)
		return;
	while(head!=e){
		r=p1=head;
		while(p1->p!=NULL){
			p2=p1->p;
			if(p1->d>p2->d){
				p1->p=p2->p;
				p2->p=p1;
				if(p1==head)
					head=p2;
				else
					r->p=p2;
				t=p1;
				p1=p2;
				p2=t;
			}
			r=p1;
			p1=p1->p;
		}
		e=p1;
	}
}

void main()
{
	int n,m,opt,i;
	int *ptr;
	while(1){
		printf("\nMenu\n--------------------------------------------------------------------------------------------------------------------------\n0.exit\n1.add at begining\n2.delete at begining\n3.display\n4.search\n5.no of elements present\n6.delete all\n7.add at last\n8.delete at last\n9.delete particular node\n10.add after node\n11 add befor node\n12 reverse the list\n13 selection sort using data\n14.swap using link\n15.create a list\n16.swap using data\n17.delete duplicates\n18.selection sort using link\n19.selection sort using data\n19.bubble sort using data\n20.bubble sort using data");
		scanf("%d",&opt);
		switch(opt){
			case 0:deleteall();
			       exit(0);
			case 1:printf("enter a number");
			       scanf("%d",&n);
			       addbeg(n);break;
			case 2:deletebeg();
			       break;
			case 3:display();
			       break;
			case 5:n=count();
			       if(n)
				       printf("%d elements are present in list",n);
			       break;
			case 4:printf("enter search element");
			       scanf("%d",&n);
			       search(n);break;
			case 6:deleteall();break;
			case 7:printf("enter a number");
			       scanf("%d",&n);
			       addlast(n);break;
			case 8:deletelast();break;
			case 9:printf("enter a value");
			       scanf("%d,%d",&n,&m);
			       deletepartnode(n);break;
			case 10:printf("enter inputs");
				scanf("%d%d",&n,&m);
				printf("%d %d\n",n,m);
				addaftnode(n,m);
				break;
			case 11:printf("enter inputs");
				scanf("%d%d",&n,&m);
				printf("%d %d\n",n,m);
				addbefnode(n,m);break;
			case 12:rev();
				break;
			case 13:sort_sel_data();
				break;
			case 14:printf("enter inputs");
				scanf("%d%d",&n,&m);
				swap_link(n,m);break;
			case 15:printf("enter size of list");
				scanf("%d",&n);
				ptr=(int*)malloc(n*sizeof(int));
				if(ptr==NULL){
					printf("failed to allocate memory");
					exit(1);}
				for(i=0;i<n;i++)
					scanf("%d",ptr+i);
				createlist(ptr,n);
				free(ptr);break;
			case 16:printf("enter inputs");
				scanf("%d%d",&n,&m);
				swap_data(n,m);break;
			case 17:delete_dup();break;
			case 18:selection_sort_link();break;
			case 19:bubble_sort_link();break;
			default:printf("invalid case");
		}
	}
}

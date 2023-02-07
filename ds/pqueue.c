#include<stdio.h>
#include<stdlib.h>
struct priqueue{
	struct priqueue *n,*p;
	int pi,d;};
struct priqueue *f=NULL;
void insert(int pv,int n){
	struct priqueue *ptr,*t,*p;
	ptr=(struct priqueue*)malloc(1*sizeof(struct priqueue));
	ptr->d=n;
	ptr->pi=pv;
	if(f==NULL){
		f=ptr;
		ptr->n=NULL;
		ptr->p=NULL;
		return;
	}
	t=f;
	while(t!=NULL){
		if(t->pi>pv)
		{
			ptr->n=t;
			ptr->p=t->p;
			t->p=ptr;
			if(f==t)
				f=ptr;
			else
				ptr->p->n=ptr;
			return;
		}
		p=t;
		t=t->n;
	}
	p->n=ptr;
	ptr->n=NULL;
	ptr->p=p;
}
void delete(int pv)
{
	struct priqueue *t;
	if(f==NULL){
		printf("queue empty");
		return;}
	t=f;
	while(t!=NULL){
		if(t->pi==pv)
			break;
		t=t->n;}
	if(t==NULL){
		printf("priority not found");
		return;}
	if(t==f)
		f=t->n;
	else
		t->p->n=t->n;
	if(t->n!=NULL)
		t->n->p=t->p;
	free(t);
}
void display(){
	struct priqueue *t;
	if(f==NULL)
	{
		printf("queue is empty");
		return;}
	t=f;
	while(t!=NULL){
		printf("%d-%d\t",t->pi,t->d);
		t=t->n;}
}
void display_pri(int pri){
	int c=0;
	struct priqueue *t;
	if(f==NULL)
	{
		printf("queue is empty");
		return;}
	t=f;
	while(t!=NULL){
		if(t->pi==pri){
			printf("%d-%d\t",t->pi,t->d);
			c++;}
		t=t->n;}
	if(c==0)
		printf("priority elements not found");
}
void search_pri(int pri){
	int c=0;
	struct priqueue *t;
	if(f==NULL)
	{
		printf("queue is empty");
		return;}
	t=f;
	while(t!=NULL){
		if(t->pi==pri){
			c++;}
		t=t->n;}
	if(c==0)
		printf("priority elements not found");
	else
		printf("%d elements are present of priority %d",c,pri);
}
void delete_pri(int pri){
	int c=0;
	struct priqueue *t,*p;
	if(f==NULL)
	{
		printf("queue is empty");
		return;}
	t=f;
	while(t!=NULL){
		if(t->pi==pri){
			c++;
			if(f==t){
				f=f->n;
				free(t);
				t=f;
				t->p=NULL;
				continue;
			}
			else{
				p=t;
				t->p->n=t->n;
				if(t->n!=NULL)
					t->n->p=t->p;
				t=t->p;
				free(p);
				}
			}
			t=t->n;
		}
	if(c==0)
		printf("priority elements not found");
}
void search(int pri,int n){
	int c=0;
	struct priqueue *t;
	if(f==NULL)
	{
		printf("queue is empty");
		return;}
	t=f;
	while(t!=NULL){
		if((t->pi==pri)&&(t->d==n)){
			printf("element found at %d",c);
			return;
		}
		c++;
		t=t->n;}
	printf("element not found");
}
void delete_part(int pri,int n){
	struct priqueue *t;
	if(f==NULL)
	{
		printf("queue is empty");
		return;}
	t=f;
	while(t!=NULL){
		if((t->pi==pri)&&(t->d==n)){
			if(t!=f)
				t->p->n=t->n;
			else
				f=NULL;
			free(t);
			return;
		}
		t=t->n;}
	printf("element not found");
}
void createlist(int num,int *pr,int *da){
	int i,pv;
	struct priqueue *ptr,*t,*p;
	for(i=0;i<num;i++)
	{
		ptr=(struct priqueue*)malloc(1*sizeof(struct priqueue));
		ptr->d=da[i];
		ptr->pi=pr[i];
		if(f==NULL){
			f=ptr;
			ptr->n=NULL;
			ptr->p=NULL;
			continue;
		}

		t=f;
		while(t!=NULL){
			if(t->pi>pr[i])
			{
				ptr->n=t;
				ptr->p=t->p;
				t->p=ptr;
				if(f==t)
					f=ptr;
				else
					ptr->p->n=ptr;
				break;
			}
			p=t;
			t=t->n;
		}
		if(t==NULL){
		p->n=ptr;
		ptr->n=NULL;
		ptr->p=p;}
	}
}
void deleteall()
{
	struct priqueue *t;
	if(f==NULL)
	{
		printf("list is empty");
		return;}
	while(f!=NULL)
	{
		t=f;
		f=f->n;
		free(t);}
}
void sort(){
	struct priqueue *p1,*p2,*t;
	if(f==NULL){
		printf("queue is empty");
		return;}
	for(p1=f;p1!=NULL;p1=p1->n)
	{
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
void sort_p(){
	struct priqueue *p1,*p2,*t;
	if(f==NULL){
		printf("queue is empty");
		return;}
	for(p1=f;p1!=NULL;p1=p1->n)
	{
		for(p2=p1->n;p2!=NULL;p2=p2->n)
		{
			if(p1->pi!=p2->pi)
				break;
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
void rev_p(){
	int p;
	struct priqueue *cur,*next,*padd,*temp,*st,*ed,*pr,*t;
	if(f==NULL){
		printf("queue is empty");
		return;}
	cur=f;
	st=f;
		p=cur->pi;
	while(cur!=NULL)
	{
		while(cur!=NULL){
			if(p!=cur->pi)
				break;
			pr=cur;
			cur=cur->n;}

			ed=pr;
			if(st==f)
				t=pr;
			for(st,ed;st!=ed;st=st->n,ed=ed->p)
			{
				if(st->p!=NULL)
					st->p->n=ed;
				if(st->n!=ed)
				{
					st->n->p=ed;
					ed->p->n=st;}
				else{
					st->n=st;
					ed->p=ed;}
				if(ed->n!=NULL)
					ed->n->p=st;
				temp=st->p;
				st->p=ed->p;
				ed->p=temp;
				temp=st->n;
				st->n=ed->n;
				ed->n=temp;
				temp=st;
				st=ed;
				ed=temp;
			}
		if(cur!=NULL)
			p=cur->pi;
		st=cur;
	}
	f=t;

}
void main(){
	int n,pv,opt,i;
	int *p,*d;
	while(1){
		printf("\nMenu\n1.insert\n2.delete\n3.display\n4.create list\n5.display the nodes of particular priority\n6.delete all\n7.search based on priorityi\n8.search a element\n9.delete particular node\n10.delete particular prority elements\n11.sorting\n12.sorting base on priority\n13.reverse based on priority\nenter your choice");
		scanf("%d",&opt);
		switch(opt){
			case 0:exit(0);
			case 1:printf("enter priority");
			       scanf("%d",&pv);
			       printf("enter a number");
			       scanf("%d",&n);
			       insert(pv,n);break;
			case 2:printf("enter priority");
			       scanf("%d",&pv);
			       delete(pv);break;
			case 3:display();break;
			case 4:printf("enter size of list");
			       scanf("%d",&n);
			       p=(int*)malloc(n*sizeof(int));
			       d=(int*)malloc(n*sizeof(int));
			       if((p==NULL)||(d==NULL)){
				       printf("failed to allocate memory");
				       exit(1);}
			       for(i=0;i<n;i++){
				       printf("enter p:v");
				       scanf("%d %d",(p+i),(d+i));}
			       createlist(n,p,d);break;
			case 5:printf("enter a value");
			       scanf("%d",&n);
			       display_pri(n);break;
			case 6:deleteall();break;
			case 7:printf("enter priority value");
			       scanf("%d",&pv);
			       search_pri(pv);break;
			case 8:printf("enter node data and priority");
			       scanf("%d %d",&pv,&n);
			       search(pv,n);break;
			case 9:printf("enter node data and priority");
			       scanf("%d %d",&pv,&n);
			       delete_part(pv,n);break;
			case 10:printf("enter a value");
				scanf("%d",&pv);
				delete_pri(pv);break;
			case 11:sort();break;
			case 12:sort_p();break;
			case 13:rev_p();break;
			default:printf("invalid choice");
		}
	}
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct book{
	char name[32];
	int nop;
	float price;};

struct book* memalloc(){
	struct book* b=(struct book*)malloc(1*sizeof(struct book));
	if(b==NULL){
		printf("failed to allocate memory");
		exit(1);
	}
	return b;
}
void read(struct book *p){
	scanf("%s",p->name);
	__fpurge(stdin);
	scanf("%d",&p->nop);
	__fpurge(stdin);
	scanf("%f",&p->price);
	__fpurge(stdin);
}
void display(struct book *p){
	printf("%s\n",p->name);
	printf("%d\n",p->nop);
	printf("%f\n",p->price);
}
void swap(struct book *b1,struct book *b2)
{
	struct book t;
	t.nop=b1->nop;
	b1->nop=b2->nop;
	b2->nop=t.nop;
	strcpy(t.name,b1->name);
	strcpy(b1->name,b2->name);
	strcpy(b2->name,t.name);
	t.price=b1->price;
	b1->price=b2->price;
	b2->price=t.price;
}
void dealloc(struct book *b){
	free(b);
}
void main(){
	struct book *b1,*b2;
	b1=memalloc();
	b2=memalloc();
	read(b1);
	read(b2);
	display(b1);
	display(b2);
	swap(b1,b2);
	display(b1);
	display(b2);
	dealloc(b1);
	dealloc(b2);
}

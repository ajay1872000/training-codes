#include<stdlib.h>
#include<stdio.h>

struct node{
	int d;
	struct node *l;
};
extern struct node *sp;

void swap_data(int n,int m){
	int t;
	struct node *p1,*p2;
	p1=p2=sp;
	if(sp==NULL)
	{
		printf("list is empty");
		return;}
	if(n==m)
		return;
	while(p1!=NULL){
		if(p1->d==n)
			break;
		p1=p1->l;}
	while(p2!=NULL){
		if(p2->d==m)
			break;
		p2=p2->l;}
	if((p1==NULL)||(p2==NULL)){
		printf("data not found");
		return;}
	t=p1->d;
	p1->d=p2->d;
	p2->d=t;
}

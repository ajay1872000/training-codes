#include<stdio.h>
struct node{
int d;
struct node *l;};
extern struct node *sp;
void search(int n){
	int po=0;
	struct node *p=NULL;
	if(sp==NULL){
		printf("stack is empty");
		return;}
	p=sp;
	while(p!=NULL){
		po++;
		if(p->d==n){
		printf("element fount at %d,%p",po,p);
		return;}
		p=p->l;}
	printf("element not found");
}


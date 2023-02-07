#include<stdlib.h>
#include<stdio.h>

struct node{
	int d;
	struct node *l;
};
extern struct node *sp;
void rev(){
	struct node *n,*c,*p;
	c=sp;
	p=NULL;
	while(c!=NULL){
		n=c->l;
		c->l=p;
		p=c;
		c=n;}
	sp=p;
}

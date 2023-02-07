#include<stdio.h>
struct node {
	int a;
	struct node *p;};
void main(){
	struct node n1;
	n1.p=&n1;
	scanf("%d,%d",&n1.a);
	printf("%d,%d",n1.a,n1.p->a);
	printf("%d",sizeof(n1));
}


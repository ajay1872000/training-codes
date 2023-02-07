#include<stdio.h>
#include<stdlib.h>
struct node{
        int d;
        struct node *l;
};
extern struct node *sp;
void push(int n)
{ struct node *p;
        p=(struct node*)malloc(1*sizeof(struct node));
        if(p==NULL){
                printf("failed to allocate memory");
                exit(1);
        }
        p->d=n;
        p->l=sp;
        sp=p;
}


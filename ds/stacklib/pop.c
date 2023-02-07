#include<stdio.h>
#include<stdlib.h>
struct node{
        int d;
        struct node *l;
};
extern struct node *sp; 
void pop(){
        struct node *p;
        p=sp;
        sp=sp->l;
        free(p);
}


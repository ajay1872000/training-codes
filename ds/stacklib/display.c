#include<stdlib.h>
#include<stdio.h>
struct node{
        int d;
        struct node *l;
};
extern struct node *sp;
void display(){
        struct node *p=NULL;
        if(sp==NULL){
                printf("stack is empty");
                return;}
        p=sp;
        while(p!=NULL){
                printf("%d\t",p->d);
                p=p->l;}
}


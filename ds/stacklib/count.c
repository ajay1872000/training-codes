#include<stdlib.h>
#include<stdio.h>
struct node{
        int d;
        struct node *l;
};
extern struct node *sp;
int count(){
        int c=0;
        struct node *p=NULL;
        if(sp==NULL){
                printf("stack is empty");
                return 0;}
        p=sp;
        while(p!=NULL){
                c++;
                p=p->l;}
        return c;
}


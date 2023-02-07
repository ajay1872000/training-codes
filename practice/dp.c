#include<stdio.h>
void main(){
	int x=10;
	int* ptr=&x;
	int** dptr=&ptr;
	printf("%p\n",ptr);
	printf("%d\n",*ptr);
	printf("%d\n",x);
	printf("%d\n",*ptr);
	printf("%p\n",*dptr);
	printf("%p\n",ptr);
	printf("%d\n",**dptr);
	printf("%d\n",x);
	printf("%p",dptr);}

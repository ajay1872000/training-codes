#include<stdio.h>
void main(){
	int x=10;
	int *const ptr=&x;
	*ptr=20;
	printf("%d",*ptr);
	int y=30;
	//ptr=&y we cannot modify the address in constant address pointer
	printf("%d",*ptr);}

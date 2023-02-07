// excution of C statements in a single line using comma operator
#include<stdio.h>
void main(){
	int a,b,c;
	c=printf("v1"),a=5,printf("v2"),b=7,printf("v3"),c=a+b,printf("v4"),a=c+b;
	printf("\nc=%d",c);
}


#include<stdio.h>
void swap(int,int);
void main(){
	int a=10,b=20;
	printf("main a=%p-%d\n",&a,a);
	printf("main b=%p-%d\n",&b,b);
	swap(a,b);
	printf("main a=%p-%d\n",&a,a);
	printf("main b=%p-%d\n",&b,b);
}
void swap(int a,int b){
	int t;

	printf("swap a=%p-%d\n",&a,a);
	printf("swap b=%p-%d\n",&b,b);
	t=a;
	a=b;
	b=t;
	printf("swap a=%p-%d\n",&a,a);
	printf("swap b=%p-%d\n",&b,b);
}



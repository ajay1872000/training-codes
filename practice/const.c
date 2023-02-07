// to understand about constant keyword in constant datatype
#include<stdio.h>
void main(){
	const char x=10;
	char y=20;
	printf("%d\n",x);
//	x=20; it shows compilation error in constant data we cannot modify the data
	char* ptr=&x;
	*ptr=40;// we can modify through dereferencing the address
	printf("%d\n",x);

	
}

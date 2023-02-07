// to understand about constant keyword in constant datatype
#include<stdio.h>
void main(){
	int x=10;
	int const *ptr=&x;
	printf("%d\n",*ptr);
//	*ptr=20; it shows compilation error in constant data through dereferencing pointer we cannot modify the data
	x=40;// we can modify through dereferencing the address
	printf("%d\n",*ptr);

	
}

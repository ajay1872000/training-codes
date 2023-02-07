#include<stdio.h>
void main(){
	void* ptr1=0x5000;
	void* ptr2=0x5008;
	printf("%d",ptr2-ptr1);
}

#include<stdio.h>
void main(){
	int  a;
	scanf("%d",&a);
	if((a&0x1)==0)
		printf("Even number");
	else
		printf("odd number");
	
}

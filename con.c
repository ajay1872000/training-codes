#include<stdio.h>
void main(){
	int a=5;
	float b=2.45;
	printf("%d",a+(int)b);
	printf("\n%f",a+b);
	printf("\n%ld",a+b);
	printf("\n%d",a+b);
	printf("\n%lf",a+b);
	unsigned int x=0xAABBCCDD;
	unsigned int y=0x00000000;
	y=(char)x;
	printf("\n%x\n",y);
	y=x;
	printf("%x",y);
}

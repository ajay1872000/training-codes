#include<stdio.h>
#include<endian.h>
void main(){
	int a;
	printf("enter a value");
	scanf("%x",&a);
	int y=(a&0xff);
	printf("%x",a);
	if(y==(a&0xff))
		printf("little endian");
	else
		printf("big endian");

	}

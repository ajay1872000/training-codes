#include<stdio.h>
	void main()
	{
		unsigned int a;
	printf("enter a value");
	scanf("%x",&a);
	printf("%x",a&0xff);
	printf("\n%x",(a>>8)&0xff);
	printf("\n%x",(a>>16)&0xff);
	printf("\n%x",(a>>24)&0xff);
	}



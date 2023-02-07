
#include<stdio.h>
void main(){
	unsigned int x,y,z,a,b;
	printf("enter x value");
	scanf("%x",&x);
	printf("enter swap places big,small");
	scanf("%d,%d",&a,&b);
	((a>=0)&&(a<=31))?0:(printf("invalid"),exit(0));
	((b>=0)&&(b<=31))?0:(printf("invalid"),exit(0));
	(b>a)?(a=a+b,b=a-b,a=a-b):0;
	y=x&(0x1<<b);
	y=y<<(a-b);
	z=x&(0x1<<a);
	z=z>>(a-b);
	x=((x&(~(0x1<<a)))&(~(0x1<<b)));
	x=x|y|z;
	printf("%x",x);
}

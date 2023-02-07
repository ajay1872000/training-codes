#include<stdio.h>
void main(){
	int a,i,c,b;
	scanf("%d",&a);
	for(i=0;i<=16;i++){
		b=(a&(0x1<<i))<<(31-2*i);
		c=(a&(0x1<<(31-i)))>>(31-(2*i));
		a=(a&(~((0x1<<i)|(0x1<<(31-i)))));
		a=a|b|c;
	}
	printf("%d",a);
}



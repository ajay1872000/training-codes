#include<stdio.h>
void replace(int n)
{
	int i,j;
	for(i=0;i<32;i=i+4)
		if(((n>>i)&0xff)==0x34)
			n=n|(0x77<<i);
	printf("%x",n);
}
void main()
{
	int n;
	printf("enter n value");
	scanf("%x",&n);
	replace(n);
}

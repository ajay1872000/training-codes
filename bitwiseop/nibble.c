#include<stdio.h>
void nibbleswap(unsigned int n)
{
 int i,j;
	for(i=0,j=16;j<32;i=i+4,j=j+4)
		n=(n&~(0xf<<i|0xf<<j))|(n&0xf<<i)<<(j-i)|(n&0xf<<j)>>(j-i);
		printf("%x",n);
}
void main()
{
       	int n;
	printf("enter n value");
	scanf("%x",&n);
	nibbleswap(n);
}

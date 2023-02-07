#include<stdio.h>
void bin(int,int);
void main(){
	int n;
	printf("enter n value");
	scanf("%d",&n);
	bin(n,31);
}
void bin(int n,int i)
{
	if(i>=0)
	{
	printf("%d",(n>>i)&0x1);
	bin(n,i-1);
		return;}
}


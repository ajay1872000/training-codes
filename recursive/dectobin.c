#include<stdio.h>
int dectobin(int);
void main()
{
	int n,bin;
	printf("enter n value");
	scanf("%d",&n);
	dectobin(n);
	bin=dectobin(n);
	printf("\n binary =%d",bin);
}
int dectobin(int n)
{
	int bin;
	if(n<=0)
		return 0;
	bin=(n%2)+(10*dectobin(n/2));
	return bin;
}


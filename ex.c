#include<stdio.h>
void main()
{
	int r;
	r=printf("welcome");
	printf("return value=%d\n",r);
	r=printf("hi \t \v hello \r hyderabad\n");
	printf("output \b%d",r);
}

#include<stdio.h>
void main()
{
	char a;
	scanf("%c",&a);
	if((a<=90)&&(a>=65))
		printf("%c",a+32);
	else if((a>=97)&&(a<=122))
		printf("%c",a-32);
	else
		printf("%c",a);
}

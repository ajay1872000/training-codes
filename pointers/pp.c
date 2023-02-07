#include<stdio.h>
void main(){
	int a=0x41424344;
	char *p=&a;
	printf("%c\n",(p[3]));
	printf("%c\n",(2[p]));
	printf("%c\n",*(p+1));
	printf("%c\n",*(0+p));
}

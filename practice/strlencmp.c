#include<stdio.h>
#include<string.h>
void main(){
	char a[5]="ajay",b[10]="ajaynaga";
	unsigned int la=5;
	unsigned int lb=9;
	printf("%d,,,,%u",la-lb,la-lb);
	if((int)(strlen(a)-strlen(b))>=0)
		printf("%s",a);
	else
		printf("%s",b);
}


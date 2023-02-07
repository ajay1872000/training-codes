#include<stdio.h>
void main(){
	int a,b;
	scanf("%d",&a);
	b=a++;
	printf("%d,%d",a,b);
	b=++a;
	printf("%d,%d",a,b);
	b=a--;
	printf("%d,%d",a,b);
	b=--a;
	printf("%d,%d",a,b);


}

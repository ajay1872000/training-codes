#include<stdio.h>
void main(){
	int a,b;
	printf("enter a,b values");
	scanf("%d,%d",&a,&b);
	if(a^b)
		printf("not equal");
	else
		printf("equal");
	
}

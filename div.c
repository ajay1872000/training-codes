#include<stdio.h>
void main(){
	int a;
	printf("enter a value");
	scanf("%d",&a);	
	if((a%3)||(a%5))
		printf("%d is not divisible",a);
	else
		printf("%d is  divisible",a);

}

/* to print 5 divisibles for a range a to b*/
#include<stdio.h>
void main(){
	int a,b;
	scanf("%d,%d",&a,&b);
	while(a<=b){
		if(a%5==0)
			printf("%d",a);
		a=5-(a%5)+a;
	}}


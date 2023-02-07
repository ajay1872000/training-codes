#include<stdio.h>
void main(){
	char a,i;
	scanf("%d",&a);
	for(i=0;i<8;i++){
		if((a&(0x1<<i))==0)
			printf("Even number");
		else
			printf("odd number");
	}
}

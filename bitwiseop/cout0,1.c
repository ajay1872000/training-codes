#include<stdio.h>
void main(){
	int a,i=0,o=0,z=0;
	scanf("%d",&a);
	while(i<32){
		if((a&(0x1<<i))==0)
			z++;
		else
			o++;
	        i++;
	}
	printf("c1=%d,c0=%d",o,z);
}

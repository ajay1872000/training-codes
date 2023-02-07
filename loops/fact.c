#include<stdio.h>
void main(){
	int min,max,i,f=1;
	printf("enter min&max values");
	scanf("%d,%d",&min,&max);
	(min>max)?(min=min+max,max=min-max,min=min-max):0;
	
	for(;min<=max;min++){
		f=1;
		for(i=min;i>0;i--)
		f=f*i;
	printf("%d!=%d\n",min,f);}

#include<stdio.h>
void main(){
	int  a,c=0,i;
	scanf("%d",&a);
	for(i=32;i>=3;i--)
	{
		if(((a>>(i-3))&(0x7))==0x5){
			c++;
		}
	}
	printf("%d",c);
}

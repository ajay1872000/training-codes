#include<stdio.h>
void main(){
	int  a,i;
	scanf("%d",&a);
	for(i=32;i>=3;i--)
	{
		if(((a>>(i-3))&(0x7))==0x5){
			a=(a&(~(0x7<<(i-3))))|(0x6<<(i-3));
		}
	}
	printf("%d",a);
}

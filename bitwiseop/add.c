#include<stdio.h>
int add(int x,int y){
	int a,i,b,c=0,r,res=0;
	for(i=0;i<32;i++){
		a=(x>>i)&0x1;
		b=(y>>i)&0x1;
		if((a||b)&&c)
		{
			r=(a^b)^c;
			c=1;
		}
		else{if(a&&b){
			r=a^b;
			c=1;}
			else{
				r=a|b|c;
				c=0;}
		}
	
		res=(r<<i)|res;
	}
	return res;
}
void main(){
	int a,b,c;
	printf("enter two values");
	scanf("%d,%d",&a,&b);
	c=add(a,b);
	printf("%d",c);}


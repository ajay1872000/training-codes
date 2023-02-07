#include<stdio.h>
int sub(int x,int y)
{int a,b,r,c=0,re=0,i;
	for(i=0;i<=31;i++)
	{
		a=(x>>i)&0x1;
		b=(y>>i)&0x1;
		if((a==0)&&b)
		{
			if(((x>>(i+1))&0x1)==1)
			{
				x=x&(~(0x1<<(i+1)));
				r=b^c;
				c=0;
			}
			else
			{
				r=b^c;
				c=1;

			}
		}
		else{

			if(c)
			{
				r=1;
				c=1;}
			else{
				r=a^b;
				c=0;}
		}
	printf("a=%d,b=%d,r=%d,c=%d\n",a,b,r,c);
		re=re|(r<<i);
	}
	return re;}





void main(){
	int a,b,c;
	printf("enter a,b values");
	scanf("%d,%d",&a,&b);
	c=sub(a,b);
	printf("%d",c);
}


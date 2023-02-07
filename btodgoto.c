#include<stdio.h>
void main()
{
	int a,i,min,max,s,r,b;
	printf("enter min and max values");
	scanf("%d,%d",&min,&max);
	(min>max)?(min=min+max,max=min-max,min=min-max):0;
	a=min;
	b=max;
    l: if(((a%10)>1)||((b%10)>1))
		{	
		printf("invalid inputs");
		
			goto j;
		}
		a=a/10;
		b=b/10;
	if(b>0)
		goto l;	
k:	s=0;
	i=1;
	a=min;
z:	r=a%10;
	if(r>1){
		min++;
		goto k;}
	s=s+r*i;
	i=i*2;
	a=a/10;
	if(a!=0)
		goto z;

	printf("%d-%d\n",min,s);
	min++;
	if(min<=max)
		goto k;	
j:;
}

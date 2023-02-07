#include<stdio.h>
#define S 10
void main(){
	int i,a[10],l,k=0,l1;
	for(i=0;i<10;i++)
	{	scanf("%d",&a[i]);}
	l=a[0];
	for(i=1;i<10;i++)
	{	if(l>a[i])
			l=a[i];}
	l1=l;
	for(l;l<=(10+l1);l++)
	{
		k=0;
		for(i=0;i<10;i++)
		{
			if(l==a[i])
				{k=1;
					break;}
		}
		if(k==0)
			printf("%d is missing",l);
	}
}

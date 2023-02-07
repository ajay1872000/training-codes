#include<stdio.h>
#define s 10
void main(){
	int t,i,j,a[s];
	for(i=0;i<s;i++)
		scanf("%d",&a[i]);
	for(i=0;i<s;i++)
	{
		for(j=0;j<s-1;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	for(i=0;i<s;i++)
		printf("%d\t",a[i]);
}



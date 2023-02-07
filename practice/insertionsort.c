#include<stdio.h>
#define s 10
void main(){
	int t,i,j,a[s];
	for(i=0;i<s;i++)
		scanf("%d",&a[i]);
	for(i=0;i<s;i++)
	{
		for(j=0;j<i;j++)
		{
			if(a[i]<a[j])
			{
				t=a[j];
				a[j]=a[i];
				a[i]=t;
			}
		}
	}
	for(i=0;i<s;i++)
		printf("%d\t",a[i]);
}



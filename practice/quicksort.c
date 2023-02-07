#include<stdio.h>
#define s 10
void main(){
	int t,i,j,a[s],k;
	for(i=0;i<s;i++)
		scanf("%d",&a[i]);
	for(i=0;i<s;i++){
		for(j=0,k=s-1;j<k;j++,k--)
		{
			if(a[j]>a[k])
			{
				t=a[j];
				a[j]=a[k];
				a[k]=t;
			}
		}
	}
	for(i=0;i<s;i++)
		printf("%d\t",a[i]);
}



#include<stdio.h>
void main(){
	int i,j,n,k;
	printf("enter a array size");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(a[i]==a[j])
			{
				for(k=j;k<n-1;k++)
					a[k]=a[k+1];
				n=n-1;
				j--;
			}}
		
	}
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
}
	


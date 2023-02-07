/*to check contains different elements or not*/
#include<stdio.h>
void main(){
	int a[10],i,j,n,s=0;
	printf("enter array size");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	 {
		 for(j=i+1;j<n;j++)
		 {
			 if(a[i]==a[j])
			 {
				 s=1;
				 break;}
		 }
	 }
	if(s==0){
		printf("array has distinct elements");
	}
	else printf("array has same elements");

	
}






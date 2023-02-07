#include<stdio.h>
void main(){
	int i,n,l1=9999,l2=9999;
	printf("enter array size");
	scanf("%d",&n);
	int arr[n];
	printf("enter array elements");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<n;i++){
		if(l1>arr[i]){
			l2=l1;
			l1=arr[i];}
		else {if((l2>arr[i])&&(l1!=arr[i]))
			l2=arr[i];}
	}
	printf("second least=%d",l2);}


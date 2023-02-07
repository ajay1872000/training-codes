#include<stdio.h>
void main(){
	int i,j,n;
	printf("enter a value");
	scanf("%d",&n);
	for(i=0;i<=n;i++){
		printf("%d-",i);
		for(j=7;j>=0;j--)
			printf("%d",((i>>j)&0x1));
		printf("\n");}
}

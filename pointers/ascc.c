#include<stdio.h>
void main(){
	int a[10][10],i,j,k,l,t,r,c;
	printf("enter r,c values");
	scanf("%d,%d",&r,&c);
	printf("array elements");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			scanf("%d",&a[i][j]);
	}
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			for(k=0;k<r;k++){
			//	for(l=0;l<c;l++){
					if(a[i][j]<a[k][j]){
						t=a[k][j];
						a[k][j]=a[i][j];
						a[i][j]=t;}
			//	}
			}
		}
	}
	printf("asecending order elements\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
}

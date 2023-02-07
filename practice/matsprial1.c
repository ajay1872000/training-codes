#include<stdio.h>
#define R 3
#define C 3
void spiral(int (*a)[C],int i,int j,int r,int c){
	int k,l;
	//printf("\t");
	if(((r-i)<=0)&&((c-j)<=0))
	{	if(((r-i)==0)&&((c-j)==0))
		 printf("%d",a[i][j]);
		return;}
	for(k=i;k<=c;k++)
		printf("%d\t",a[i][k]);
	for(k=i+1;k<=r;k++)
		printf("%d\t",a[k][c]);
	for(k=c-1;k>=i;k--)
		printf("%d\t",a[r][k]);
	for(k=r-1;k>i;k--)
		printf("%d\t",a[k][i]);
	spiral(a,i+1,j+1,r-1,c-1);
}
void main(){
	int a[R][C],i,j,k=1;
	for(i=0;i<R;i++)
		for(j=0;j<C;j++,k++)
		 	a[i][j]=k;
	spiral(a,0,0,R-1,C-1);
}

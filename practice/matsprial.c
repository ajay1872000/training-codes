#include<stdio.h>
#define R 3
#define C 3
void main(){
	int a[R][C],i,j;
	for(i=0;i<R;i++)
		for(j=0;j<C;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<C;i++)
		printf("%d\t",a[0][i]);
	for(i=1;i<R;i++)
		printf("%d\t",a[i][C-1]);
	for(i=C-2;i>=0;i--)
		printf("%d\t",a[R-1][i]);
	for(i=R-2;i>0;i--)
		printf("%d\t",a[i][0]);
	for(i=1;i<C-1;i++)
		printf("%d'\t",a[1][i]);
	for(i=2;i<R-1;i++)
		printf("%d\t",a[i][C-2]);
	for(i=C-3;i>0;i--)
		printf("%d\t",a[R-2][i]);
}


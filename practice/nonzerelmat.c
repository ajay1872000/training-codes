#include<stdio.h>
#define R 3
#define C 3
void main(){
	int a[R][C],i,j,(*p)[3]=NULL,co=0;
	for(i=0;i<R;i++)
		for(j=0;j<C;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
			printf("%d\t",a[i][j]);
		printf("\n");}
	printf("-------------------------------------------------------\n");
	for(i=0;i<R;i++){
		for(j=0;j<C;j++){
			if(a[i][j]!=0)
			{co++;
			p=(int(*)[3])realloc(p,co*3*sizeof(int));
				p[co-1][0]=i;
				p[co-1][1]=j;
				p[co-1][2]=a[i][j];

			}
		}
	}
	for(i=0;i<co;i++)
	{
		for(j=0;j<3;j++)
			printf("%d\t",p[i][j]);
		printf("\n");
	}
}


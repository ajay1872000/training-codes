#include<stdio.h>
int x[3]={0,1,2};
int y[3];
void main(){
	int i,j,a[3]={10,20,30},b[3]={20,40,50};
	int *p=(int*)calloc(3,sizeof(int));
	int *ptr[5]={a,b,p,x,y};
	printf("ptr=%p,&ptr[0]=%p",ptr,&ptr[0]);
	printf("a=%p,ptr[0]=%p\n",a,ptr[0]);
	printf("b=%p,ptr[1]=%p\n",b,ptr[1]);
	for(i=0;i<5;i++)
		{printf("\n%p\n",ptr[i]);
		for(j=0;j<4;j++)
		{printf("%d\t",ptr[i][j]);}
		}
}


	


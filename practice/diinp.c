#include<stdio.h>
void main(){
	int x[5]={1,2,3,4,5};
	int *ptr=x;
	int  ret;
	ret=((int*)&ptr[4])-((int*)&ptr[0]);
		printf("%d",ret);
}


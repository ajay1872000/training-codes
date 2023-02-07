#include<stdio.h>
void display(int x[5],int n)
	{
		int i;
		printf("%d\n",sizeof(x));
		for(i=0;i<n;i++)
			printf("%d\n",x[i]);
	}
void main(){
	int x[5]={10,20,30,40,50};
	display(x,5);
	printf("%d\n",sizeof(x));
}

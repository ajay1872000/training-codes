#include<stdio.h>
void main(){
	int a=5;
	printf("%d\n",++a);
	 a=5;
	printf("%d\n",a++);
	a=5;
	printf("%d,%d\n",++a,a++);
	 a=5;
	printf("%d,%d\n",++a,++a);
	 a=5;
	printf("%d,%d\n",a++,++a);
	a=5;
	printf("%d,%d,%d\n",++a,a++,++a);
}

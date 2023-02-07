
#include<stdio.h>
void main(){
	int a=10;
	unsigned int *ptr=&a;
	printf("%x\n",*ptr);
	*ptr++;
	printf("%x\n",*ptr);
       ++*ptr;	
	printf("%x\n",*ptr); 
	(*ptr)++;
	printf("%x\n",*ptr); 
	printf("%x\n",*ptr);
	//int *ptr1=&b;
	//printf("%d-%d-%d\n",*ptr1++,++*ptr1,(*ptr1)++); 
}

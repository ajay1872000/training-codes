/* to perform byte swap using pointers*/
/* i/p1=11223344 i/p2=aabbccdd o/p=11bb33dd*/
#include<stdio.h>
#include<stdlib.h>
void main(){
	unsigned int *ptr=(int*)malloc(1*sizeof(int));
	unsigned int *ptr1=(int*)malloc(1*sizeof(int));
	unsigned int *ptr2=(int*)malloc(1*sizeof(int));
	if((ptr==NULL)||(ptr1==NULL)||(ptr2==NULL)){
		printf("faoled to allocate memory");
		exit(1);}
	printf("enter two values a,b:");
	scanf("%x,%x",&ptr[0],&ptr1[0]);
	ptr2[0]=ptr1[0];
	((char*)ptr2)[0]=((char*)ptr)[0];
	((char*)ptr2)[2]=((char*)ptr)[2];
	printf("%x",ptr2[0]);
	free(ptr);
	free(ptr1);
	free(ptr2);
}



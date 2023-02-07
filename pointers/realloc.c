#include<stdio.h>
#include<stdlib.h>
void main(){
	int s,rs,i;
	int *ptr,*rptr;
	printf("enter size of an array");
	scanf("%d",&s);
	ptr=(int*)calloc(s,sizeof(int));
	if(ptr==NULL){
		printf("failed to allocate memory");
		exit(1);}
	for(i=0;i<s;i++)
		scanf("%d",ptr+i);
	for(i=0;i<s;i++)
		printf("%d\t",ptr[i]);
	printf("\nenter new size");
	scanf("%d",&rs);
	rptr=(int*)realloc(ptr,rs*sizeof(int));
	if(rptr==NULL){
		printf("failed to reallocate memory");
		exit(2);
	}
	printf("\nenter remaining elements");
	for(i=s;i<rs;i++)
		scanf("\t%d",rptr+i);
	printf("\nupdated elements");
	for(i=0;i<rs;i++)
		printf("\t%d",rptr[i]);
	free(rptr);
}


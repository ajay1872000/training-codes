/*program to study about array of pointers through switch case as menu driven*/
#include<stdio.h>
#include<stdlib.h>
int add_ele(int*,int);
int remove_ele(int*,int);
void read_arr(int*,int);//to read array of pointers
void disp_arr(int*,int);//to display the array
int big_num(int*,int);//to find the biggest number among the array
int big2_num(int*,int);// to find second biggest number
void bin_num(int*,int);// to converter each decimal number to binary in a array
void asce_ord(int*,int);// to arrange the array in ascending order
void main(){
	int n,c,r;
	int *ptr=NULL;
	printf("enter n value");
	scanf("%d",&n);
	ptr=(int *)calloc(n,sizeof(int));
	if(ptr==NULL)
	{printf("failed to allocate memory");
		exit(1);}
	while(1){
		printf("\n0.exit\n1.read array\n2.add element\n3.remove element\n4.display array\n5.biggest value\n6.2nd biggest value\n7.Decimal to binary\n8.ascending order of a array\n enter a choice");
		scanf("%d",&c);
		switch(c){
			case 0: free(ptr);exit(0);
			case 1:read_arr(ptr,n);break;
			case 2:n=add_ele(ptr,n);break;
			case 3:n=remove_ele(ptr,n);break;
			case 4:disp_arr(ptr,n);break;
			case 5:r=big_num(ptr,n);
			       printf("biggest=%d",r);break;
			case 6:r=big2_num(ptr,n);
			       printf("2nd biggest=%d",r);break;
			case 7:bin_num(ptr,n);
			       break;
			case 8:asce_ord(ptr,n);break;
			default : printf("wrong choice");}}}
int add_ele(int* ptr,int n){
int r,i;
printf("enter no of elements need to add");
scanf("%d",&r);
int *rptr=(int*) realloc(ptr,n+r);
printf("enter extra elements");
for(i=n;i<n+r;i++)
	scanf("%d",ptr+i);
n=n+r;
disp_arr(ptr,n);
return n;}
int remove_ele(int* ptr,int n){
	int r;
printf("enter no of elements need to remove");
scanf("%d",&r);
n=n-r;
int *rptr=(int*) realloc(ptr,n);
disp_arr(rptr,n);
return n;}

void read_arr(int* ptr,int n){
	int i;
	printf("enter array elements");
	for(i=0;i<n;i++)
		scanf("%d",&ptr[i]);
}
void disp_arr(int* ptr,int n){
	int i;
	for(i=0;i<n;i++)
		printf("%d\n",ptr[i]);
}
int big_num(int* ptr,int n){
	int i,b=0;
	for(i=0;i<n;i++)
	{if(b<ptr[i])
		b=ptr[i];}
	return b;
}
int big2_num(int* ptr,int n){
	int i,b=0,b2=0;
	for(i=0;i<n;i++)
	{
		if(b<ptr[i])
		{b2=b;

			b=ptr[i];}
		else{
			if(b2<ptr[i])
				b2=ptr[i];}}
	return b2;
}
void bin_num(int* ptr,int n){
	int i,t,r,bin=0,j;
	for(i=0;i<n;i++)
	{ 
		t=ptr[i];
		bin=0;
		j=1;
		while(t!=0){
			r=t%2;
			bin=bin+r*j;
			j=j*10;
			t=t/2;}
		printf("\n%d-%d",ptr[i],bin);}
}
void asce_ord(int* ptr,int n){
	int i,j,t;
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			if(ptr[i]>ptr[j])
			{       t=ptr[i];
				ptr[i]=ptr[j];
				ptr[j]=t;}}}
	disp_arr(ptr,n);
}

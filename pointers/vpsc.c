/*program to study about array of pointers through switch case as menu driven*/
#include<stdio.h>
#include<stdlib.h>
void read_arr(void*,int);//to read array of pointers
void disp_arr(void*,int);//to display the array
int big_num(void*,int);//to find the biggest number among the array
int big2_num(void*,int);// to find second biggest number
void bin_num(void*,int);// to converter each decimal number to binary in a array
void asce_ord(void*,int);// to arrange the array in ascending order
void main(){
	int n,c,r;
	int *ptr=NULL;
	printf("enter n value");
	scanf("%d",&n);
	ptr=(void *)calloc(n,sizeof(int));
	if(ptr==NULL)
	{printf("failed to allocate memory");
		exit(1);}
	while(1){
		printf("\n0.exit\n1.read array\n2.display array\n3.biggest value\n4.2nd biggest value\n5.Decimal to binary\n6.ascending order of a array\n enter a choice");
		scanf("%d",&c);
		switch(c){
			case 0: free(ptr);exit(0);
			case 1:read_arr(ptr,n);break;
			case 2:disp_arr(ptr,n);break;
			case 3:r=big_num(ptr,n);
			       printf("biggest=%d",r);break;
			case 4:r=big2_num(ptr,n);
			       printf("2nd biggest=%d",r);break;
			case 5:bin_num(ptr,n);
			       break;
			case 6:asce_ord(ptr,n);break;
			default : printf("wrong choice");}}}

void read_arr (void* ptr,int n){
	int i;
	printf("enter array elements");
	for(i=0;i<n;i++)
		scanf("%d",&((int*)ptr)[i]);
}
void disp_arr(void* ptr,int n){
	int i;
	for(i=0;i<n;i++)
		printf("%d\n",((int*)ptr)[i]);
}
int big_num(void* ptr,int n){
	int i,b=0;
	for(i=0;i<n;i++)
	{if(b<((int*)ptr)[i])
		b=((int*)ptr)[i];}
	return b;
}
int big2_num(void* ptr,int n){
	int i,b=0,b2=0;
	for(i=0;i<n;i++)
	{
		if(b<((int*)ptr)[i])
		{b2=b;

			b=((int*)ptr)[i];}
		else{
			if(b2<((int*)ptr)[i])
				b2=((int*)ptr)[i];}}
	return b2;
}
void bin_num(void* ptr,int n){
	int i,t,r,bin=0,j;
	for(i=0;i<n;i++)
	{ 
		t=((int*)ptr)[i];
		bin=0;
		j=1;
		while(t!=0){
			r=t%2;
			bin=bin+r*j;
			j=j*10;
			t=t/2;}
		printf("\n%d-%d",((int*)ptr)[i],bin);}
}
void asce_ord(void* ptr,int n){
	int i,j,t;
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			if(((int*)ptr)[i]>((int*)ptr)[j])
			{       t=((int*)ptr)[i];
				((int*)ptr)[i]=((int*)ptr)[j];
				((int*)ptr)[j]=t;}}}
	disp_arr(ptr,n);
}

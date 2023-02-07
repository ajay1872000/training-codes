#include<stdio.h>
#include<stdlib.h>
void pop();
void push(int*,int);
int search(int*);
void disp(int*);
int se_le(int*);
#define S 5
int i=-1;
void main(){
	int opt,arr[S],r;
	while(1){
		printf("\nMENU\n0.exit\n1.push\n2.pop\n3.search\n4.display\n5.second least element\nEnter your choice");
		scanf("%d",&opt);
		switch(opt){
			case 0:exit(0);
			case 1:push(arr,S);
			       break;
			case 2:pop();break;
			case 3:r=search(arr);
			       if(r<=i)
				       printf("\n%d is found at %p",arr[r],&arr[r]);
			       else 
				       printf("\nelement not found");
			       break;
			case 4:disp(arr);break;
			case 5:r=se_le(arr);
			       printf("%d is the second least number",r);break;
			default:printf("invalid choice");}}}
int se_le(int *ptr){
	int l1=999,l2=999,j;
	for(j=0;j<=i;j++){
		if(l1>ptr[j]){
			l2=l1;
			l1=ptr[j];}
		else{
			if((l2>ptr[j])&&(l1!=ptr[j]))
				l2=ptr[j];}
	}
		return l2;
}

void pop(int *ptr){
	if(i<0)
		printf("stack is empty");
	else
		i--;
}
void push(int *ptr,int n){
	i++;
	if(i<n)
	{
		printf("enter a value");
		scanf("%d",&ptr[i]);
	}
	else{
		printf("Stack is full");
		i--;}
}
int search(int *ptr){
	int k,j;
	printf("enter search element");
	scanf("%d",&k);
	for(j=0;j<=i;j++){
		if(ptr[j]==k)
			return j;
	}return j;
	}
void disp(int *ptr){
	int j;
	for(j=0;j<=i;j++)
		printf("\n%p-%d",ptr+j,ptr[j]);
}

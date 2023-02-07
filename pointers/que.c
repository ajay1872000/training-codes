#include<stdio.h>
#include<stdlib.h>
void insert(int*);
void delete(int*);
int search(int*);
int big(int*);
int _2big(int*);
void disp(int*);
#define S 5
int f=-1,b=-1; 
void main(){
	int arr[S],opt,r;
       while(1){
       printf("\nMENU\n-------------------------------------------------------------------------------------------------------------\n0.exit(0)\n1.insert\n2.delete\n3.search\n4.display\n5.biggest number\n6.2nd biggest number\nEnter your choice");
       scanf("%d",&opt);
	switch(opt){
		case 0: exit(0);
		case 1: insert(arr);
			break;
		case 2:delete(arr);
	       		break;
		case 3:r=search(arr);
		       if(r==-1)
			       printf("element not found");
		       else
			       printf("%d is found at %p",arr[r],arr+r);

			break;
		case 4:disp(arr);
			break;
		case 5:r=big(arr);
		       printf("%d is the biggest number",r);break;
		case 6:r=_2big(arr);
		       printf("%d is the second biggest number",r);break;
		default:printf("invalid choice");}
       }
}
int big(int *ptr){
	int i,n=ptr[f];
	for(i=f;i<=b;i++){
		if(n<ptr[i])
			n=ptr[i];
	}
	return n;}
int _2big(int *ptr){
	int i,b1=ptr[f],b2=ptr[f];
	for(i=f;i<=b;i++){
		if(b1<ptr[i]){
			b2=b1;
			b1=ptr[i];}
		else{
			if((b2<ptr[i])&&(b1!=ptr[i]))
				b2=ptr[i];
		}}
		return b2;
}
void insert(int *ptr){
	if(f==-1)
		f++;
	if(b<4)
		{b++;
	printf("enter a value");
	scanf("%d",&ptr[b]);}
	else printf("queue full");
}
void delete(int *ptr){
	int i;
	if((f==-1)&&(b==-1))
		printf("queue is empty");
	else{if(f==b)
		{f=-1;
		b=-1;}
		else {
		for(i=f;i<b;i++)
		  ptr[i]=ptr[i+1];
		b--;}}
}
void disp(int *ptr){
	int i;
	if((f==-1)&&(b==-1))
		printf("queue is empty");
	else{
		for(i=f;i<=b;i++)
			printf("%d\t",ptr[i]);
	}
}
int search(int *ptr){
	int n,i;
	printf("enter search value");
	scanf("%d",&n);
	if((f==-1)&&(b==-1))
		printf("queue is empty");
	else{
		for(i=f;i<=b;i++)
		{
			if(ptr[i]==n)
				return i;}
	}
	return -1;
}




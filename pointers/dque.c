#include<stdio.h>
#include<stdlib.h>
void insert(int*);
void delete();
int search(int*);
void disp(int*);
#define S 5
int f=-1,b=-1; 
void main(){
	int arr[S],opt,r;
       while(1){
       printf("\nMENU\n----------------------------------------------------------------------------------------------------------\n0.exit(0)\n1.insert\n2.delete\n3.search\n4.display\nEnter your choice");
       scanf("%d",&opt);
	switch(opt){
		case 0: exit(0);
		case 1: insert(arr);
			break;
		case 2:delete();
	       		break;
		case 3:r=search(arr);
		       if(r==-1)
			       printf("element not found");
		       else
			       printf("%d is found at %p",arr[r],arr+r);

			break;
		case 4:disp(arr);
			break;
		default:printf("invalid choice");}
       }
}
void insert(int *ptr){
	int d,n;
	if(f==-1)
		f++;
	printf("menu\n1.first\n2.second");
	scanf("%d",&d);
	if(d==1){
		if(f>0){
		f--;
		n=f;}
		else{
			printf("can't add from front");
		return;}}
	else
	{if(b<4){
		b++;
		n=b;}
	else {printf("queue overflow");
		return;}

	}
	printf("enter a value");
	scanf("%d",&ptr[n]);
}
void delete(){
	int d;
	printf("enter a value");
	scanf("%d",&d);
	if((f==-1)&&(b==-1))
		printf("double queue is empty");
	else{if(f==b)
		{f=-1;
		b=-1;}
		else {if(d==1)
			f++;
			else b--;
				}
}}
void disp(int *ptr){
	int i;
	if((f==-1)&&(b==-1))
		printf("double queue is empty");
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
		printf("double queue is empty");
	else{
		for(i=f;i<=b;i++)
		{
			if(ptr[i]==n)
				return i;}
	}
	return -1;
}











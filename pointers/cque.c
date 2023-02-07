#include<stdio.h>
#include<stdlib.h>
int f=-1,r=-1;
#define S 5
void insert(int*);
void delete();
void display(int*);
void asce(int*);
void dec(int*);
int rep(int*,int);
void main(){
	int arr[5],opt,n,r;
	while(1){
		printf("\nMENU\n___________________________________________________________________________________________________________________________________________\n0.exit(1)\n1.insert\n2.delete\n3.display\n4.ascending order\n5.descending  order\n6.search number how many times it is repeated\nenter your choice");
		scanf("%d",&opt);
		switch(opt){
			case 0:exit(0);
			case 1:insert(arr);
			       break;
			case 2:delete(arr);
			       break;
			case 3:display(arr);
			       break;
			case 4:asce(arr);
			       break;
			case 5:dec(arr);
			       break;
			case 6:printf("enter a value");
			       scanf("%d",&n);
			       r=rep(arr,n);
			       if(r==0)
			       printf("element not found");
			       else
				       printf("%d times %d found",r,n);
			       break;
			default:printf("invalid choice");}
	}
}
int rep(int *ptr,int n){
	int c=0,i;
	if(f<=r){
		for(i=f;i<=r;i++){
			if(ptr[i]==n)
				c++;}
	}
	else{
		for(i=f;i<=S+r;i++)
			if(ptr[i%S]==n)
				c++;}
	return c;
}

void insert(int *ptr){
	if(f==-1){
		f++;
		r++;
	}
	else{ if((r==(f-1))||((f==0)&&(r==(S-1)))){
		printf("Queue is full");
		return;
	}
	else{
		if(r==(S-1))
			r=0;
		else 
			r++;
	}
	}
	printf("enter a value");
	scanf("%d",ptr+r);
}

void delete(){
	if(f==-1)
	{
		printf("Queue is empty");
		return;}
	else {if(f==r)
		{f=r=-1;
			return;}
		else {if(f==S-1)
			{f=0;
				return;}
			else f++;}}
}
void display(int *ptr){
	int i;
	if(f==-1)
	{
		printf("Queue is empty");
		return;}
	else {
		if(f<=r){
			for(i=f;i<=r;i++)
				printf("%p-%d\t",&ptr[i],ptr[i]);
		}
		else{
			for(i=f;i<=S+r;i++)
				printf("%p-%d\t",&ptr[i%S],ptr[i%S]);
		}}
}
void asce(int *a){
	int i,j,t;
	if(f==-1)
		printf("Queue is empty");
	else{
		if(f>r){
			for(i=f;i<=S+r;i++)
			{for(j=i+1;j<=S+r;j++)
				{if(a[i%S]>a[j%S])
					{
						t=a[i%S];
						a[i%S]=a[j%S];
						a[j%S]=t;}
				}
			}
		}
		else{
			for(i=f;i<=r;i++)
			{for(j=i+1;j<=r;j++)
				{if(a[i]>a[j])
					{
						t=a[i];
						a[i]=a[j];
						a[j]=t;
					}
				}
			}
		}
	}
	display(a);
}

void dec(int *a){
	int i,j,t;
	if(f==-1)
	{
		printf("Queue is empty");
		return;}
	else{
		if(f>r){
			for(i=f;i<=S+r;i++)
			{for(j=i+1;j<=S+r;j++)
				{if(a[i%S]<a[j%S])
					{
						t=a[i%S];
						a[i%S]=a[j%S];
						a[j%S]=t;}
				}
			}
		}
		else{
			for(i=f;i<=r;i++)
			{for(j=i+1;j<=r;j++)
				{if(a[i]<a[j])
					{
						t=a[i];
						a[i]=a[j];
						a[j]=t;
					}
				}
			}
		}
	}
	display(a);
}


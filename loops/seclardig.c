#include<stdio.h>
int sec_d (int);
void main(){
	int n,r;
	printf("enter n value");
	scanf("%d",&n);
	r=sec_d(n);
	printf("\n%d",r);
}
int sec_d(int n){
	int b=0,a=0,r;
	while(n!=0){
		r=n%10;
		if(a>r){
			if(b<r)
				b=r;
			else
				;
		}
		else{
			b=a;
			a=r;}
	n=n/10;}
	return b;
	}


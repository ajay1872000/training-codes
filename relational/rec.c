#include<stdio.h>
int f(int);
void main(){
	int n=7;
	printf("%d",f(n));
}
int f(int n){
	if(n<=4)
		return n;
	else
		return f(--n);
}

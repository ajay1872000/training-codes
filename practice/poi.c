#include<stdio.h>
int main(){
	int *p,arr[10]={10,20,30,40,50,60,70,80,90,100};
	for(p=&arr[0];p<arr+10;p++)
		printf("%d ",*p);
	return 0;
}

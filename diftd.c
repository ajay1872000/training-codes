#include<stdio.h>
#include<stdio_ext.h>
void main(){
	 int a,b;
	 char x,y[10];
	 printf("enter interger a");
	 scanf("%d",&a);
	 printf("\nenter interger b");
	 scanf("%d",&b);
	 __fpurge(stdin);
	 printf("\nenter char x");
	 scanf("%c",&x);
	 __fpurge(stdin);
	 printf("\nenter string y");
	 scanf("%s",y);
	 printf("\na=%d,b=%d",a,b);
	 printf("\nx=%c,y=%s",x,y);
 }

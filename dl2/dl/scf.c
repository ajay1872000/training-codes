#include<stdio.h>
#include"header.h"
#include<stdlib.h>
void main(){
	int n,res,opt;
//	while(1){
		printf("\n0.exit\n1.Reverse a number\n2.Palindrome\n3.sum of digits\n4.no of digits\n5.Decimal to binary\n6.Binary to decimal\n enter a option");
		scanf("%d",&opt);
		__fpurge(stdin);
		if((opt<7)&&(opt>0))
		{	printf("enter a value");
			scanf("%d",&n);}
		switch(opt){
			case 0:exit(0);
			case 1:res=rev_digit(n);
			       printf("%d reverse is %d",n,res);break;
			case 2:res=rev_digit(n);
			       if(res==n)
				       printf("%d is a palindrome",n);
			       else
				       printf("%d is not a palindrome",n);
			       break;
			case 3:res=sum_of_digit(n);
			       printf("%d is sum of digits of %d",res,n); break;
			case 4:res=no_of_digit(n);
			       printf("%d is no of digits in %d",res,n);break;
			case 5:res=dec_to_bin(n);
			       printf("%d is binary number for %d",res,n);break;
			case 6:res=bin_to_dec(n);
			       if(res==-1)
				       printf("invalid number");
			       else
				       printf("%d is decimal number for %d",res,n);
			       break;
			default:printf("invalid case");}}
//}

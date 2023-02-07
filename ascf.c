#include<stdio.h>
int rev_int(int);
int sum_of_digit(int);
int no_of_digit(int);
int dec_to_bin(int);
int even_odd(int);
void main(){
	int n,res,opt;
	while(1){
	printf("\nenter a digit");
        scanf("%d",&n);
	printf("the menu\n0.exit");
	printf("\n1.Reverse of a given number");
	printf("\n2.sum of digits of a given number");
	printf("\n3.count the no of digits of a given number");
	printf("\n4.Given number is a palindrome or not");
	printf("\n5.binary  of a given number");
	printf("\n6.Given number is even or odd");
	printf("\nenter a choice");
	scanf("%d",&opt);
	switch(opt){
		case 0:exit(0);
		case 1:
			printf("Reverse of number %d is %d",n,rev_int(n));
		       break;
		case 2:res=sum_of_digit(n);
		       printf("sum of digits of number %d is %d",n,res);
		        break;
		case 3:
			res=no_of_digit(n);
			printf("number of digits in a given number %d is %d",n,res);
		       break;
		case 4:
			res=rev_int(n);
		       if(res==n)
				printf("number %d is a palindrome",n);
			else
				printf("number %d is not a palindrome",n);
		       break;
		case 5:
		       res=dec_to_bin(n);
			printf("Binary of number %d is %d",n,res);break;
		case 6:
			if(even_odd(n)==0)
				printf("%d is Even number",n);
			else
				printf("%d is odd number",n);
		       break;
		default:
		       printf("invalid choice");
	}}


}
int rev_int(int num){
	int r,dec=0,t=num;
	    while(t!=0){
		    r=t%10;
		    dec=dec*10+r;
		    t=t/10;}
	return dec;
}
int no_of_digit(int num){
	int n=0,t=num;
	do{
		n++;
		t=t/10;}while(t!=0);
	return n;}
int sum_of_digit(int num){
	int s=0,r,t=num;
	while(t!=0){
		r=t%10;
		s=s+r;
		t=t/10;}
	return s;}
int dec_to_bin(int num){
	int s=0,r,i=1,t;
	    t=num;
	while(t!=0){
		r=t%2;
		s=s+r*i;
		i=i*10;
		t=t/2;}
	return s;}
int even_odd(int num){
	if(num%2==0){
		printf("Even number");
		return 0;}
	else{
		printf("Odd number");
		return 1;}}




			 



					

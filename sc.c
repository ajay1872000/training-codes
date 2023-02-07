#include<stdio.h>
void main(){
	int n,s=0,opt,t,i=1,r;
	printf("enter a digit");
        scanf("%d",&n);
	printf("the menu");
	printf("\n1.Reverse of a given number");
	printf("\n2.sum of digits of a given number");
	printf("\n3.count the no of digits of a given number");
	printf("\n4.Given number is a palindrome or not");
	printf("\n5.binary  of a given number");
	printf("\n6.Given number is even or odd");
	printf("\nenter a choice");
	scanf("%d",&opt);
	switch(opt){
		case 1:
		       t=n;
			while(t!=0){
		 	s=(t%10)+(s*10);
			t=t/10;}
			printf("Reverse of number %d is %d",n,s);
		       break;
		case 2:t=n;
			while(t!=0){
		 	s=(t%10)+s;
			t=t/10;}
			printf("sum of digits of number %d is %d",n,s);
		        break;
		case 3:
			t=n;       
			do{
		 	s=s+1;
			t=t/10;}while(t!=0);
			printf("number of digits in a given number %d is %d",n,s);
		       break;
		case 4:
			       t=n;
			while(t!=0){
		 	s=(t%10)+(s*10);
			t=t/10;}
			if(s==n)
				printf("number %d is a palindrome",n);
			else
				printf("number %d is not a palindrome",n);
		       break;
		case 5:
			t=n;       
			while(t!=0){
		 	s=((t%2)*i)+s;
			i=i*10;
			t=t/2;}
			printf("Binary of number %d is %d",n,s);break;
		case 6:
			if(n%2==0)
				printf("%d is Even number",n);
			else
				printf("%d is odd number",n);
		       break;
		default:
		       printf("invalid choice");
	}

}
			 



					

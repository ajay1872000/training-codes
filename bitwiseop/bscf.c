#include<stdio.h>
int no_of_zeros(int);
int no_of_101(int);
int bin_32bit(int);
int swap_bit(int);
int replace_101_111(int);
int even_odd(int);
void main(){
	int n,res,opt;
	while(1){
        printf("enter a digit");
       	scanf("%d",&n);
	printf("the menu\n0.exit");
	printf("\n1.Count  no of zeros and ones of a given number");
	printf("\n2.count no of 101  in  a given number");
	printf("\n3.Print 32-bit binary number");
	printf("\n4.Swap bits  of a given number");
	printf("\n5.replace 101 with 111 in a given ");
	printf("\n6.check if the given number is even or odd");
	printf("\nenter a choice");
	scanf("%d",&opt);
	switch(opt){
		case 0:exit(0);
		case 1:res=no_of_zeros(n);
			printf("%d zeros and %d ones are present in %d",res,32-res,n);
		       break;
		case 2:
       			res=no_of_101(n);
			printf("%d no  of 101 present in given  number %d",res,n);
		        break;
		case 3:
		       
			printf("32-bit binary number of %d is ",n);
			res=bin_32bit(n);
		       break;
		case 4:res=swap_bit(n);
		       printf("%x 32-bit swap is %x",n,res);

		       break;
		case 5:res=replace_101_111(n);
       			
			printf("%d is the number generated for  %d",res,n);
			break;
		case 6:
			if(even_odd(n))
				printf("%d is an even number",n);
			else
				printf("%d is an odd number",n);
		       break;
		default:
		       printf("invalid choice");
	}
	}
}
int no_of_zeros(int n){
	int i,z=0;
	for(i=0;i<=31;i++){
		if((n>>i)&0x1){
			z++;
		}
	}
	return z;
}

int no_of_101(int n){
	int i,c=0;
	for(i=0;i<=29;i++){
		if(((n>>i)&0x7)==0x5){
			c++;
		}
	}
	return c;}
int bin_32bit(int n){
	int i;
	for(i=31;i>=0;i--)
		printf("%d",(n>>i)&0x1);
	return 0;
}
int swap_bit(int n){
	int i,j,y=n;
	for(i=0,j=31;i<j;i++,j--){
		y=(y&~(0x1<<i|0x1<<j))|(y&(0x1<<j))>>(j-i)|(y&(0x1<<i))<<(j-i);

				}
	return y;
	}
int replace_101_111(int n){
	int i,y=n;
       for(i=0;i<=29;i++){
	if(((n>>i)&0x7)==0x5){
 		y=y|(0x7<<i);
		}
		}
		return y;
		}
int even_odd(int n)
{ if(n&0x1==0){
 		printf("Even number");
		return 0;}
		else{
		printf("Odd numbers");
		return 1;}
		}

			 



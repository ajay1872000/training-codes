#include<stdio.h>
void main(){
	int n,s1=0,s0=0,j,opt,t,i=1,r;
        printf("enter a digit");
       	scanf("%d",&n);
	printf("the menu");
	printf("\n1.Count  no of zeros and ones of a given number");
	printf("\n2.count no of 101  in  a given number");
	printf("\n3.Print 32-bit binary number");
	printf("\n4.Swap bits  of a given number");
	printf("\n5.replace 101 with 111 in a given ");
	printf("\n6.check if the given number is even or odd");
	printf("\nenter a choice");
	scanf("%d",&opt);
	switch(opt){
		case 1:
			for(i=0;i<=31;i++)
			{
				if((n&(0x1<<i))==0)
					s0++;
				else
					s1++;
			}
			printf("%d zeros and %d ones are present in %d",s0,s1,n);
		       break;
		case 2:t=n;	
		       for(i=0;i<=29;i++)
			{
				if(((n>>i)&0x7)==0x5)
					s0++;
			}
       			
			printf("%d no  of 101 present in given  number %d",s0,n);
		        break;
		case 3:
		       s1=n;
			printf("32-bit binary number of %d is ",n);
			for(i=31;i>=1;i--)
			{
				printf("%d",((s1>>i)&0x1));
			}
		       break;
		case 4:s1=n;	
		       for(i=0,j=31;i<j;i++,j--)
			{
				s1=((s1&~(0x1<<i|0x1<<j))|((s1&(0x1<<i))<<(j-i))|((s1&(0x1<<j))>>(j-i)));
			}
		       printf("%x 32-bit swap is %x",n,s1);

		       break;
		case 5:
		       t=n;	
		       for(i=0;i<=29;i++)
			{
				if(((n>>i)&0x7)==0x5)
					t=t|(0x7<<i);
			}
       			
			printf("%d is the number generated for  %d",t,n);
			break;
		case 6:
			if((n&0x1)==0)
				printf("%d is an even number",n);
			else
				printf("%d is an odd number",n);
		       break;
		default:
		       printf("invalid choice");
	}

}
			 



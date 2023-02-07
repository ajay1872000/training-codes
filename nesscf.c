#include<stdio.h>
#include<stdlib.h>
int rev_int(int);
int sum_of_digit(int);
int no_of_digit(int);
int bin_dec(int);
int dec_bin(int);
int no_of_0s(int);
int dec_bin_bit(int);
int swap_bit(int);
int rep_101_111(int);
int fact(int);
void main(){
	unsigned int a;
	int res,b,t,n,i;
	char sopt,x;
	int opt;
	while(1){
		printf("\n0.Exit\n1.bitwise operations\n2.Arthemetic operations\n3.swap\n4.character conversion\n5.fibonacci series\n6.factorial");
		scanf("%d",&opt);
		__fpurge(stdin);
		switch(opt){
			case 0: exit(0);
			case 1: printf("0.exit\nn.no of 0's and 1's\n b.decimal to binary\ns.swap bit by bit\nr.replace 101 with n in a\nenter an option");
				scanf("%c",&sopt);
				__fpurge(stdin);
				printf("enter a value:");
				scanf("%d",&a);
				__fpurge(stdin);
				switch(sopt){
					case '0': exit(0);
					case 'n':res=no_of_0s(a);
						 printf("%d 1's and %d 0's are present in %d",32-res,res,t);break;
					case 'b':
						 printf("%d binary number is",a);
						 res=dec_bin_bit(a);
						 break;
					case 's':res=swap_bit(a);
						printf("%x is generated for %x",res,a); break;
					case 'r':res=rep_101_111(a);
						printf("%d is generated %d",res,a);
						break;
					default : printf("invalid case"); break;
					}break;
			case 2: printf("0.exit\nP.palindrome\nS.sum of digits\nN:no of digits\nB.Decimal to binary\nD. binary to decimal\nenter an option");
				scanf("%c",&sopt);
				__fpurge(stdin);
				printf("enter a value");
				scanf("%d",&a);
				__fpurge(stdin);
				switch(sopt){
				case '0':exit(0);
				case 'P': res=rev_int(a);
					if(res==a)
						printf("it is a palindrome");
					else 
						printf("it is not a palindrome");
					break;
				case 'N': res=no_of_digit(a);
						  printf("%d is %d digits number",a,res);break;
				case 'S':res=sum_of_digit(a);
						 printf("%d is sum for %d",res,a);break;
				case 'B':res=dec_bin(a);
						 printf("%d binary number for %d",res,a); break;
				case 'D': res=bin_dec(a);
						  printf("%d decimal number for %d binary number",res,a);break;
					default:printf("invalid case");}break;
			case 3:printf("0.exit\na.swap using thrid variable\nb.swap without using thrid variable\nc.swap using bitwise operator");
			       scanf("%c",&sopt);
			       printf("enter two values a,b");
			       scanf("%d,%d",&a,&b);
			       switch(sopt){
				       case '0':exit(0);
				       case 'a':t=a;
						a=b;
						b=t;
						printf("a=%d,b=%d",a,b); break;
				       case 'b':a=a+b;
						b=a-b;
						a=a-b;
						printf("a=%d,b=%d",a,b); break;
				       case 'c':a=a^b;
						b=a^b;
						a=a^b;
						printf("a=%d,b=%d",a,b); break;
				       default: printf("invalid case");}break;
			case 5:printf("enter 1st,2nd values");
			       scanf("%d,%d",&a,&b);
			       __fpurge(stdin);
			       printf("enter n value");
			       __fpurge(stdin);
			       scanf("%d",&n);
			       if(n>=1)
				       printf("\n%d",a);
			       if(n>=2)
				       printf("%d",b);
			        for(i=3;i<=n;i++)
			       {
				       t=a+b;
				       printf("%d",t);
				       a=b;
				       b=t;}break;
			case 4:printf("0.exit\nx.lower case to upper case or lower to upper\n y. char to int");
			       scanf("%c",&sopt);
			       __fpurge(stdin);
			       printf("enter a character");
			       scanf("%c",&x);
			       __fpurge(stdin);
			       switch(sopt){
				       case 'x': if((x>=65)&&(x<=90))
					       {   x=x+32;
					           printf("%c",x); }
					       else{ if((x>=97)&&(x<=122))
					         {x=x-32;
						       printf("%c",x);}
					       else printf("invalid character");}break;
				       case 'y':if((x>=48)&&(x<=57))
						{
							x=x-48;
							printf("%d",x);}
						else printf("invalid character");
						break;
				       default: printf("invalid case");break;}
						break;
			case 6:printf("enter a value");
						scanf("%d",&a);
						res=fact(a);
						printf("%d!=%d",a,res);
			default:printf("invalid case");break;
		}
	}
}
int fact(int n){
	int i,f=1;
	for(i=n;i>0;i--){
		f=f*i;}
	return f;}
int rev_int(int n){
	int t=n,r,s=0;
	while(t!=0){
		r=t%10;
		s=s*10+r;
		t=t/10;}
	return s;}
int no_of_digit(int n){
	int s=0,t=n;
	while(t!=0){
		s++;
		t=t/10;}
	return s;
}
int sum_of_digit(int n){
	int s=0,t=n,r;
	while(t!=0){
		r=t%10;
		s=s+r;
		t=t/10;}
	return s;}
int bin_dec(int n){
	int s=0,t=n,i=1,r;
	while(t!=0){
		r=t%10;
		if(r>1)
			return -1;
		s=s+r*i;
		t=t/10;
		i=i*2;}
	return s;}
int dec_bin(int n){
	int s=0,t=n,i=1,r;
	while(t!=0){
		r=t%2;
		s=s+r*i;
		t=t/2;
		i=i*10;}
	return s;}
int no_of_0s(int n){
	int i,c=0;
	for(i=31;i>=0;i--){
		if(((n>>i)&0x1)==0)
			c++;
	}return c;}
int dec_bin_bit(int n){
	int i;
	for(i=31;i>=0;i--){
		printf("%d",(n>>i)&0x1);
	}
	return 0;}
int swap_bit(int n){
	int i,j,t=n;
	for(i=0,j=31;i<j;i++,j--){
		t=(t&~(0x1<<i|0x1<<j))|(t&(0x1<<i))<<(j-i)|(t&(0x1<<j))>>(j-i);
	}
	return t;}
int rep_101_111(int n){
	int i,t=n;
	for(i=31;i>=0;i--)
	{ if(((n>>i)&0x7)==0x5)
		t=t|0x7<<i;}
	return t;
}

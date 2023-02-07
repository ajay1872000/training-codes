#include<stdio.h>
void main(){
	unsigned int a,bit,b,t;
	int n,c1=0,c0=0;
	int i=0,j;
	char sopt,x;
	int opt;
	while(1){
		printf("\n0.Exit\n1.bitwise operations\n2.Arthemetic operations\n3.swap\n4.character conversion\n5.fibonacci series");
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
					case 'n':t=a;
						 for(i=0;i<=31;i++){
							 if(((t>>i)&(0x1))==0)
								 c0++;
							 else
								 c1++;}
						 printf("%d 1's and %d 0's are present in %d",c1,c0,t);break;
					case 'b':t=a;
						 printf("%d binary number is",t);
						 for(i=31;i>=0;i--)
						    printf("%d",((a>>i)&0x1));
						 break;
					case 's':t=a;
						for(i=0,j=31;i<j;i++,j--){
						  t=(t&(~((0x1<<i)|(0x1<<j))))|((t&(0x1<<i))<<(j-i))|((t&(0x1<<j))>>(j-i));
								  }
						printf("%d is generated for %d",t,a); break;
					case 'r':t=a;
						printf("enter hexa-decimal numbers to replace");
						scanf("%x",&n);
						__fpurge(stdin);
						for(i=0;i<=29;i++){
							if(((a>>i)&0x7)==0x5)
								t=t|(n<<i);

						}
						printf("%d is generated %d",t,a);
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
				case 'P':	t=a;
						i=0;
					while(t>0){
						i=i*10+(t%10);
						t=t/10;
					}
					if(i==a)
						printf("it is a palindrome");
					else 
						printf("it is not a palindrome");
					break;
				case 'N': t=a;
						  i=0;
						  do{
							  i++;
							  t=t/10;
						  }while(t>0);
						  printf("%d is %d digits number",a,i);break;
				case 'S':t=a;
						 i=0;
						 while(t>0){
							 i=i+(t%10);
							 t=t/10;}
						 printf("%d is sum for %d",i,a);break;
				case 'B':t=a;
						 j=1;
						 i=0;
						 while(t>0){
							 n=t%2;
							 i=i+(n*j);
							 j=j*10;
							 t=t/2;}
						 printf("%d binary number for %d",i,a); break;
				case 'D': t=a;
						  j=1;
						  i=0;
						  while(t>0){
						  	n=t%10;
							  if(n>1){
								  printf("invalid binary number");
								  break;}
							  i=i+(n*j);
							  j=j*2;
							  t=t/10;}
						  printf("%d decimal number for %d binary number",i,a);break;
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
					       else if((x>=97)&&(x<=122))
					       {  x=x-32;
						       printf("%c",x);}
					       else printf("invalid character");break;
				       case 'y':if((x>=48)&&(x<=57))
						{
							x=x-48;
							printf("%d",x);}
						else printf("invalid character");
						break;
				       default: printf("invalid case");break;}
						break;
			default:printf("invalid case");break;


		}}





}					 




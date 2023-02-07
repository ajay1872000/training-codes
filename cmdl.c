#include<stdio.h>
#include<stdlib.h>
int stoi(char*);
int palin(int);
void bin_value(int);
void asce_ord(int*,int);
void desce_ord(int*,int);
void main(int argc,char *argv[])
{
	int i,n,*ptr,a;
	scanf("%d",&a);
	printf("%d",a);
	if(argc<=2){
		printf("enter valid no of inputs");
		exit(1);}
	else{if(argv[1][0]=='-'){
		if(argv[1][2]=='\0'){
			n=argc-2;
			ptr=(int*)calloc(n,sizeof(int));
			if(ptr==NULL){
				printf("failed allocate to memory");
				exit(1);}
			for(i=2;i<argc;i++)
				ptr[i-2]=stoi(argv[i]);
			switch(argv[1][1]){
				case 'a': for(i=0;i<argc-2;i++)
						bin_value(ptr[i]);
					break;
				case 'b': asce_ord(ptr,argc-2);
					break;
				case 'c': desce_ord(ptr,argc-2);
					break;
				case 'd':for(i=0;i<argc-2;i++)
					       if(palin(ptr[i]))
						       printf("%d\t",ptr[i]);
				       break;
				case 'h':
				       printf("\n-a:to print binary values\n-b:ascending order\n-c:desending order\n-d:to print the palindromes"); break;
				default :
				       printf("invalid flag use -h for help");}
		}
		else
		printf("invalid flag");
	}
	else 	printf("- is not used for the flag use -h for help");}
	free(ptr);
}	
int stoi(char* ptr)
{
	int i,n=0,s=1;
	for(i=0;ptr[i]!='\0';i++)
	{
		
		if(((ptr[i]>='0')&&(ptr[i]<='9'))||((ptr[i]=='-')&&(i==0)&&(ptr[i+1]!='\0')))
		{ if((ptr[i]=='-')&&(i==0))
			{
				s=-1;
				}else{

			n=n*10+(ptr[i]-48);}
		}
		else{
			printf("invalid input");
			exit(1);}
	}
	return n*s;
}
void bin_value(int n)
{
	int i;
	printf("\n%d-",n);	
	for(i=31;i>=0;i--)
		printf("%d",((n>>i)&1));
	printf("\n");
}
void asce_ord(int* ptr,int n){
	int i,j,t;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(ptr[i]>ptr[j])
			{
				t=ptr[i];
				ptr[i]=ptr[j];
				ptr[j]=t;
			}
		}
	printf("%d\t",ptr[i]);
	}
}


void desce_ord(int* ptr,int n){
	int i,j,t;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(ptr[i]<ptr[j])
			{
				t=ptr[i];
				ptr[i]=ptr[j];
				ptr[j]=t;
			}
		}
	printf("%d\t",ptr[i]);
	}
}

int palin(int n){
	int r=0,rem,t=n;
	while(n!=0)
	{
		rem=n%10;
		r=r*10+rem;
		n=n/10;
	}
	if(t==r)
		return 1;
	else return 0;
}

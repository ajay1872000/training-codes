#include<stdio.h>
#include<stdlib.h>
char* itos(char*,int );
int ccount(char*,char*,int*);
int palin(char*);
char* stcc(char*,char*);
int wc(char*,char*);
int stle(char*);
char* mystrcop(char*,char*);
int strc(char*,char*);
char* strev(char*);	
int stoi(char*);
void replace(char*,char*,char*);
void main(){
	int opt,re,n,cc[10];
	char r[100],c[100],*ret,rep[10];

	void *fp;
	while(1)
	{
		printf("\nMENU\n----------------------------------------------------------------------------------------------------------------------------------------------------\n0.exit\n1.string to integer\n2.to print string element and its repetation\n3.palindrome or not\n4.search for a string \n5.string concate\n6.string length\n7,string reverse\n8.string copy\n9.string compare\n10. string to int \n11.string replace \nenter option");
		scanf("%d",&opt);
		__fpurge(stdin);
		switch(opt){
			case 0:exit(1);
			case 1: printf("enter a string");
				scanf("%s",r);
				fp=stoi;
				re=((int(*)(char*))fp)(r);
				printf("%d",re);
				break;
			case 2:printf("enter a string");
			       scanf("%s",r);
			       fp=ccount;
			       re=((int(*)(char*,char*,int*))fp)(r,c,cc);
			       for(n=0;n<re;n++)
				       printf("%c-%d",c[n],cc[n]);
			       break;
			case 3:printf("enter a string");
		 		scanf("%s",r);
			       fp=palin;
			       if(((int(*)(char*))fp)(r))
				       printf("it is not a palindrome");
			       else
				       printf("it is a palidrome");
			       break;
			case 4:printf("enter a sentence");
			       scanf("%[^\n]s",r);
			       printf("enter search word");
			       scanf("%s",c);
			       fp=wc;
			       re=((int(*)(char*,char*))fp)(r,c);
			       if(re!=0)
				       printf("%d times repeated",re);
			       else
				       printf("not found");
			       break;

			case 5:printf("enter 1st string");
			       scanf("%s",r);
			       printf("enter 2nd string");
			       scanf("%s",c);
			       fp=stcc;
			       ret=((char*(*)(char*,char*))fp)(r,c);
			       printf("%s",ret);break;
			case 6:printf("entre string");
			       scanf("%s",r);
			       fp=stle;
			       printf("string length=%d",((int(*)(char*))fp)(r));
			       break;
			case 7:printf("enter string");
			       scanf("%s",c);
			       fp=strev;
			       printf("%s",((char*(*)(char*))fp)(c));break;
			case 8:printf("enter a string");
			       scanf("%s",c);
			       fp=mystrcop;
			       printf("%s",((char*(*)(char*,char*))fp)(r,c));
	
					       break;
		 	case 9:printf("enter 1st string");
				scanf("%s",r);
				printf("enter 2nd string");
				scanf("%s",c);
				fp=strc;
				if(((int(*)(char*,char*))fp)(r,c))
					printf("not equal");
				else
				     printf("equal");
				     break;
			case 10:printf("enter a string");
				scanf("%s",r);
				fp=stoi;
				n=((int(*)(char*))fp)(r);
				printf("%d",n);break;
			case 11: printf("enter a string");
				 scanf("%[^\n]s",r);
				 printf("enter a search string");
				 scanf("%s",c);
				 printf("enter a replace string");
				 scanf("%s",rep);
				 replace(r,c,rep);
				 break;

			default:printf("invalid case");

		}

	}
}
void replace(char* s,char* s1,char* s2){
	int s1s,ss,s2s;
	char* ds;
	int i,j,c=0,k,a;
	ss=stle(s);
	ds=(char*)calloc(ss,sizeof(char));
	if(ds==NULL)
	{
		printf("failed to allocate memory");
		return;}
	for(i=0;i<=ss;i++)
		ds[i]=s[i];
	s1s=stle(s1);
	s2s=stle(s2);

	for(i=0;ds[i]!='\0';i++){
		
		{ a=0;
			for(j=i,k=0;((ds[j]!='\0')||ds[j]!=' ');k++,j++)
			{       if(s1[k]=='\0')
				   break;
				if(ds[j]==s1[k])
					a++;
				 
				
			}
			if(a==k)
			{	if(s1s==s2s){
						    
				for(j=i,k=0;s2[k]!='\0';k++,j++)
					ds[j]=s2[k];}
					    	    else{
				if(s1s<s2s){
				ds=(char*)realloc(ds,(ss+s2s-s1s)*sizeof(char));
				if(ds==NULL)
				{
					printf("failed to reallocate memory");
					return;}
				for(j=(ss+s2s-s1s);j>i;j--)
					ds[j]=ds[j-1];
					
				for(j=i,k=0;s2[k]!='\0';k++,j++)
					ds[j]=s2[k];}

				else{
				for(j=i;j<=(ss-(s1s-s2s));j++)
					ds[j]=ds[j+(s1s-s2s)];
					
				for(j=i,k=0;s2[k]!='\0';k++,j++)
					ds[j]=s2[k];}}}
		}
	}printf("%s",ds);
}
int stoi(char* a){
	int i,s=0;
	for(i=0;a[i]!=0;i++){
		if((a[i]>='0')&&(a[i]<=57))
		{s=s*10+(a[i]-48);}
		else {printf("invalid input");
			return 0;}}
	return s;
}
char* mystrcop(char* s1,char* s2){
	int i;
	for(i=0;s2[i]!='\0';i++)
		s1[i]=s2[i];
	s1[i]='\0';
	return s1;}
int strc(char* s1,char* s2)
{ int i=0;
 for(i=0;((s1[i]!='\0')||(s2[i]!='\0'));i++)
 {
 	if(s1[i]!=s2[i])
	 return 1;}
	 return 0;
	 }

char* strev(char* r){
	int j=stle(r)-1,i;
	char t;
	for(i=0;i<j;i++,j--)
	{
		t=r[i];
		r[i]=r[j];
		r[j]=t;}
	return r;}


int stle(char* ptr){
	int i;
	for(i=0;ptr[i]!='\0';i++);
	return i;
}
char* stcc(char* s1,char* s2)
	{
		int i,j;
		for(i=0;s1[i]!='\0';i++);
		for(j=0;s2[j]!='\0';i++,j++)
			s1[i]=s2[j];
		s1[i]='\0';
		return s1;
	}
int palin(char* a){
	int i,j,k;
	for(i=0;a[i]!='\0';i++);
	char b[i];
	k=0;
	for(j=i-1;j>=0;j--,k++)
		b[k]=a[j];
	for(j=0;j<i;j++){
		{if(b[j]!=a[j])
			return 1;}
	}
	return 0;}


char* itos(char* a,int s){
	int r,j,i;
	char t;
	j=0;
	while(s!=0){
		r=(s%10)+48;
		a[j]=r;
		s=s/10;
		j++;}
	a[j]='\0';
	j--;
	for(i=0;i<j;j--,i++){
		t=a[i];
		a[i]=a[j];
		a[j]=t;}
	return a;
	}

int ccount(char* r,char* c,int* cc){
	int i,j=0,k=0,s;
	char t[10];
	for(i=0;r[i]!=0;i++)
		t[i]=r[i];
	for(i=0;t[i]!='\0';i++){
		if(t[i]!='.'){
		cc[k]=1;
		for(j=i+1;t[j]!='\0';j++)
		{
			if(t[i]==t[j])
			{
				cc[k]++;
				t[j]='.';
			}
		}
		c[k]=t[i];
		k++;
	}}
	return k;
}

int wc(char* s1,char* s2){
	int i,j,c=0,k,a;
	for(i=0;s1[i]!='\0';i++){
		
		{ a=0;
			for(j=i,k=0;((s1[j]!=' ')||(s1[j]!='\0'));k++,j++)
			{       
			     if(s2[k]=='\0')
			        break;   
				if(s1[j]==s2[k])
					a++;
				 
				
			}
			if(a==k)
				c++;
		}
		
	}return c;
}

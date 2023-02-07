#include<stdio.h>
void main(){
	int i,j;
	char s[10],t,a,b;
	printf("enter a string");
	gets(s);
	for(i=0;s[i]!='\0';i++)
	{
		for(j=i+1;s[j]!='\0';j++)
		{
			if((s[j]<=90)&&(a[j]>=65))
			b=s[j]+31;
			else b=s[j];
			if((s[i]<=90)&&(a[i]>=65))
				a=s[i]+31;
			else a=s[i];
			if(a>b){
				t=s[i];
				s[i]=s[j];
				s[j]=t;}
		}
	}
	printf("%s",s);}

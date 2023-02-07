#include<stdio.h>
void main(){
	int i,a=0,j,k,c;
	char s[100];
	printf("enter a string\n");
	scanf("%[^\n]s",s);
	for(i=0;s[i]!='\0';i++)
	{ for(j=i+1,c=1;(s[j]!=s[i]);j++,c++)
		if(s[j]=='\0')
		{ c=0;
			break;}
		if(a<c)
		{
			a=c;
			k=i;}
	}
	for(i=k;((i<=a+i)&&(s[i]!='\0'));i++)
		printf("%c",s[i]);
}

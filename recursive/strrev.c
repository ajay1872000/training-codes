#include<stdio.h>
char* strrev(char*,int,int);
void main(){
	char a[10],*c;
	int i=0,j;
	printf("enter a string");
	scanf("%s",a);
	for(j=0;a[j]!='\0';j++);
	c=strrev(a,i,j-1);
	printf("%s",a);
}
char* strrev(char* str,int i,int j){
	char t;
	if(i>=j)
		return str;
	t=str[i];
	str[i]=str[j];
	str[j]=t;
	strrev(str,i+1,j-1);
	return str;
}




#include<stdio.h>
void main(){
	int i,j;
	char str[10],t;
	printf("enter a string");
	scanf("%s",str);
	for(i=0;str[i];i++)
	{
		for(j=i+1;str[j];j++)
			if(str[i]<str[j])
			{
				t=str[i];
				str[i]=str[j];
				str[j]=t;
			}
	}
	printf("%s",str);
}


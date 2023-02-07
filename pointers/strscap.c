#include<stdio.h>
void main(){
	int i,j;
	char a[100];
	printf("enter a string");
	scanf("%[^\n]s",a);
	for(i=0;a[i]!='\0';i++)
	{
		if(((a[i-1]==' ')||(i==0))&&(a[i]>=97)&&(a[i]<=122))
			a[i]=a[i]-32;
	}
	printf("%s",a);
}

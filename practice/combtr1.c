#include<stdio.h>
void combination(char* s,int n,int c,int co,int k)
{int i,j;
	char t;
	if(co==n)
		return;

	for(i=n-2;i<n;i++){
		for(j=1;j<n;j++){
			t=s[i];
			s[i]=s[j];
			s[j]=t;}

	printf("%s\t%d\n",s,co);
	co++;}
	t=s[0];
	for(j=0;j<k;j++){
	for(i=0;s[i]!='\0';i++)
		s[i]=s[i+1];
	i--;
	s[i]=t;
	s[i+1]='\0';}
	if(c==n)
	{
		k--;
	c=0;}
	combination(s,n,++c,co,);
	return;
	}

void main()
{
	int le;
	char a[20];
	scanf("%s",a);
	for(le=0;a[le]!='\0';le++);
	combination(a,le,0,1);
}



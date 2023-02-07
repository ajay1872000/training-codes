#include<stdio.h>
void main()
{
	int i,j,k=0;
	char s[20];
	scanf("%[^\n]s",s);
	for(i=0;s[i]!='\0';i++)
	{
		for(j=i+1;s[j]!='\0';j++)
		{
			if(s[i]==s[j])
			{
				for(k=j;s[k]!='\0';k++)
					s[k]=s[k+1];
				j--;
				k=1;
			}
		}
		if(k)
		{
				for(k=i;s[k]!='\0';k++)
					s[k]=s[k+1];
				k=0;
				i--;
		
		}
	}
	printf("%s",s);
}

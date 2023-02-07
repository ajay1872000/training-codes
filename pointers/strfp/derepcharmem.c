#include<stdio.h>
#include<string.h>
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
				memmove((s+j),(s+j+1),sizeof(s)-j);
				j--;
				k=1;
			}
		}
		if(k)
		{
				memmove((s+i),(s+i+1),sizeof(s)-i);
				k=0;
				i--;
		
		}
	}
	printf("%s",s);
}

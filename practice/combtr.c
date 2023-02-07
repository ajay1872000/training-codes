#include<stdio.h>
void main(){
	int i,j,le,k,f=1,su=1,l;
	char a[10],t;
	scanf("%s",a);
	for(le=0;a[le]!='\0';le++);
	char (*s)[le+1]=NULL;
	//printf("%s\n",a);
	for(i=0;i<le;i++)
	{
		for(j=0;j<le;j++)
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
			s=(char(*)[])realloc(s,su*(le+1)*sizeof(char));
			for(l=0;l<su-1;l++)
			{
				for(k=0;a[k]!='\0';k++)
				{
					if(s[l][k]!=a[k])
					{
						f=1;
						break;
					}
					f=0;
				}
			if(f==0)
				break;

			}
			if(f)
			{
				for(k=0;a[k]!='\0';k++)
					s[su-1][k]=a[k];
				su++;
				printf("%s\n",a);\
			}
		}
	}
		printf("%d\n",su-1);
}



#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
int strtoi(int l,char *s)
{
	int n=0,k,i=1;;
	if((l==0)&&(s[0]=='-'))
		i=-1;
	for(k=l;s[k]!='\0';k++)
	{
		if(((s[k]<=57)&&(s[k]>=48))||(s[0]=='-'))
		{
			if(s[k]=='-')
				continue;
			n=(n*10)+(s[k]-48);
		}
		else{
			if(l==1)
			{
				printf("invalid signal");
				exit(1);
			}
			else
			{
				printf("invalid pid");
				exit(1);
			}
		}
	}
	return n*i;
}
void main(int args,char* argv[])
{
	int n,pid,r;
	if(args==3)
	{
		if(argv[1][0]=='-')
		{
			n=strtoi(1,argv[1]);
			printf("signal=%d",n);
			pid=strtoi(0,argv[2]);
			printf("pid=%d",pid);
			r=kill(pid,n);
			if(r==0)
				printf("succes");
			else
				printf("failure");
		}
		else
			printf("invalid flag");
	}
	else
		printf("invalid inputs");
}



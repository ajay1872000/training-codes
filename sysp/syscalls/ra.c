#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
int strtoi(char *s)
{
	int n=0,k,i=1;;
	for(k=1;s[k]!='\0';k++)
	{
		if((s[k]<=57)&&(s[k]>=48))
			n=(n*10)+(s[k]-48);
		else{
			printf("invalid signal");
			exit(1);
		}
	}
	return n;
}
void main(int args,char* argv[])
{
	int n,pid,r;
	if(args==2)
	{
		if(argv[1][0]=='-')
		{
			n=strtoi(argv[1]);
			printf("signal=%d",n);
			pid=getpid();
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



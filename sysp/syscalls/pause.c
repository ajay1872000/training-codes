#include<stdio.h>
#include<signal.h>
void main()
{
	int i=1;
	pause();
	alarm(2);
	//signal(2,SIG_IGN);
	while(i>0){
		printf("%d\n",i);
		i++;}
}


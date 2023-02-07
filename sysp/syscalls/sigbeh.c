#include<stdio.h>
#include<signal.h>
void myhandler1(int);
void myhandler2(int);
void main()
{
	int i=0;
	size_t sigset;
	pause();
	signal(2,myhandler2);
	signal(18,myhandler2);
	sigemptyset(&sigset);
	sigaddset(&sigset,2);
	sigaddset(&sigset,18);
	sigprocmask(SIG_BLOCK,&sigset,NULL);

	while(i<25)
	{
		printf("%d\n",i);
		i++;
	}
	sigdelset(&sigset,2);
	sigprocmask(SIG_UNBLOCK,&sigset,0);
}
void myhandler1(int signo)
{
	printf("signal to continue is generated\n");
	sleep(10);
}
void myhandler2(int signo)
{
	printf("signal to stop is generated\n");
	sleep(10);
}

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void myhandler(int);
void main()
{
	int i;
	size_t a;
	struct sigaction act;
	act.sa_handler=myhandler;
	act.sa_flags=0;
	sigemptyset(&act.sa_mask);
	sigaction(2,&act,0);
	sigaddset(&act.sa_mask,64);
	sigaddset(&act.sa_mask,50);
	sigprocmask(0,NULL,&a);
	printf("signal mask=%lx\n",a);
	pause();
	sigprocmask(SIG_BLOCK,&act.sa_mask,0);
	sigprocmask(0,NULL,&a);
	printf("signal mask=%lx\n",a);
	while(i<=5)
	{
		sleep(1);
		printf("%d\n",i);
		i++;
	}
	sigdelset(&act.sa_mask,50);
	sigprocmask(SIG_UNBLOCK,&act.sa_mask,0);
	sigprocmask(0,NULL,&a);
	printf("signal mask=%lx\n",a);
	sigaction(14,&act,0);
	i=0;
	while(i<=1000)
	{
		sleep(1);
		printf("%d\n",i);
		i++;
	}
}
void myhandler(int signo)
{
	printf("signal=%d is received\n",signo);
}


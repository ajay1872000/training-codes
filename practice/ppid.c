#include<stdio.h>
#include<unistd.h>
void main()
{
	int pid,ppid;
	pid=getpid();
	printf("pid=%d",pid);
	ppid=getppid();
	printf("ppid=%d",ppid);
	scanf("%d",&ppid);
}


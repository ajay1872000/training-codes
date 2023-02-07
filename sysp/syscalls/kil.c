#include<stdio.h>
#include<signal.h>
void main()
{
	int pid;
	scanf("%d\n",&pid);
	kill(pid,2);
}


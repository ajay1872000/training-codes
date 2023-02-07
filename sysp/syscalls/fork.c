#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
int a;
void main()
{
	pid_t pid,ppid;
	pid=fork();
	if(pid<0)
	{
		printf("failed to allocate memory");
		exit(1);
	}
	if(pid>0)
	{
		//sleep(2);
		printf("parent chidid=%d\n",pid);
		ppid=getpid();
		printf("parent parentid=%d\n",ppid);
		printf("parent %p,%d\n",&a,a);
		sleep(2);
		a=1000;
		while(1){
		printf("1");}
		exit(1);
	}
	else{
		a=20;
		//sleep(2);
		printf("child chidid=%d\n",pid);
		pid=getpid();
		printf("child chid id=%d\n",pid);
		ppid=getppid();
		printf("child parent id=%d\n",ppid);
		printf("parent %p,%d\n",&a,a);
		while(1)
			printf("2");
	}
}

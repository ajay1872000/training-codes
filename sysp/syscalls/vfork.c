#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
void main()
{
	pid_t pid,ppid;
	pid=vfork();
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
		while(1)
			printf("1");
		exit(0);
	}
	else{
		//sleep(2);
		printf("child chidid=%d\n",pid);
		pid=getpid();
		printf("child chid id=%d\n",pid);
		ppid=getppid();
		printf("child parent id=%d\n",ppid);
		while(1)
			printf("2");
		exit(0);
	}
}


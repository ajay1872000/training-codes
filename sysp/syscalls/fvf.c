#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
int p1,p2;
void main()
{
	pid_t pid1,ppid1,pid2,ppid2;
	pid1=fork();
	pid2=vfork();
	if((pid1<0)||(pid2<0))
	{
		printf("failed to allocate memory");
		exit(1);
	}
	if((pid1>0)&&(pid2>0))
	{
		printf("parent 1");
		exit(1);
	}
	if((pid1>0)&&(pid2==0))
	{	
		printf("child 1");
		exit(1);
	}
	if((pid1==0)&&(pid2>0))
	{
		printf("child 2");
		exit(1);
	}
	if((pid1==0)&&(pid2==0)){
		printf("child 3");
		exit(1);
	}
}

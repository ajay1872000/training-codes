#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	int ret,fd[2],bu[100];
	pid_t pid;
	ret=pipe(fd);
	pid=fork();
	if(pid<0)
	{
		printf("failed to create a child process");
		exit(1);
	}
	else if(pid>0)
	{
		close(fd[0]);
		ret=write(fd[1],"hi",strlen("hi"));
		close(fd[1]);
		exit(0);
	}
	else{
		close(fd[1]);
		ret=read(fd[0],bu,100);
		write(1,bu,ret);
		close(fd[0]);
		exit(1);
	}
}

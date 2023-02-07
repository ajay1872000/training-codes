#include<sys/wait.h>
#include<sys/types.h>
void main()
{
	pid_t pid,cpid;
	int stat=0,i=0,a=1000;
	pid=fork();
	if(pid>0)
	{
		while(a>0)
		{
			printf("2");
			a--;}
		cpid=wait(&stat);
		printf("\n%d",cpid);
		printf("\n%d",stat);
		if(WIFSTOPPED(stat))
			printf("\n%d",WSTOPSIG(stat));
		if(WIFEXITED(stat))
			printf("\n%d",WEXITSTATUS(stat));
		if(WIFSIGNALED(stat))
			printf("\n%d",WTERMSIG(stat));
	}
	else{
		printf("child=%d",getpid());
		while(i<=10)
		{
			printf("1\n");
			i++;}
		exit(10);
	}
}

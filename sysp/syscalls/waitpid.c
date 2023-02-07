#include<sys/wait.h>
#include<sys/types.h>
void main()
{
	pid_t pid,cpid;
	int stat=0,i=0,a=100;
	pid=fork();
	if(pid>0){
		while(a>0)
		{
			printf("2");
			a--;}
		wait(&stat);
	/*	cpid=waitpid(pid,&stat,WNOHANG);
		if(WIFCONTINUED(stat))
			printf("continued");*/
		printf("\n%d",cpid);
		printf("\n%d",stat);
	}
	else{
		//sleep(30);
		printf("child\n");
		a=100;
		while(a>0){
			printf("hi\n");
		//	a--;
		}
	}

		
}

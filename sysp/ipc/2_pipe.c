#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	int ret,fd1[2],fd2[2],i;
	char bu[100];
	pid_t pid;
	ret=pipe(fd1);
	ret=pipe(fd2);
	pid=fork();
	if(pid<0)
	{
		printf("failed to create a child process");
		exit(1);
	}
	else if(pid>0)
	{
		close(fd1[0]);
		close(fd2[1]);
		//write(1,"enter a string\n",strlen("enter a string\n"));
		//read(0,bu,100);
		printf("enter a string\n");
		scanf("%[^\n]s",bu);
		ret=write(fd1[1],bu,strlen(bu));
		ret=read(fd2[0],bu,100);
		write(1,bu,ret);
		close(fd1[1]);
		close(fd2[0]);
		exit(0);
	}
	else{
		close(fd1[1]);
		close(fd2[0]);
		ret=read(fd1[0],bu,100);
		bu[ret]='\0';
		for(i=0;bu[i];i++)
		{
			if((bu[i]>='A')&&(bu[i]<='Z'))
				bu[i]=bu[i]+32;
			else if((bu[i]>='a')&&(bu[i]<='z'))
				bu[i]=bu[i]-32;
		}
		ret=write(fd2[1],bu,strlen(bu));
		close(fd1[0]);
		close(fd2[1]);
		exit(1);
	}
}

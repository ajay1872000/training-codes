#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/stat.h>
#include<unistd.h>
void main()
{
	int fd,fd1,ret;
	char rbuf[100],s[100];
	fd=open("servfifo",O_RDWR);
	if(fd<0)
	{
		printf("failed to open file");
		exit(1);
	}
	printf("enter a string");
	scanf("%[^\n]s",s);
	ret=write(fd,s,strlen(s));

	fd1=open("cfifo",O_RDONLY);
	if(fd1<0)
	{
		ret=mkfifo("cfifo",0660);
		if(ret<0)
		{
			printf("failed to open");
			exit(1);
		}
		else{
			fd1=open("cfifo",O_RDONLY);
			if(fd1<0)
			{
				printf("failed to perform read operation");
				exit(1);
			}
		}
	}
	ret=read(fd1,rbuf,100);
	ret=write(1,rbuf,ret);
	close(fd);
	close(fd1);
}


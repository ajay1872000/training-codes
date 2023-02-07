#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	int fd,fd1,ret;
	char rbuf[100],wbuf[100];
	fd=open("servfifo",O_RDONLY);
	if(fd<0)
	{
		ret=mkfifo("servfifo",0660);
		if(ret<0)
		{
			printf("failed to create an fifo object");
			exit(1);
		}
		else{
			fd=open("servfifo",O_WRONLY);
			if(fd<0)
			{
				printf("failed to open file");
				exit(1);
			}
		}
	}
	fd1=open("cfifo",O_WRONLY);
	if(fd1<0)
	{
		printf("failed to open");
		exit(1);
	}
	while(1){
	ret=read(fd,rbuf,99);
	if(ret<0)
	{
		printf("failed to read");
		exit(1);
	}
	rbuf[ret]='\0';
	printf("%100s\n",rbuf);
	scanf("%[^\n]s",wbuf);
	__fpurge(stdin);
	ret=write(fd1,wbuf,strlen(wbuf));
	if(ret<0)
	{
		printf("failed to write on file");
		exit(1);
	}}
	close(fd);
	close(fd1);
}


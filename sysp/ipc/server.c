#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<fcntl.h>
void main()
{
	int ret,fd;
	char wbuf[20]="hi";
	char rbuf[20];
	fd=open("servfifo",O_RDONLY);
	if(fd<0)
	{
		ret=mkfifo("servfifo",0660);
		if(ret<0)
		{
			printf("failed to create a fifo object");
			exit(0);
		}
		else{
			fd=open("servfifo",O_RDONLY);
			if(fd<0)
			{
				printf("failed to open file");
				exit(1);
			}
		}
	}
	ret=read(fd,rbuf,20);
	if(ret<0)
	{
		printf("failed to perform read operation");
		exit(3);
	}
	ret=write(1,rbuf,ret);
	if(ret<0)
	{
		printf("failed to perform write operation");
		exit(1);
	}
	close(fd);
}

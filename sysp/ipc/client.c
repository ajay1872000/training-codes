#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/stat.h>
void main()
{
	int ret,fd;
	char buf[20],wbuf[20]="request";
	fd=open("servfifo",O_WRONLY);
	if(fd<0)
	{
		printf("failed to open file");
		exit(1);
	}
	ret=write(fd,wbuf,strlen(wbuf));
	if(ret<0)
	{
		printf("failed to write\n");
		exit(2);
	}
	close(fd);
}

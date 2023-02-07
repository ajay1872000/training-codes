#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
void main()
{
	int ret,fd,fd1;
	char rbuf[100],wbuf[100];
	fd=open("servfifo",O_WRONLY);
	if(fd<0)
	{
		printf("failed to open1");
		exit(1);
	}
	fd1=open("cfifo",O_RDONLY);
	if(fd1<0)
	{
		ret=mkfifo("cfifo",0660);
		if(ret<0)
		{
			printf("failed to create a fifo object");
			exit(1);
		}
		else{
			fd1=open("cfifo",O_RDONLY);
			if(fd<0)
			{
				printf("failed to open");
				exit(1);
			}
		}
	}
	while(1){
	scanf("%[^\n]s",wbuf);
	__fpurge(stdin);
	ret=write(fd,wbuf,strlen(wbuf));
	if(ret<0)
	{
		printf("failed to read data");
		exit(1);
	}
	ret=read(fd1,rbuf,99);
	if(ret<0)
	{
		printf("failed to read");
		exit(1);
	}
	rbuf[ret]='\0';
	printf("%100s\n",rbuf);}
	close(fd);
	close(fd1);
}

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
void main()
{
	int ret,fd,i,fd1;
	char rbuf[100],wbuf[100];
	fd=open("servfifo",O_RDONLY);
	if(fd<0)
	{
		ret=mkfifo("servfifo",0660);
		if(ret<0)
		{
			printf("failed to create a fifo object");
			exit(1);}
		else{
			fd=open("servfifo",O_RDONLY);
			if(fd<0)
			{
				printf("failed to open");
				exit(1);
			}
		}
	}
	ret=read(fd,rbuf,100);
	rbuf[ret]='\0';
	for(i=0;rbuf[i];i++)
	{
		if((rbuf[i]<='Z')&&(rbuf[i]>='A'))
			wbuf[i]=rbuf[i]+32;
		else if((rbuf[i]>='a')&&(rbuf[i]<='z'))
			wbuf[i]=rbuf[i]-32;
	}
	printf("%s",wbuf);
	fd1=open("cfifo",O_WRONLY);
	if(fd1<0)
	{
		printf("failed to open client file");
		exit(1);
	}
	ret=write(fd1,wbuf,i);
	if(ret<0)
	{
		printf("failed to perform write operation");
		exit(1);
	}
	close(fd1);
	close(fd);
}

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
void main()
{
	int fd,fd1;
	fd1=dup(1);
	close(1);
	fd=open("sample.txt",O_CREAT|O_RDWR,0664);
	printf("welcome");
	write(fd1,"printf",strlen("printf"));
}

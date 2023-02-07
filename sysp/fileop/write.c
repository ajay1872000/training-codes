#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
void main()
{
	int ret,fd;
	char a[100]="c in depth by srivastava";
	fd=open("sample2.txt",O_CREAT|O_RDWR,0764);
	printf("fd=%d",fd);
//	fd=open("sample.txt",O_RDWR);
	printf("fd=%d",fd);
	if(fd<0)
	{
		printf("failed to open");
		exit(1);
	}
	ret=write(fd,a,strlen(a));
	printf("ret=%d",ret);
	if(ret<0)
	{
		printf("failed to read");
		exit(1);
	}
	ret=close(fd);
	printf("ret=%d",ret);
}

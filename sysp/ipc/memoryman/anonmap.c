#include<stdio.h>
#include<unistd.h>
#include<sys/mman.h>
#include<fcntl.h>
void main()
{
	int *ptr;
#ifdef USE_MAP_ANON
	ptr=mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS,-1,0);
	printf("if\n");
#else
	int fd=open("/dev/zero",O_RDWR);
	printf("else\n");
	ptr=mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS,fd,0);
	close(fd);
#endif
	int pid=fork();
	if(pid>0)
	{
		sleep(10);
		printf("parent process");
		exit(0);
	}
	else
	{
		*ptr=4;
		printf("child proces %d\n",*ptr);
		exit(1);
	}
}





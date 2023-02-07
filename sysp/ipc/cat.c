#include<stdio.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<unistd.h>
void main(int argc,char* argv[])
{
	int i,fd;
	char *ptr;
	struct stat buf;
	if(argc>=2)
	{
		for(i=1;i<=argc;i++)
		{
			fd=open(argv[i],O_RDWR);
			if(fd<0)
			{
				printf("failed to open file");
				exit(1);
			}
			fstat(fd,&buf);
			ptr=mmap(NULL,buf.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
			write(1,ptr,buf.st_size);
			close(fd);
		}
	}
	else{
		printf("invalid no of inputs");
	}
}



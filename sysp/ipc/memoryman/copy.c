#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/mman.h>
void main(int argc,char* argv[])
{
	int i,ret,fd2,ret1,fd1;
	char  *ptr2,*ptr1;
	struct stat buf1,buf2;
	if(argc==3)
	{
		fd1=open(argv[1],O_RDONLY);
		if(fd1<0)
		{
			printf("failed to open source file");
			exit(1);
		}
		ret=chdir(argv[2]);
		if(ret==0)
		{
			fd2=open(argv[1],O_CREAT|O_RDWR,0664);
			if(fd2<0)
			{
				printf("failed to open file1");
				exit(1);
			}
		}
		else{
			fd2=open(argv[2],O_CREAT|O_RDWR,0664);
			if(fd2<0)
			{
				printf("failed to open file");
				exit(1);
			}
		}
		fstat(fd1,&buf1);
		ptr1=mmap(NULL,buf1.st_size,PROT_READ,MAP_SHARED,fd1,0);
		if(ptr1==NULL)
		{
			printf("failed to allocate memory");
			exit(1);
		}
		ftruncate(fd2,buf1.st_size);
		printf("%ld",buf1.st_size);
		fstat(fd2,&buf2);
		printf("\n%ld\n",buf2.st_size);
		ptr2=mmap(NULL,buf2.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd2,0);
		if(ptr2==NULL)
		{
			printf("failed to allocate memory");
			exit(1);
		}
		memcpy(ptr2,ptr1,buf1.st_size);
		close(fd2);
		close(fd1);
	}
}


			
		

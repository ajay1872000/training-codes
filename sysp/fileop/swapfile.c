#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
void main(int argc,char* argv[])
{
	int ret1,ret2,fd1,fd2,fs1,fs2;
	char *a,*b;
	if(argc==3)
	{
		fd1=open(argv[1],O_RDWR);
		if(fd1<0)
		{
			printf("failed to open");
			exit(1);
		}
		fs1=lseek(fd1,0,SEEK_END);
		lseek(fd1,0,SEEK_SET);
		fd2=open(argv[2],O_RDWR);
		if(fd2<0)
		{
			printf("failed to open");
			exit(1);
		}
		fs2=lseek(fd2,0,SEEK_END);
		lseek(fd2,0,SEEK_SET);
		a=(char*)malloc(fs1*sizeof(char));
		if(a==NULL)
		{
			printf("failed to allocate memory");
			exit(1);
		}
		b=(char*)malloc(fs2*sizeof(char));
		if(a==NULL)
		{
			printf("failed to allocate memory");
			exit(1);
		}
		ret1=read(fd1,a,fs1+10);
		ret2=read(fd2,b,fs2+10);
		close(fd1);
		fd1=open(argv[1],O_TRUNC|O_RDWR,0664);
		close(fd2);
		fd2=open(argv[2],O_TRUNC|O_RDWR,0664);
		if(fd2<0){
			printf("failed to openfile");
			exit(1);}
		ret2=write(fd2,a,ret1);
		ret1=write(fd1,b,ret2);
		free(a);
		free(b);
	}
	else{
		printf("invalid no of inputs");
	}
}



	





#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
void main(int argc,char* argv[],char *env[])
{
	int fd1,ret1,fd2,ret2,n,ret;
	char buf1[20],*cptr;
	if(argc>=3){
		fd1=open(argv[1],O_RDONLY);
		if(fd1<0)
		{
			printf("source file not found");
			exit(2);
		}
		n=strlen(argv[2]);
		if((strcmp(argv[2],env[14]))&&(n>1))
		{
			ret=chdir(argv[2]);
			if(ret==0)
			{
				fd2=open(argv[1],O_RDWR|O_CREAT,0664);
				if(fd2<0)
				{
					printf("failed to create a new file");
					exit(1);
				}

			}
			else{

				fd2=open(argv[2],O_RDWR|O_CREAT,0664);
				if(fd2<0)
				{
					printf("failed to create a new file");
					exit(1);
				}
			}

		}
		else{
				printf("file cannot be create in the same directory of same name");
				exit(1);
		}

		do{
			ret1=read(fd1,&buf1,20);
			ret2=write(fd2,&buf1,ret1);
		}while(ret1!=0);
		close(fd1);
		close(fd2);
		remove(argv[1]);
	}
	else{
		printf("invalid no of inputs");
	}	
}






#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
int strcomp(char* str1,char* str2)
{
	int i;
	for(i=0;str2[i]&&str1[i];i++)
		if(str2[i]!=str1[i])
			return 1;
	return 0;
}
void main(int argc,char* argv[],char *env[])
{
	int fd1,ret1,fd2,ret2,n,ret,m;
	char buf1[20],*cptr;
	if(argc>=3){
		fd1=open(argv[1],O_RDONLY);
		if(fd1<0)
		{
			printf("source file not found");
			exit(2);
		}
		n=strlen(argv[2]);
		printf("\n%s",&env[14][4]);
		printf("\n%s\n",argv[2]);
		m=strcomp(&env[14][4],argv[2]);
		printf("%d",m);
		if(m&&(n>1))
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
	}
	else{
		printf("invalid no of inputs");
	}	
}






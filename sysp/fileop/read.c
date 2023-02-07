#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
void main(int args,char* argv[])
{
	int ret,fd,i;
	char a[5];
	if(args>=2)
	{
		for(i=1;argv[i];i++)
		{
		fd=open(argv[i],O_RDONLY);
		if(fd<0)
		{
			printf("failed to open a file");
			exit(1);
		}
		while(ret=read(fd,a,4))
		{
			if(ret<0)
			{
				printf("failed to read the file");
				exit(1);
			}
			a[ret]='\0';
			printf("%s",a);
		}close(fd);
		}

	}
	else{
		printf("insufficient inputs");}
}

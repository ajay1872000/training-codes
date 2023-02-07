#include<unistd.h>
void main(int argc,char *argv[])
{

	int a,pid;
		//a=execl("/bin/ps","ps","-ef",0);
	pid=fork();
	if(pid<0)
	{
		printf("failed to create a child");
		exit(10);
	}`
	if(pid==0)
	{
		a=execvp(&argv[1][2],&argv[2]);
	}
	else
	{
		printf("parent");
	}

}

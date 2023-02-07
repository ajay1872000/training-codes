#include<stdio.h>
void main(int argc,char *argv[])
{
	int i;
	if(argc>=2)
	{
		for(i=1;i<argc;i++)
			remove(argv[i]);
	}
	else{
		printf("invalid no of inputs");
	}
}



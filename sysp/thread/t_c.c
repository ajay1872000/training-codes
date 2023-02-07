#include<stdio.h>
#include<pthread.h>
void* mythread(void *ptr)
{
	int i;
	printf("mythread is invoked");
	for(i=0;i<=*(int*)ptr;i++)
		printf("%d\n",i);
}
void main()
{
	pthread_t ti;
	int i,ret,loop=10;
	ret=pthread_create(&ti,0,mythread,&loop);
	//sleep(1);
	pthread_exit(NULL);
	//exit(0);
}


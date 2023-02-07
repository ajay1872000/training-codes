#include<pthread.h>
#include<pthread.h>
void* mythread()
{
	int i=0;
	while(1)
	{
		printf("thread:%d\n",i);
		sleep(1);
		i++;
	}
}
void main()
{
	pthread_t ti;
	int i=0,j;
	pthread_create(&ti,0,mythread,&j);
	while(1)
	{
		scanf("%d",&i);
		printf("main thread:%d\n",i);
		sleep(1);
		i++;
	}
}

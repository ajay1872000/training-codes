#include<unistd.h>
#include<pthread.h>
#include<stdio.h>
int a;
pthread_mutex_t mtx=PTHREAD_MUTEX_INITIALIZER;
void* mythread1(void *argv)
{
	int i,loop,local;
	loop=*(int*)argv;
	for(i=0;i<loop;i++)
	{
		printf("before lock thread-1: %d\n",a);
		pthread_mutex_lock(&mtx);
		local=a;
		local++;
		a=local;
		pthread_mutex_unlock(&mtx);
		printf("after lock thread-1: %d\n",a);
	}
}
void* mythread2(void *argv)
{
	int i,loop,local;
	loop=*(int*)argv;
	for(i=0;i<loop;i++)
	{
		printf("before lock thread-2: %d\n",a);
		pthread_mutex_lock(&mtx);
		local=a;
		local++;
		a=local;
		pthread_mutex_unlock(&mtx);
		printf("after lock thread-2: %d\n",a);
	}
}
void main()
{
	void *ret;
	int res,loop=3;
	pthread_t t1,t2;
	pthread_create(&t1,0,mythread1,&loop);
	printf("thread-1 : %lu\n",t1);
	pthread_create(&t2,0,mythread2,&loop);
	printf("thread-2 : %lu\n",t2);
	pthread_join(t1,&ret);
	pthread_join(t2,&ret);
	printf("\n%d",a);
}

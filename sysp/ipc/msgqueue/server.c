#include<stdio.h>
#include<sys/msg.h>
#define KEY 0x1199887
#define MSG_TYPE 1
struct msg{
	long int msgtype;
	long int pid;
	char rbuf[100];
};
void main()
{
	int msgid;
	char buf[100];
	struct msg msg;
	msgid=msgget(KEY,IPC_CREAT|0664);
	if(msgid<0)
	{
		printf("failed to create a message queue");
		exit(1);
	}
	msgrcv(msgid,buf,100,MSG_TYPE,0);
	printf("%s",buf+2*sizeof(long int));
	//msgctl(msgid,IPC_RMID,NULL);
}

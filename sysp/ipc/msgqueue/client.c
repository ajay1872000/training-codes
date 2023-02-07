#include<stdio.h>
#include<sys/msg.h>
#define KEY 0X1199887
#define MSG_TYPE 1
struct msg{
	long int msgtype;
	long int pid;
	char buf[100];
};
void main()
{
	int msgid;
	struct msg message;
	msgid=msgget(KEY,0);
	if(msgid<0)
	{
		printf("failed to get id");
		exit(1);
	}
	message.msgtype=MSG_TYPE;
	message.pid=getpid();
	strcpy(message.buf,"hello");
	msgsnd(msgid,&message,2*sizeof(long int)+strlen(message.buf)+1,0);
}



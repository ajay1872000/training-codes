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
	int msgid,i;
	char buf[100];
	struct msg message;
	msgid=msgget(KEY,IPC_CREAT|0664);
	if(msgid<0)
	{
		printf("failed to create a message queue");
		exit(1);
	}
	message.msgtype=MSG_TYPE;
	message.pid=getpid();
	msgrcv(msgid,buf,100,MSG_TYPE,0);
	printf("%s",buf+2*sizeof(long int));
	strcpy(message.rbuf,buf+2*sizeof(long int));
	for(i=0;message.rbuf[i];i++)
	{
		if((message.rbuf[i]>='A')&&(message.rbuf[i]<='Z'))
			message.rbuf[i]=message.rbuf[i]+32;
		else 
			if((message.rbuf[i]>='a')&&(message.rbuf[i]<='z'))
				message.rbuf[i]=message.rbuf[i]-32;
	}
	msgsnd(msgid,&message,2*sizeof(long int)+strlen(message.rbuf)+1,0);
}

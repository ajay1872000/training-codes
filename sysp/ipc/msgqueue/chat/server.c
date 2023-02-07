#include<stdio.h>
#include<sys/msg.h>
#define KEY 0x1199887
#define MSG_TYPE 1
struct msg{
	//long int msgtype;
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
	//message.msgtype=MSG_TYPE;
	while(1){
	msgrcv(msgid,buf,100,MSG_TYPE,0);
	message.pid=((long int *)buf)[0];
	printf("%ld",message.pid);
	printf("%100s\n",buf+2*sizeof(long int));
	scanf("%[^\n]s",message.rbuf);
	__fpurge(stdin);
	msgsnd(msgid,&message,1*sizeof(long int)+strlen(message.rbuf)+1,0);
	}
}

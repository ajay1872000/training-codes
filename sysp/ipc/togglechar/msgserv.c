#include<stdio.h>
#define KEY 0x11998844
#define MSG_INPUT 1
void main()
{
	char buf[100];
	int msgid;
	msgid=msgget(KEY,IPC_CREATE|

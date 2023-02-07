#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<arpa/inet.h>
struct profile{
	long unsigned int userid;
	char name[32];
};
void main()
{
	int sockfd,ret,r;
	struct profile p;
	p.userid=123;
	struct sockaddr_in serv;
	char buf[256]="hi";
	sockfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	bzero(&serv,sizeof(serv));
	serv.sin_addr.s_addr=inet_addr("127.0.0.1");
	serv.sin_port=htons(5000);
	serv.sin_family=AF_INET;
	connect(sockfd,(struct sock_addr*)&serv,sizeof(serv));
	ret=send(sockfd,"hi",strlen("hi"),0);
	ret=recv(sockfd,&r,sizeof(int),0);

}


#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>
#include<netinet/in.h>
struct profile{
	long unsigned int userid;
	char name[32];
};
void main()
{
	int sockfd,newsockfd,clientsize,ret;
	char buf[256];
	//enum sock_type st;
	struct sockaddr_in serv,client;
	sockfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	bzero(&serv,sizeof(serv));
	serv.sin_family=AF_INET;
	serv.sin_port=htons(5000);
	serv.sin_addr.s_addr=INADDR_ANY;
	bind(sockfd,(struct sockaddr*)&serv,sizeof(serv));
	listen(sockfd,5);
	clientsize=sizeof(client);
	newsockfd=accept(sockfd,(struct sockaddr*)&client,&clientsize);
	ret=read(newsockfd,&p,sizeof(profile));
	write(1,p->userid,ret);
	ret=write(newsockfd,ret,sizeof(ret));
	close(newsockfd);
}

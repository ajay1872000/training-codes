#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include"head.h"
int strcomp(char* s1,char* s2)
{
	int i;
	for(i=0;s1[i]&&s2[i];i++)
		if(s1[i]!=s2[i])
			return -1;
	if(s1[i]!=s2[i])
		return -1;
	return 0;
}
void regis(int fd,struct regis pro){
	int ret,pfd,tfd;
	char a[10];
	printf("register function invoked\n");
	sprintf(a,"%lu",pro.u_id);
	ret=mkdir(a,0777);
	if(ret<0)
	{
		ret=-1;
		send(fd,&ret,sizeof(int),0);
		return;
	}
	ret=chdir(a);
	if(ret<0)
	{
		ret=-1;
		send(fd,&ret,sizeof(int),0);
		return;
	}
	pfd=open("profile.txt",O_CREAT|O_RDWR,0777);
	if(pfd<0)
	{
		printf("failed to create profile");
		exit(0);
	}
	tfd=open("transcantion.txt",O_CREAT|O_RDWR,0777);
	if(tfd<0)
	{
		printf("failed to create profile");
		exit(0);
	}
	ret=write(pfd,&pro,sizeof(struct regis));
	if(ret<0)
	{
		printf("failed to write on profile");
		exit(0);
	}
	ret=3;
	send(fd,&ret,sizeof(int),0);
	close(pfd);
	close(tfd);
}
		
void login(int fd,struct login l)
{
	int ret,pfd,opt,tfd,i;
	struct tm *ptr;
	time_t t;
	struct regis pro;
	char a[100];
	int am;
	sprintf(a,"%lu",l.u_id);
	ret=chdir(a);
	if(ret<0)
	{
		send(fd,&ret,sizeof(int),0);
		return;}
	pfd=open("profile.txt",O_RDWR);
	if(pfd<0)
	{
		send(fd,&pfd,sizeof(int),0);
		printf("failed to open file");
		exit(1);
	}
	ret=read(pfd,&pro,sizeof(struct regis));
	if(ret<0)
	{
		send(fd,&ret,sizeof(int),0);
		printf("failed to open file");
		exit(1);
	}
	tfd=open("transcantion.txt",O_CREAT|O_RDWR,0777);
	if(tfd<0)
	{
		printf("failed to create profile");
		exit(0);
	}
	ret=strcomp(pro.pass,l.pass);
	if(ret!=0)
	{
		send(fd,&ret,sizeof(int),0);
		return;}
		send(fd,&ret,sizeof(int),0);
	while(1)
	{
		recv(fd,&opt,sizeof(int),0);
		send(fd,&opt,sizeof(int),0);
		switch(opt)
		{
			case 1:recv(fd,&am,sizeof(int),0);
			       lseek(pfd,0,SEEK_SET);
			       ret=read(pfd,&pro,sizeof(struct regis));
			       if(ret<0)
			       {
				       printf("failed to read file");
				       exit(0);}
			       pro.bal=pro.bal+am;
			       lseek(pfd,0,SEEK_SET);
			       printf("%d",pro.bal);
			       write(pfd,&pro,sizeof(struct regis));
			       printf("%d\n",pro.bal);
			       send(fd,&pro.bal,sizeof(int),0);
			       lseek(tfd,0,SEEK_END);
			       write(tfd,"credit amount:",strlen("credit amount:"));
			       sprintf(a,"%d",am);
			       write(tfd,a,strlen(a));
			       write(tfd,"balance amount:",strlen("balance amount:"));
			       sprintf(a,"%u",pro.bal);
			       write(tfd,a,strlen(a));
			       t=time(NULL);
			       ptr=localtime(&t);
			       write(tfd," ",strlen(" "));
			       strcpy(a,asctime(ptr));
			       write(tfd,a,strlen(a));
			       write(tfd,"\n",strlen("\n"));
			       break;
			case 2:recv(fd,&am,sizeof(int),0);
			       lseek(pfd,0,SEEK_SET);
			       ret=read(pfd,&pro,sizeof(struct regis));
			       if(ret<0)
			       {
				       printf("failed to read file");
				       exit(0);}
			       if(pro.bal>=am){
			       pro.bal=pro.bal-am;
			       lseek(pfd,0,SEEK_SET);
			       printf("%d\n",pro.bal);
			       write(pfd,&pro,sizeof(struct regis));
			       send(fd,&pro.bal,sizeof(int),0);
			       ret=0;
				       send(fd,&ret,sizeof(int),0);
			       lseek(tfd,0,SEEK_END);
			       write(tfd,"debit amount:",strlen("debit amount:"));
			       sprintf(a,"%d",am);
			       write(tfd,a,strlen(a));
			       write(tfd,"balance amount:",strlen("balance amount:"));
			       sprintf(a,"%u",pro.bal);
			       write(tfd,a,strlen(a));
			       t=time(NULL);
			       ptr=localtime(&t);
			       write(tfd," ",strlen(" "));
			       strcpy(a,asctime(ptr));
			       write(tfd,a,strlen(a));
			       write(tfd,"\n",strlen("\n"));
			       }else
			       {
				       send(fd,&pro.bal,sizeof(int),0);
				       ret=-1;
				       send(fd,&ret,sizeof(int),0);}
			       break;
			case 3:
			       lseek(pfd,0,SEEK_SET);
			       ret=read(pfd,&pro,sizeof(struct regis));
			       if(ret<0)
			       {
				       printf("failed to read file");
				       exit(0);}
			       send(fd,&pro.bal,sizeof(int),0);break;
			case 4:
			       lseek(pfd,0,SEEK_SET);
			       ret=read(pfd,&pro,sizeof(struct regis));
			       send(fd,&pro,sizeof(struct regis),0);break;
			case 5:i=1;
			       lseek(tfd,0,SEEK_SET);
			       while(i>0)
			       {
				       i=read(tfd,a,sizeof(a));
				       printf("%d\n",i);
				       if(i<0)
					       i=-1;
				       send(fd,&i,sizeof(int),0);
				       if(i>0)
					       send(fd,a,i,0);
			       }break;
			case 6:close(pfd);
			       close(tfd);
			       printf("\nlogout succesfully\n");
			       return;
		}
	}
}	
void main(int argc,char* argv[],char* env[])
{
	struct sockaddr_in serv,cli;
	struct regis pro;
	struct login l;
	char buf[100],add[100];
	int sfd,cfd,ret,cls,opt;
	sfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	ret=chdir("database");
	if(ret<0)
	{
		ret=mkdir("database",0777);
		if(ret<0)
		{
			printf("failed to create director");
			exit(1);
		}
		ret=chdir("database");
		if(ret<0)
		{
			printf("failed to open directory");
			exit(1);
		}
	}
	bzero(&serv,sizeof(serv));
	serv.sin_family=AF_INET;
	serv.sin_addr.s_addr=INADDR_ANY;
	serv.sin_port=htons(6006);
	ret=bind(sfd,(struct sockaddr*)&serv,sizeof(serv));
	if(ret<0)
	{
		printf("failed to bind");
		exit(0);}
	listen(sfd,5);
	cls=sizeof(cli);
	cfd=accept(sfd,(struct sockaddr*)&cli,&cls);
	if(cfd<0)
	{
		printf("failed to connect");
		exit(0);}
	printf("----------------------------------Connect----------------------------------------\n");
	while(1){
		recv(cfd,&opt,sizeof(int),0);
		send(cfd,&opt,sizeof(int),0);
		ret=chdir(env[14]+4);
		if(ret<0)
		{
			ret=chdir(env[15]+4);
			if(ret<0)
			{
				printf("failed open dir");
				exit(1);
			}
		}
		ret=chdir("database");
		if(ret<0)
		{
			printf("failed open dir");
			exit(1);
		}
		printf("%d\n",opt);
		switch(opt)
		{
			case 0:exit(0);
			case 1:recv(cfd,&l,sizeof(struct login),0);
			       login(cfd,l);break;
			case 2:recv(cfd,&pro,sizeof(struct regis),0);
			       regis(cfd,pro);
			      
			       break;
			default:printf("invalid choice");
		}
	}

}

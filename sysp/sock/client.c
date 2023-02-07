#include<arpa/inet.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<time.h>
#include"head.h"
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<stdio_ext.h>
void regis(int fd)
{
	int opt1=1,i=0,ret;
	struct regis pro;
	time_t t;
	struct tm* ptr;
	t=time(NULL);
	ptr=localtime(&t);
	strcpy(pro.rdt,asctime(ptr));
	printf("%s\n",pro.rdt);
	do{
	printf("enter user id");
	scanf("%lu",&pro.u_id);
	__fpurge(stdin);
	i++;
	if((pro.u_id>=10000000)&&(pro.u_id<=99999999))
		break;
	else
	{
		printf("\n enter a valid user id");
		if(i>=2)
		{	
			printf("\nregistration is unsuccesfull");
			return;}
	}
	}while(i<3);
	i=0;
	do{
	printf("enter phone number");
	scanf("%lu",&pro.phno);
	__fpurge(stdin);
	i++;
	if((pro.phno>=1000000000)&&(pro.phno<=9999999999))
		break;
	else
	{
		printf("\n enter a valid phone number");
		if(i>=3)
		{
			printf("\nregistration is unsuccesfull");
			return;}
	}
	}while(i<3);
	i=0;
	do{
	printf("enter adhaar number");
	scanf("%lu",&pro.adno);
	__fpurge(stdin);
	i++;
	if((pro.adno>=100000000000)&&(pro.adno<=999999999999))
		break;
	else
	{
		printf("\n enter a valid adhaar number");
		if(i>=3)
		{
			printf("\nregistration is unsuccesfull");
			return;}
	}
	}while(i<3);
	
	i=0;
	do{printf("\nenter passwor");
	scanf("%s",pro.pass);
	__fpurge(stdin);
	i++;
	ret=strlen(pro.pass);
	if((ret<=16)&&(ret>=8))
		break;
	else
	{
		printf("\nenter a valid password");
		if(i>=3)
		{
			printf("\nregistration was unsuccesful");
			return;}
	}
	}while(i<3);
	printf("enter name");
	scanf("%s",pro.name);
	__fpurge(stdin);
	printf("enter gender");
	scanf("%c",&pro.gen);
	__fpurge(stdin);
	printf("enter house number");
	scanf("%s",pro.add.hno);
	__fpurge(stdin);
	pro.bal=0;
	printf("enter your area");
	scanf("%s",pro.add.area);
	__fpurge(stdin);
	printf("enter your location");
	scanf("%s",pro.add.location);
	__fpurge(stdin);
	printf("enter your state");
	scanf("%s",pro.add.state);
	__fpurge(stdin);
	printf("enter your area pincode");
	scanf("%lu",&pro.add.pincode);
	__fpurge(stdin);
	printf("enter your date of birth as dd mm yyyy");
	scanf("%d %d %d",&pro.dob.d,&pro.dob.m,&pro.dob.y);
	__fpurge(stdin);
	printf("enter your nominee name");
	scanf("%s",pro.n.name);
	__fpurge(stdin);
	i=0;
	do{
	printf("enter nominee adhaar number");
	scanf("%lu",&pro.n.adno);
	__fpurge(stdin);
	i++;
	if((pro.n.adno>=100000000000)&&(pro.n.adno<=999999999999))
		break;
	else
	{
		printf("\n enter a valid adhaar number");
		if(i>=3)
		{
			printf("\nregistration is unsuccesfull");
			return;}
	}
	}while(i<3);
	do{
	printf("enter nominee  phone number");
	scanf("%lu",&pro.n.phno);
	__fpurge(stdin);
	i++;
	if((pro.phno>=1000000000)&&(pro.phno<=9999999999))
		break;
	else
	{
		printf("\n enter a valid phone number");
		if(i>=3)
		{
			printf("\nregistration is unsuccesfull");
			return;}
	}
	}while(i<3);
	pro.acno=pro.u_id+pro.adno;
	send(fd,&pro,sizeof(struct regis),0);
		printf("\ndata sent  succesful");
	recv(fd,&ret,sizeof(int),0);
	if(ret>0)
		printf("\nregistraton succesful");
	else
		printf("\nregistration unsuccesful");
}
void login(int fd)
{
	struct login l;
	int ret,opt,a,i;
	struct regis pro;
	char b[101];
	printf("enter login id");
	scanf("%lu",&l.u_id);
	__fpurge(stdin);
	printf("enter login pass");
	scanf("%s",l.pass);
	__fpurge(stdin);
	send(fd,&l,sizeof(struct login),0);
	recv(fd,&ret,sizeof(int),0);
	if(ret<0)
	{
		printf("userid not found try again");
		return;}
	else{if(ret>0)
	{
		printf("userid not found try again");
		return;}
	else{
		printf("login successfully");
	}}
	while(1){
		printf("\nlogin menu\n1.deposit\n2.withdraw\n3.balance\n4.profile\n5.transaction history\n6.logout\nenter your choice");
		scanf("%d",&opt);
		send(fd,&opt,sizeof(int),0);
		recv(fd,&opt,sizeof(int),0);
		switch(opt)
		{
			case 1:	printf("enter deposite amount");
			       scanf("%d",&a);
			       printf("credited amount:%d\n",a);
			       send(fd,&a,sizeof(int),0);
			       recv(fd,&ret,sizeof(int),0);
			       printf("balance:%u",ret);
			       break;
			case 2:printf("enter withdraw amount");
			       scanf("%d",&a);
			       printf("debited amount:%d\n",a);
			       send(fd,&a,sizeof(int),0);
			       recv(fd,&a,sizeof(int),0);
			       recv(fd,&ret,sizeof(int),0);
			       printf("balance:%u",a);break;
			       if(ret<0)
				       printf("insufficient balance\n");
			case 3:recv(fd,&a,sizeof(int),0);
			       printf("balance:%d",a);break;
			case 4:recv(fd,&pro,sizeof(struct regis),0);
			       printf("-------------------PROFILE----------------------------------\n");
			       printf("userid :%lu\n",pro.u_id);
			       printf("user name :%s\n",pro.name);
			       printf("phone number :%lu\n",pro.phno);
			       printf("adhaar number :%lu\n",pro.adno);
			       printf("account number :%lu\n",pro.acno);
			       printf("balance :%u\n",pro.bal);
			       printf("user gender :%c\n",pro.gen);
			       printf("user register time :%s\n",pro.rdt);
			       printf("user area :%s\n",pro.add.area);
			       printf("user location :%s\n",pro.add.location);
			       printf("user state :%s\n",pro.add.state);
			       printf("user pincode :%lu\n",pro.add.pincode);
			       printf("nominee name :%s\n",pro.n.name);
			       printf("nominee adhar number :%lu\n",pro.n.adno);
			       printf("nominee phone number :%lu\n",pro.n.phno);

			       break;
			case 5:i=1;
                               while(i>0)
                               {
                                       recv(fd,&i,sizeof(int),0);
                                       if(i>0)
                                               recv(fd,b,i,0);
                                       write(1,b,i);
                               }printf("-----------end of transaction history------------------\n");
			       break;

			case 6:printf("logout succesfully");
			       return;
		}
	}
}
	




void main()
{
	struct sockaddr_in serv;
        int cifd,cfd,ret,opt1;
        char buf[10];
        cfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
        bzero(&serv,sizeof(serv));
        serv.sin_family=AF_INET;
        serv.sin_addr.s_addr=inet_addr("127.0.0.1");
        serv.sin_port=htons(6006);
        cifd=connect(cfd,(struct sockaddr*)&serv,sizeof(serv));
        if(cifd<0)
        {
                printf("failed to connect");
                exit(0);}
        printf("----------------------------------Connect----------------------------------------\n");
	while(1)
	{
		printf("\nMenu\n0.exit\n1.login\n2.register\nenter your choice");
		scanf("%d",&opt1);
	send(cfd,&opt1,sizeof(int),0);
	recv(cfd,&opt1,sizeof(int),0);
	__fpurge(stdin);
		switch(opt1)
		{
			case 0:
			       exit(0);
			case 1:login(cfd);break;
			case 2:
			       regis(cfd);break;
			default: printf("wrong choice");break;
		}
	}
}

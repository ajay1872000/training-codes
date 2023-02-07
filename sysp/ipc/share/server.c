#include<stdio.h>
#include<sys/shm.h>
#include<sys/sem.h>
#define KEY 0x12345678
void main()
{
	int shmid,semid,ret;
	char *ptr;
	struct sembuf buf;
	shmid=shmget(KEY,512,IPC_CREAT|0660);
	semid=semget(KEY,2,IPC_CREAT|0640);
	ret=semctl(semid,0,SETVAL,0);
	ret=semctl(semid,1,SETVAL,0);
	buf.sem_num=0;
	buf.sem_op=-1;
	buf.sem_flg=0;
	ret=semop(semid,&buf,1);
	ptr=shmat(shmid,NULL,0);
	printf("%s",ptr);
	strcpy(ptr+256,"hi");
	buf.sem_num=1;
	buf.sem_op=+1;
	buf.sem_flg=0;
	ret=semop(semid,&buf,1);
	shmdt(ptr);
}


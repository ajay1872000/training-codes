#include<stdio.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include<string.h>
#define KEY 0X12345678
void main()
{
	int shmid,semid,ret;
	char *ptr;
	struct sembuf buf;
	shmid=shmget(KEY,512,0);
	semid=semget(KEY,2,0);
	ptr=shmat(shmid,NULL,0);
	strcpy(ptr,"Hello");
	buf.sem_num=0;
	buf.sem_op=+1;
	buf.sem_flg=0;
	semop(semid,&buf,1);
	buf.sem_num=1;
	buf.sem_op=-1;
	buf.sem_flg=0;
	semop(semid,&buf,1);
	printf("%s",ptr+256);
	shmdt(ptr);
}

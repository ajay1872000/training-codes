#include<stdio.h>
void main(){
	int i=10;
	int* ip=NULL;
	char c='c';
	char* cp=NULL;
	float f=5.78;
	float* fp=NULL;
	double d=89.23;
	double* dp=NULL;
	printf("\nip=%p-&i=%p-i=%d-size(ip)=%d-size(i)=%d",ip,&i,i,sizeof(ip),sizeof(i));
	printf("\ncp=%p-&c=%p-c=%c-size(cp)=%d-size(c)=%d",cp,&c,c,sizeof(cp),sizeof(c));
	printf("\nfp=%p-&f=%p-f=%f-size(fp)=%d-size(f)=%d",fp,&f,f,sizeof(fp),sizeof(f));
	printf("\ndp=%p-&d=%p-d=%f-size(dp)=%d-size(d)=%d",dp,&d,d,sizeof(dp),sizeof(d));
	printf("\n after intialisation");
	ip=&i;
	fp=&f;
	cp=&c;
	dp=&d;
	printf("\nip=%p-&i=%p-i=%d-size(ip)=%d-size(i)=%d",ip,&i,i,sizeof(ip),sizeof(i));
	printf("\ncp=%p-&c=%p-c=%c-size(cp)=%d-size(c)=%d",cp,&c,c,sizeof(cp),sizeof(c));
	printf("\nfp=%p-&f=%p-f=%f-size(fp)=%d-size(f)=%d",fp,&f,f,sizeof(fp),sizeof(f));
	printf("\ndp=%p-&d=%p-d=%f-size(dp)=%ld-size(d)=%ld",dp,&d,d,sizeof(dp),sizeof(d));
}



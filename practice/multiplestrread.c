/*multiple strings read and sort in asceding order*/
#include<stdio.h>
#include<stdlib.h>
char* strread(){
	int i=0;
	char* ptr=NULL;
	do{
		ptr=(char*)realloc(ptr,(i+1)*sizeof(char));
		ptr[i]=getchar();
	}while(ptr[i++]!='\n');
	ptr[i-1]='\0';
	return ptr;
}
int strcomp(char* a,char* b){
	int i;
	for(i=0;((a[i]!='\0')||(b[i]!='\0'));i++)
	{
		if(a[i]<b[i])
			return 1;
		else if(a[i]>b[i])
			return -1;
	}
	return 0;}
void main(){
	int n,i,o,j;
	scanf("%d",&n);
	__fpurge(stdin);
	char *str[10],*t;
	for(i=0;i<n;i++)
		str[i]=strread();
	printf("-----------------------------------------------------\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			o=strcomp(str[i],str[j]);
			if(o>0)
			{t=str[i];
				str[i]=str[j];
				str[j]=t;}
		}
	}


	for(i=0;i<n;i++)
		printf("%s\n",str[i]);
}



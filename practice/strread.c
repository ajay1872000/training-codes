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
void main(){
	char *str;
	str=strread();
	printf("%s",str);
}



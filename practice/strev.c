#include<stdio.h>
char* strcp (char*const,char*const);
void main(){
	char a[10]="",b[10]="bye";
	char* c;
	c=strcp(a,b);
	printf("%s",c);
}
char* strcp(char*const a,char*const c){
       int i;
for(i=0;c[i]!='\0';i++){ 
 a[i]=c[i];}
a[i]='\0';
return a;}	



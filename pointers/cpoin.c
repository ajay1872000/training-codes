#include<stdio.h>
void main(){
	unsigned int x=0x414243445;
	unsigned char *cp=&x;
	printf("%x-%d-%%c",*cp,*cp,*cp);
}

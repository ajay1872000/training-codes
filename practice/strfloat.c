#include<stdio.h>
float strtofloat(char* s){
	int l,i,dc=0;
	float f=0,c=1;
	for(i=0;s[i];i++)
	{
		if(((s[i]>=48)&&(s[i]<=57))||(s[i]=='.')){
			if((s[i]=='.')||(c<1))
			{	if(s[i]!='.')
					f=f+((s[i]-48)*c);
				else{
					if(dc==1){
						printf("invalid input");
						exit(1);}
					else dc++;}
					c=c*0.1;
			}	
			else
				f=f*10+(s[i]-48);
		}
		else{
			printf("invalid input");
			exit(1);}

	}
	return f;
}


void main(){
	float f;
	char s[10];
	printf("enter string");
	scanf("%s",s);
	f=strtofloat(s);
	printf("%f",f);
}


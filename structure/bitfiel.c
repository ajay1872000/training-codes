#include<stdio.h>
struct dob{
	unsigned int d:5;
	unsigned int m:4;
	unsigned short int y;
};
void main(){
	struct dob da;
	da.d=18;
	da.m=7;
	da.y=2000;
	da.a=0;
	printf("%d\n",sizeof(struct dob));
	printf("%d-%2d-%d",da.d,da.m,da.y);
}


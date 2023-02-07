#include<stdio.h>
//#pragma pack(1)
struct emp{
	int id;
	char a;
	double d;
	float f;
};//__attribute((packed));;
void main(){
	printf("%d",sizeof(struct emp));
}

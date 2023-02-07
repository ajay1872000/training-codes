#include<stdio.h>
struct employee{
	char name[32];
	int id;
	float salary;
	char gen;
	char grade;
};
void read(struct employee* ptr,int n)
{
	for(i=0;i<n;i++){
		printf("enter employee name");
		scanf("%s",ptr[i].name);
		__fpurge(stdin);
		printf("enter employee id");
		scanf("%d",ptr[i].id);
		__fpurge(stdin);
		printf("enter salary");
		scanf("%f",ptr[i].salary);
		

void main()
{
	struct employee e[3];
	printf("%d,%p",sizeof(e),e);
	read(e,3);
	display(e,3);
}





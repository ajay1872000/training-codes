#include<stdio.h>
union emp{
	char name[32];
	int id;
	float salary;};
void main()
{
	int i;
	union emp e[3];
	for(i=0;i<3;i++){
	scanf("%d",&e[i].id);
	scanf("%s",&e[i].name);
	scanf("%f",&e[i].salary);}
	printf("%d\n",sizeof(e.id));
	printf("enter employee id");
	scanf("%d",&e[0].id);
	printf("id=%d\n",e[0].id);
	printf("enter employee salary");
	scanf("%f",&e[1].salary);
	printf("id=%d\n",e[1].salary);
	printf("enter employee name");
	scanf("%s",e[2].name);
	printf("name=%s\n",e[2].name);
	printf("\n------------------------------------------------------------------------------------------\n");
	for(i=0;i<3;i++){
	printf("id=%d\n",e[i].id);
	printf("name=%s\n",e[i].name);
	printf("salary=%f\n",e[i].salary);}
}

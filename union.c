#include<stdio.h>
union emp{
	char name[32];
	int id;
	float salary;};
void main()
{
	union emp e;
	printf("%d\n",sizeof(union emp));
	printf("enter employee id");
	scanf("%d",&e.id);
	printf("id=%d\n",e.id);
	printf("enter employee salary");
	scanf("%f",&e.salary);
	printf("id=%d\n",e.id);
	printf("salary=%f\n",e.salary);
	printf("enter employee name");
	scanf("%s",e.name);
	printf("name=%s\n",e.name);
	printf("\n------------------------------------------------------------------------------------------\n");
	printf("id=%d\n",e.id);
	printf("name=%s\n",e.name);
	printf("salary=%f\n",e.salary);
}

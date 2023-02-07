#include<stdio.h>
struct employee{
	char name[32];
	int id;
	char gen;
	char grade;
	float salary;
};
void main(){
	struct employee e={.id=1001,.name="asdf",.gen='M',.grade='J',.salary=100000};
	printf("%d\n",e.id);
	printf("%s\n",e.name);
	printf("%c\n",e.gen);
	printf("%c\n",e.grade);
	printf("%f\n",e.salary);
	scanf("%d",&e.id);
	__fpurge(stdin);
	scanf("%s",e.name);
	__fpurge(stdin);
	scanf("%c",&e.gen);
	__fpurge(stdin);
	scanf("%c",&e.grade);
	__fpurge(stdin);
	scanf("%f",&e.salary);
	__fpurge(stdin);
	printf("%d\n",e.id);
	printf("%s\n",e.name);
	printf("%c\n",e.gen);
	printf("%c\n",e.grade);
	printf("%f\n",e.salary);
}

#include<stdio.h>
struct student{
	int id;
	char name[32];
	char gen;
	char grade;
}
void main(){
	struct student s={.id=101,.name="ajay",.gen='M',.grade='J'};
	struct student *p=&s;
	printf("%p-%d-%d\n",&p->id,p->id,sizeof(p->id));
	printf("%p-%s-%d\n",p->name,p->name->sizeof(p->name));
	printf("%p-%c-%d\n",&p->gen,p->gen,sizeof(p->gen));
	printf("%p-%c-%d\n",&p->grade,p->grade,sizeof(p->grade));
}

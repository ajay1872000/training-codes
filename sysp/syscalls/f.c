#include<stdio.h>
void main()
{
	vfork();
	vfork();
	vfork();
	vfork();
	printf("hi");
	exit(0);
}

#include<stdio.h>
void main()
{int x=10,y=10;
	const int* const ptr=&x;
	//ptr=&y; in constant data and constant address type the data cannot modify the address
	//*ptr=20 in constant data and constant address type the data cannot modify the data
	printf("%d",*ptr);
}


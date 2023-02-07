#include<stdio.h>
void main()
{
	long int ts,ia,l1a,l2a,l1b,l2b,sa=0x002,ta;
	l=256*1024*1024;
	l2a=l+sa;
	l1b=l2a+l;
	l1a=l1b+l;
	ta=l1a+l;
	printf("total size 1GB:%pto%p\npart 1a size from 1GB to 768 Mb:%p-%p\npart 1b size from 767MB to 512MB :%p-%p\npart 2a size from 511MB to 256MB:%p-%p\npart 2b:size from 255Mb to 0MB%p-%p\n enter a memory address:",sa,ta,l1a-1,ta,l1b,l1a-1,l2a,l1b-1,sa,l2a-1);
	scanf("%p",&ia);

	if((ia>=sa)&&(ia<=ta))
	{
		
	   if(ia>=l1a)
		   printf("%p lies in 1a-%p to %p",ia,l1a,ta);
	   else if(ia>=l1b)
		   printf("%p lies in 1b-%p to %p",ia,l1b,l1a-1);
	   else if(ia>=l2a)
		   printf("%p lies in 2a-%p to %p",ia,l2a,l1b-1);
	   else 
		   printf("%p lies in 2b-%p to %p",ia,sa,l2a-1);
	}
	else{
		printf("%p memory out of range",ia);
	}



}



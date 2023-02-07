#include<stdio.h>
void main()
{
	int a,i,min,max,s,r,b,f=1;
	printf("enter min and max values");
	scanf("%d,%d",&min,&max);
	(min>max)?(min=min+max,max=min-max,min=min-max):0;
	a=min;
	b=max;
        while(b>0){ 
		if(((a%10)>1)||((b%10)>1))
		{
			f=0;
			break;
		}
		a=a/10;
		b=b/10;
	}
     if(f!=0){
		while(min<=max){
			s=0;
			i=1;
			a=min;
			while(a!=0){
				r=a%10;
				if(r>1){
					s=0;
					break;
				}
				s=s+r*i;
				i=i*2;
				a=a/10;}
			if(s==0)
			{
				min++;
				continue;}

			printf("%d-%d\n",min,s);
			min++;
		}
	}
	else
		printf("invalid inputs");


}

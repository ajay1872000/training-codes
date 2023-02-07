// intialising a char variable with ascii value and then verify to its corresponding ascii character

#include<stdio.h>
void main()
{
	
      int c,b,a,r=0,i=1,nb;
      printf("enter number, its base value");
      scanf("%d,%d",&c,&b);
      while(c>0){
	      r=r+(c%10)*i;
	      c=c/10;
	      i=i*b;
      }

      printf("\ndecimal value=%d\n",r);
      printf("\nenter new base value");
      scanf("%d",&nb);
      i=1,a=r,r=0;
      while(a>0){
	      r=r+(a%nb)*i;
	      a=a/nb;
	      i=i*10;
      }
      printf("%d",r);	
}

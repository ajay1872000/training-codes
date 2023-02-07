#include<stdio.h>
void main()
{
	
      int a,b,i=1,r=0;
      scanf("%d",&a);
      if(a<=255){
	      int c=a;
	      while(c>0){
		      r=r+(c%2)*i;
		      c=c/2;
		      i=i*10;}
	      printf("%d",r);
	      i=0;
	      while(i<=8){
		      if(r%10==1){
			      printf("\nBulb %d on",i);
		      }
		      else{
			      printf("\nBulb %d off",i);}
		   
	      
	      r=r/10;
	      i++;}
      }
      else{
	      printf("%d is invalid number",a);}

}

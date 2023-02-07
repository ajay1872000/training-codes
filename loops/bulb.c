#include<stdio.h>
void main()
{
	
int i=1,a;
      scanf("%d",&a);
      if(a<=255){
	      while(i<=8){
		      if(a%2)
			      printf("\nBulb %d on",i);
		      else
			      printf("\nBulb %d off",i);
	      
		      a=a/2;
		      i++;}}
      else{
	      printf("invalid case");}

}

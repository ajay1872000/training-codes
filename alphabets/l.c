// intialising a char variable with ascii value and then verify to its corresponding ascii character

#include<stdio.h>
void main()
{
	
      int n,i,d;
      scanf("%d",&n);
      d=n/2+2;
      for(i=1;i<=n;i++){
	      for(int j=1;j<=n;j++){
		      if((i==n)||(j==1)){
			      printf("*");
		      }
		      else{
			      printf(" ");
		      }}
		      printf("\n");}
}

// intialising a char variable with ascii value and then verify to its corresponding ascii character

#include<stdio.h>
void main()
{
	
      int n,i;
      scanf("%d",&n);
      for(i=1;i<=n;i++){
	      for(int j=1;j<=n;j++){
		      if((j==1)||(i==1)||(j==n)||(i==n)){
			      printf("*");
		      }
		      else{
			      printf(" ");
		      }}
		      printf("\n");}
}

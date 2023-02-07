// intialising a char variable with ascii value and then verify to its corresponding ascii character

#include<stdio.h>
void main()
{
	
      int n,i;
      scanf("%d",&n);
      for(i=1;i<=n;i++){
	      for(int j=1;j<=n;j++){
		      if((i==1)||(i==n)||(j==1)||((i==3*n/4)&&(j>=(n/2)+1)&&(j<=n))||((i>(3*n)/4)&&(j==n))){
			      printf("*");
		      }
		      else{
			      printf(" ");
		      }}
		      printf("\n");
      }
}

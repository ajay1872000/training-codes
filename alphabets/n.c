// intialising a char variable with ascii value and then verify to its corresponding ascii character

#include<stdio.h>
void main()
{
	
      int n,i,d,m;
      scanf("%d",&n);
      d=1;
      m=n;
      for(i=1;i<=n;i++){
	      for(int j=1;j<=n;j++){
		      if((j==1)||(j==i)|(j==n)){
			      printf("*");
		      }
		      else{
			      printf(" ");
		      }}
		      printf("\n");}
}

// intialising a char variable with ascii value and then verify to its corresponding ascii character

#include<stdio.h>
void main()
{
	
      int n,i,d=1;
      scanf("%d",&n);
      for(i=1;i<=n;i++){
		      if(i<=n/2+1){
			      d++;}
		      else{
			      d--;}
	      for(int j=1;j<=n;j++){
		      if((j==d)||(j==1)){
			      printf("*");
		      }
		      else{
			      printf(" ");
		      }}
		      printf("\n");}
}

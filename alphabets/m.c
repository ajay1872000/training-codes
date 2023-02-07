// intialising a char variable with ascii value and then verify to its corresponding ascii character

#include<stdio.h>
void main()
{
	
      int n,i,d,m;
      scanf("%d",&n);
      d=1;
      m=n;
      for(i=1;i<=n;i++){
	      if(i<n/2+1){
			      d++;
		      m--;}
	      else{
		      d=0;
		      m=0;
	      }
	      for(int j=1;j<=n;j++){
		      if((j==d)||(j==1)||(j==m)|(j==n)){
			      printf("*");
		      }
		      else{
			      printf(" ");
		      }}
		      printf("\n");}
}

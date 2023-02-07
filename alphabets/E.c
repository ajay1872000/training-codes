// intialising a char variable with ascii value and then verify to its corresponding ascii character

#include<stdio.h>
void main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if((j==1)||(i==1)||(i==n)||(i==(n/2)+1)){
				printf("*");
			}
			else{
				printf(" ");
			}
		}
		printf("\n");
	}

      
}

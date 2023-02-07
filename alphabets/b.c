#include<stdio.h>
void main()
{
	int i=1,j=1,n,s=1;
	scanf("%d",&n);

	for(i=1;i<=n;i++){
		
		if((i<=((n/4)+1))||((i>((2*n/4)+1))&&(i<=((3*n/4)+1)))){
			s++;}
		else{
			s--;}
		for(j=1;j<=n-2;j++){
			
		if((j==1)||(j==s)){
			printf("*");
		}
		else{
			printf(" ");}} printf("\n");
	}

				  

}


	

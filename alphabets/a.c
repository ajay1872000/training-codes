#include<stdio.h>
void main()
{
	int i=1,j=1,n;
	scanf("%d",&n);;
	for(i=1;i<=n;i++)
	{ 
		for(j=1;j<=2*n+1;j++){
			if(i!=((n/2)+1)){
				if((j==((n)-i+2))||(j==((n)+i))){
					printf("*");
				}
				else{
					printf(" ");
				}
			}
			else{
				if((j>=((n)-i+2))&&(j<=((n)+i))){
					printf("*");}
				else{
					printf(" ");
				}

			}


		}
			
		printf("\n");
	}

				  

}


	

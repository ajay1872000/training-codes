#include<stdio.h>
void main(){
	int i,j=0,n,k;
	printf("enter n value");
	scanf("%d",&n);
	for(i=2;i<n/2;i++){
		k=n/i;
		if((i%2)&&(n%i==0))
			j=k-i/2;
		else{ if((i%2==0)&&(n%k==i/2))
			j=k-(i/2)+1;
		}
		if(j>0){
			for(;j<=(k+i/2);j++)
				printf("%d+",j);
			printf("\b=%d\n",n);
			j=0;
		}
				
	}


}


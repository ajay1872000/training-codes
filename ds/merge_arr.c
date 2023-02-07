#include<stdio.h>
int* merge(int* p,int n){
	int t,i,j,*ptr,*ptr1,*ptr2,k;
	if(n==0)
		return NULL;
	if(n==1)
	{
				ptr=(int*)malloc(n*sizeof(int));
				ptr=p[0];
		return ptr;}
	else{
		if(n==2){
			if(p[0]>p[1])
			{
				ptr=(int*)malloc(n*sizeof(int));
				p[0]=p[1];
				p[1]=p[0];
	for(i=0;i<n;i++)
		printf("%d\t",ptr[i]);
				return ptr;
			}
			else
			{
				ptr=(int*)malloc(n*sizeof(int));
				ptr[0]=p[0];
				ptr[1]=p[1];
	for(i=0;i<n;i++)
		printf("%d\t",ptr[i]);
				return ptr;
			}
		}
		else{

			ptr1=merge(p,n/2);
			ptr2=merge((p+(n/2)),(n-n/2));
			ptr=(int *)malloc(n*sizeof(int));
			for(i=0,j=0,k=0;((i<n/2)&&(j<(n-n/2)));k++)
			{
				if(ptr1[i]==ptr2[j])
				{
					ptr[k]=ptr1[i];
					i++;
					j++;
				}
				else{if(ptr1[i]<ptr2[j])
					{
						ptr[k]=ptr1[i];
						i++;}
					else{
						ptr[k]=ptr2[j];
						j++;}
				}
			}
			for(;i<n/2;i++,k++)
				ptr[k]=ptr1[i];
			for(;j<(n-n/2);j++,k++)
				ptr[k]=ptr2[j];
		//	free(ptr1);
		//	free(ptr2);
	for(i=0;i<n;i++)
		printf("%d\t",ptr[i]);
			return ptr;

		}
	}
}
void main(){
	int i,n;
	int *p,*p1;
	printf("enter n value");
	scanf("%d",&n);
	p=(int*)malloc(n*sizeof(int));
	if(p==NULL)
	{	
		printf("failed to allocate");
			exit(1);
	}
	for(i=0;i<n;i++)
		scanf("%d",p+i);
	p1=merge(p,n);
	for(i=0;i<n;i++)
		printf("%d\t",p1[i]);
}




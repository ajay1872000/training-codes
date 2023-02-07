#include<stdio.h>
char* space_rem(char*);
int* array_rotation(int *,int,int);
void main(){
	int opt,*ptr,n,r,i;
	char a[100];
	while(1){
		printf("menu \n0.exit\n1.space remove\n2.array rotation\nenter your choice\n");
		scanf("%d",&opt);
		__fpurge(stdin);
		switch(opt){
			case 0:exit(1);
			case 1: 
				printf("enter a string");
				scanf("%[^\n]s",a);
				printf("%s",space_rem(a));
				break;
			case 2: 
	printf("\nenter array size");
	scanf("%d",&n);
	ptr=(int*)calloc(n,sizeof(int));
	if(ptr==NULL){
		printf("failed to allocate memory");
		exit(1);}
	printf("enter array element");
	for(i=0;i<n;i++)
			scanf("%d",&ptr[i]);
	printf("enter rotation of elements");
	scanf("%d",&r);
				ptr=array_rotation(ptr,n,r);
	for(i=0;i<n;i++)
		printf("%d\t",ptr[i]);
				break;
		}
	}

}
int* array_rotation(int* a,int n,int r){
	int i,j;
	int t;
	for(i=0;i<r;i++){
		t=a[0];
		for(j=0;j<n-1;j++)
			a[j]=a[j+1];
		a[j]=t;}
	return a;
	}
char* space_rem(char* a){
	int i,j;
	for(i=0;a[i]!='\0';i++)
	{
		if(((a[i-1]==' ')||(i==0))&&(a[i]==' '))
		{ for(j=i;a[j]!='\0';j++)
				a[j]=a[j+1];
		i--;
		}}
		if((a[i-1]==' ')&&(a[i]=='\0'))
			a[i-1]=a[i];
	return a;
}

#include<stdio.h>
#include<stdlib.h>
void read(int r,int c,int (*p)[c]){
	int i,j;
	printf("enter elements");
	for(i=0;i<r;i++){
		for(j=0;j<c;j++)
			scanf("%d",&p[i][j]);
	}
}
void print(int r,int c,int (*p)[c]){
	int i,j;
	printf("\nmatrix:\n");
	for(i=0;i<r;i++){
		for(j=0;j<c;j++)
			printf("%d\t",p[i][j]);
		printf("\n");
	}
}

void add(int r,int c,int r1,int c1,int (*a)[c],int (*b)[c1]){
	int i,j;
	if((r!=r1)&&(c!=c1))
	{
		printf("matrix size not equal");
		return;}
	int (*s)[c]=(int(*)[c])malloc(r*c*sizeof(int)),opt;
	if(s==NULL){
		printf("failed to allocated memory for addition matrix");
		return;}
	for(i=0;i<r;i++){
		for(j=0;j<c1;j++)
			s[i][j]=a[i][j]+b[i][j];
	}
	print(r,c,s);
	free(s);
}
void mul(int r,int c,int (*a)[c],int r1,int c1,int (*b)[c1]){
	int i,j,s,k;
	if(c!=r1)
	{
		printf("matrix size not equal");
		if(r==r1)
			printf("\ntry for transpose a");
		if(c==c1)
			printf("\ntry for transpose b");
		return;}
	int (*p)[c1]=(int(*)[c1])malloc(r*c1*sizeof(int)),opt;
	if(p==NULL){
		printf("failed to allocated memory for addition matrix");
		return;}
	for(i=0;i<r;i++){
		for(j=0;j<c1;j++)
		{
			s=0;
			for(k=0;k<c;k++){
				s=s+(a[i][k]*b[k][j]);}
			p[i][j]=s;

		}
			printf("\n");
	}
	for(i=0;i<r;i++)
		{for(j=0;j<c1;j++)
			printf("%d\t",p[i][j]);
		printf("\n");}
}
void trans(int r,int c,int (*a)[c])
{
	int i,j,t;
	if(r<=c){
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++){
			if(i<j){
				t=a[i][j];
				a[i][j]=a[j][i];
				a[j][i]=t;}}
	}}else{
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++){
			if(j<i){
				t=a[i][j];
				a[i][j]=a[j][i];
				a[j][i]=t;}}
	}}
}
void upt(int r,int c,int (*p)[c])
{
	int i,j,t;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++){
		if(i<=j)
		printf("%d\t",p[i][j]);
		else
		printf("%d\t",0);}
		printf("\n");
	}
}
void lt(int r,int c,int (*p)[c])
{
	int i,j,t;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++){
		if(i>=j)
		printf("%d\t",p[i][j]);
		else
		printf("%d\t",0);}
		printf("\n");
	}
}


 
void main()
{
	int r,c,r1,c1;
	printf("enter no of rows,columns ");
	scanf("%d,%d",&r,&c);
	int (*a)[c]=(int(*)[c])malloc(r*c*sizeof(int)),opt;
	if(a==NULL){
		printf("failed to allocated memory for a matrix");
		return;}
	printf("enter no of rows,columns of b");
	scanf("%d,%d",&r1,&c1);
	int (*b)[c1]=(int(*)[c])malloc(r1*c1*sizeof(int));
	int (*p)[c1];
	if(b==NULL){
		printf("failed to allocated memory for b matrix");
		return;}
	while(1){
		printf("\nMENU\n---------------------------------------------------------------------------------------------------------------------------------------------------------\n0.exit\n1.read a\n2.print a\n3.read b\n4.print b\n5.addition\n6.multiplication\n7.transpose of a\n8.transpose of b\n9.upper triangle of a\n10.upper triangle of b\n11.lower triangle of a\n12.lower triangle of b\nenter your choice");
		scanf("%d",&opt);
		switch(opt){
			case 0:exit(1);
			case 1:read(r,c,a);break;
			case 2:print(r,c,a);break;
			case 3:read(r1,c1,b);break;
			case 4:print(r1,c1,b);break;
			case 5:add(r,c,r1,c1,a,b);break;
			case 6:mul(r,c,a,r1,c1,b);break;
			case 7:trans(r,c,a);
			       r=r+c;
			       c=r-c;
			       r=r-c;break;
			case 8:trans(r1,c1,b);
			       r1=r1+c1;
			       c1=r1-c1;
			       r1=r1-c1;break;
			case 9:upt(r,c,a);break;
			case 10:upt(r1,c1,b);break;
			case 11:lt(r,c,a);break;
			case 12:lt(r1,c1,b);break;
			default:printf("invalid case");
		}
	}
}



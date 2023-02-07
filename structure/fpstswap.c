#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define si 6
int a=0,r=0;
struct book{
	char name[32];
	int nop;
	float price;};
struct fp{
	struct book* (*fpmemalloc)(struct book*);
	void (*fpread)(struct book*);
	void (*fpdisplay)(struct book*);
	void (*fpswap)(struct book*);
	struct book* (*fpdealloc)(struct book*);
};


struct book* memalloc(struct book *b){
	if(a==si)
	{
		printf("size of struct is full");
		a--;
		return b;
	}
	else{
	 b=(struct book*)realloc(b,a*sizeof(struct book));
	if(b==NULL){
		printf("failed to allocate memory");
		exit(1);
	}}
			       printf("%d structures memory is allocated",a);	
	return b;
}
void read(struct book *p){
	if(r==si){
		printf("structure size is full");
		r--;
	}
	else{
	if(r>a){
		printf("memory is not allocated for %d structure",r);
		r--;
		return;}
	else{
	printf("enter book name");
	scanf("%s",p[r-1].name);
	__fpurge(stdin);
	printf("enter book nop");
	scanf("%d",&p[r-1].nop);
	__fpurge(stdin);
	printf("enter book price");
	scanf("%f",&p[r-1].price);
	__fpurge(stdin);}}
}
void display(struct book *p){
	int i;
	if(a==0){
		printf("memory is not allocated");
		return;}
	else{if(r==0){
		printf("read the data");
		return;}
		else{
	for(i=0;i<a;i++){printf("\nbook %d\n",i+1);
			printf("%s\n",p[i].name);
			printf("%d\n",p[i].nop);
			printf("%f\n",p[i].price);}
		}
	}
}

void swap(struct book *b)
{
	int i,j;
	if(r<2){
		printf("insufficient structures for swap");
		}
	else{
		for(i=0,j=r-1;i<j;i++,j--)
		{
	struct book t;
	t.nop=b[i].nop;
	b[i].nop=b[j].nop;
	b[j].nop=t.nop;
	strcpy(t.name,b[i].name);
	strcpy(b[i].name,b[j].name);
	strcpy(b[j].name,t.name);
	t.price=b[i].price;
	b[i].price=b[j].price;
	b[j].price=t.price;}
	printf("succesfully swaped os structures");
	}
}
struct book* dealloc(struct book *b){
	if(a==0){
		printf("first allocate memory");
		return 0;
	}
	else{if(a==1){
		free(b);
		a--;
		r--;

			       printf("succesfully deallocated %d structure ",a+1);
	return b;}
	else{
		a--;
		r--;
	b=realloc(b,a*sizeof(struct book));
	if(b==NULL){
		printf("failed to deallocate memory");
		exit(1);
	}

			       printf("succesfully deallocated %d structure ",a+1);
	return b;}}
	
}
void main(){
	int opt;
	struct fp fpo;
	fpo.fpdealloc=dealloc;
	fpo.fpswap=swap;
	fpo.fpread=read;
	fpo.fpmemalloc=memalloc;
	fpo.fpdisplay=display;
	struct book *b=NULL;

	while(1){
		printf("\nMenu\n-------------------------------------------------------------------------------------------------------------------------\n0.exit\n1.memory allocation\n2.read\n3.display\n4.swap\n5.deallocation");
		scanf("%d",&opt);
		switch(opt){
			case 1: a++;
				b=fpo.fpmemalloc(b);
			       break;
			case 2: r++;
				fpo.fpread(b);break;
			case 3:fpo.fpdisplay(b);break;
			case 4:fpo.fpswap(b);break;
			case 5: 
			       b=fpo.fpdealloc(b);
			       break;
			case 0:exit(1);
			default :printf("invalid case");
		}
	}

}

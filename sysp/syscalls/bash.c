#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void main()
{

	int a,pid,k=0,stat,i;
	char **cptr=NULL;
	char ptr[10];
	//a=execl("/bin/ps","ps","-ef",0);

	while(1){
		pid=fork();
		if(pid<0)
		{
			printf("failed to create a child");
			exit(10);
		}

		if(pid==0)
		{
			scanf("%[^\n]s",ptr);
			__fpurge(stdin);
				cptr=(char**)malloc((k+1)*sizeof(char*));
				cptr[k]=ptr;
				k++;
					for(i=0;ptr[i];i++)
					{
						if((ptr[i]==' '))
						{	cptr=(char**)realloc(cptr,(k+1)*sizeof(char*));
							cptr[k]=&ptr[i+1];
							ptr[i]='\0';
							k++;
						}
					}
					k++;
				cptr=(char**)realloc(cptr,(k+1)*sizeof(char*));
				cptr[k]=&ptr[i];
				a=execvp(cptr[0],cptr);
				exit(1);
		}
		else
		{
			wait(&stat);
			printf("parent");
		}


	}
}

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t count_mutex     = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  condition_var   = PTHREAD_COND_INITIALIZER;
pthread_cond_t  condition_var1   = PTHREAD_COND_INITIALIZER;
void *functionCount1();
void *functionCount2();
int  count = 0;

main()
{
   pthread_t thread1, thread2;
int a=20;
   pthread_create( &thread1, NULL, &functionCount1, &a);
   pthread_create( &thread2, NULL, &functionCount2, &a);

   pthread_join( thread1, NULL);
   pthread_join( thread2, NULL);

   printf("Final count: %d\n",count);

   exit(EXIT_SUCCESS);
}


void *functionCount1(int *p)
{int a=*p;
   for(;count<a;)
   {
      pthread_mutex_lock( &count_mutex );

      pthread_cond_wait( &condition_var, &count_mutex );
          printf("odd: %d\n",count);
      count++;

      pthread_mutex_unlock( &count_mutex );


    }
}


void *functionCount2(int *p)
{int a=*p;
    for(;count<a;)
    {
       pthread_mutex_lock( &count_mutex );

       if(count%2)
       {
          
	  pthread_cond_signal( &condition_var );
       }
       else
       {
          printf("even: %d\n",count);
          count++;
       }

       pthread_mutex_unlock( &count_mutex );

    }

}


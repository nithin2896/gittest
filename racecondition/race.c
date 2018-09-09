#include<stdio.h>
#include<pthread.h>
int count=0;
void *incthread( void * arg)
{
while(1)
{
count++;
printf("inc=%d",count);
}
}
void *decthread( void * arg)
{
while(1)
{
count--;
printf("dec=%d",count);
}
}
int main()
{
pthread_t incid,decid;
pthread_create(&incid,NULL,incthread,NULL);
pthread_create(&decid,NULL,decthread,NULL);
pthread_join(incid,NULL);
pthread_join(decid,NULL);
return 0;
}




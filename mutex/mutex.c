#include<stdio.h>
#include<pthread.h>
int count=0;
pthread_mutex_t countmutex=PTHREAD_MUTEX_INITIALIZER;
void * inc(void * arg)
{
while(1)
{
pthread_mutex_lock(&countmutex);
count++;
printf("inc=%d\n",count);
pthread_mutex_unlock(&countmutex);

}
}
void * dec(void * arg)
{
while(1)
{
pthread_mutex_lock(&countmutex);
count--;
printf("dec=%d\n",count);
pthread_mutex_unlock(&countmutex);

}
}
int main()
{
pthread_t incid,decid;
pthread_create(&incid,NULL,inc,NULL);
pthread_create(&decid,NULL,dec,NULL);
pthread_join(incid,NULL);
pthread_join(decid,NULL);
return 0;
}




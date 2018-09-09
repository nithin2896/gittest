#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
sem_t semInputtoProc;
sem_t semProctoInput;
int a,b;
int sum;
void * inputthread(void * arg)
{
while(1)
{
sem_wait(&semProctoInput);
scanf("%d%d",&a,&b);
sem_post(&semInputtoProc);
}
}
void * processingthread(void * arg)
{
while(1)
{
sem_wait(&semInputtoProc);
sum=a+b;
printf("sum=%d\n",sum);
sem_post(&semProctoInput);
}
}
int main()
{
pthread_t inputid,procid;
sem_init(&semInputtoProc,0,0);
sem_init(&semProctoInput,0,1);
pthread_create(&inputid,NULL,inputthread,NULL);
pthread_create(&procid,NULL,processingthread,NULL);
pthread_join(inputid,NULL);
pthread_join(procid,NULL);
return 0;
}



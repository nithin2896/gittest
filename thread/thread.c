#include<stdio.h>
#include<pthread.h>
void *threaddemo (void * arg)
{
printf("hello world\n");
}
int main()
{
pthread_t tid;
printf("before thread\n");
pthread_create(&tid,NULL,threaddemo,NULL);
printf("after thread\n");
pthread_join(tid,NULL);
return 0;
}


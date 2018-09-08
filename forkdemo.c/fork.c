#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main( int argc,char const * argv[])
{
pid_t id;
printf("Before fork:%d\n",getpid());
id=fork();
if(0==id)
{
printf("child process:%d\t%d\t%d\n",getpid(),getppid(),id);
}
else
{
printf("parent process:%d\t%d\t%d\n:",getpid(),getppid(),id);
}
return 0;
}

#include <stdio.h>
#define _GNU_SOURCE            
#include <fcntl.h>           
#include <unistd.h>
int fd[2];
pid_t id;
unsigned char buff[1024];
int main()
{
pipe(fd);
if(id==0)
{
close(fd[1]);
read(fd[0],buff,1024);
printf("read:%s from parent ",buff);
close(fd[1]);
}
else
{
close(fd[0]);
write(fd[1],"HELLO \n",8);
close(fd[1]);
}
return 0;
}



#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
mkfifo("dac_fifo",S_IRWXU);
int fdw;
fdw=open("dac_fifo",O_WRONLY);
write(fdw,"HELLO\n",8);
close(fdw);
return 0;
}


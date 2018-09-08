#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
mkfifo("dac_fifo",S_IRWXU);
int fdr;
unsigned char buff[1024];
fdr=open("dac_fifo",O_RDONLY);
read(fdr,buff,1024);
printf("read:%s\n",buff);
close(fdr);
return 0;
}



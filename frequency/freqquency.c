#include<stdio.h>
#include<string.h>
int main()
{
char str[100],ch;
int i;
int c=0;
printf("enter the string\n");
gets(str);
printf("enter the character\n");
scanf("%c",&ch);
for(i=0;str[i]!='\0';i++)
{
if(ch==str[i])
c++;
}
printf("the no of characters are %d\n",c);

return 0;
}


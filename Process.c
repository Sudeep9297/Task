#include<stdio.h>
#include<unistd.h>
int main()
{
fork();
 printf("Hello Maplelabs!\n PID=%d\n",getpid());
 return 0;
}

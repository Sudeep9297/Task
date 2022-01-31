#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void *thread_function(void *arg);
int i,j;

int main()
{
pthread_t a_thread; //thread declaration
pthread_create(&a_thread, NULL, thread_function, NULL); //thread is created
pthread_join(a_thread, NULL); //process waits for thread to finish
printf("Inside Main Program\n");
for (j=15;j<20;j++)
{
printf("%d\n",j);
sleep(1);
}
}

void *thread_function(void *arg) //work done by the thread is defined in this function
{
printf("Inside Thread\n");
for (i=0;i<5;i++)
{
printf("%d\n",i);
sleep(1);
}
}

//Thread prints 0-4 while the main process prints 15-19

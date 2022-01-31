#include<stdio.h>
#include<unistd.h>
int main()
{
pid_t return_value;
printf("The process id is %d\n",getpid());

return_value=fork();

if (return_value<0)
{
	printf("\nfork failure\n");   //fork failed
}
else if(return_value==0)
{
	printf("\nChild Process\n");
	printf("The process id is %d\n",getpid()); 
	//sleep(10);
}
else
{
	//wait();
	printf("Parent Process\n");
	printf("the process id is %d\n",getpid());
	//sleep(20);
}
return 0;
}

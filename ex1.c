#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	printf("We are in ex1.c\n");
	printf("PID of ex1.c =%d \n", getpid());
	char *args[]={"./ex2",NULL}; //character pointer(path,null pointer)
	execv(args[0], args);
	printf("back to ex1.c"); //this will not be executed
	return 0;
}

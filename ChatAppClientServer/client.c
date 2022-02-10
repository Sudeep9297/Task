#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>		/* read(),write(),close() */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>		/*  struct hostent */

void error(const char *msg)	   //error function//
{
	perror(msg); 	           //shows the error number and error description as "stderr"//
	exit(1);	           //terminate the program if gets error//
}

int main(int argc, char *argv[])
{
	int sockfd, portno, n;
	struct sockaddr_in serv_addr;
	struct hostent *server;
	
	char buffer[255];		//messages get stored in the buffer //
	if (argc < 3)		        //if user doesnt provide ip address and port number or either of them//
	{
		fprintf(stderr, "usage %s hostname port\n", argv[0]);
		exit(1);
	}
	
	
	portno = atoi(argv[2]);        					        //port number typecasted to int type//
	sockfd = socket(AF_INET, SOCK_STREAM , 0);
	if (sockfd < 0)
		error("ERROR opening socket");
		
		server = gethostbyname(argv[1]);     				 //inbuilt function//
		if(server == NULL)						 //wrong server provided by user
		{
			fprintf(stderr , "Error , no such host");
		}
		
	bzero((char *) &serv_addr , sizeof(serv_addr));							//clears the data//
	serv_addr.sin_family = AF_INET;
	bcopy((char *) server->h_addr , (char *) &serv_addr.sin_addr.s_addr , server->h_length);	//copies n bytes from hostent to 														servaddr//
	serv_addr.sin_port = htons(portno);
	if(connect(sockfd , (struct sockaddr *) &serv_addr ,sizeof(serv_addr)) < 0)    			//connection to server//
		error("Connection Failed");								//return -1 if connection fails//
		
	while(1)
	{
		bzero(buffer , 255);					//clears the buffer//
		fgets(buffer , 255 , stdin);
		n = write(sockfd , buffer , strlen(buffer));		//write msg to server//
		if(n < 0)
			error("Error on writing");            	        //if fails to write//
			
		bzero(buffer , 255);					//clears the buffer//
		
		n = read(sockfd , buffer , 255);			//read msg from server//
		if (n < 0)
			error("Error on reading.");			//if fails to read//
		printf("Server: %s", buffer);				//print msg from server//
		
		int i = strncmp("Bye" , buffer , 3);			
		if (i==0)
		break;							
	}
	
	close(sockfd);							//connection terminated//
	return 0;
}

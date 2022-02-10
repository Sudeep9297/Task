#include <stdio.h>		/*  fgets  */	
#include <stdlib.h>		/*  atoi  */
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>		/* struct sockaddr */
#include <netinet/in.h>		/* sockaddr_in */

void error(const char *msg)    //error function//
{
	perror(msg);          //shows the error number and error description as "stderr"//
	exit(1);      	      //terminate the program if gets error//
}

int main(int argc, char* argv[])
{
	if(argc < 2)                   //if user doesnt provide PORT number as an argument//
	{
		fprintf(stderr, "Port number not provided. Program terminated\n");
		exit(1);               //terminate the program//
	}
	
	int sockfd , newsockfd , portno, n;  
	char buffer[255];              //messages get stored in the buffer //
	
	struct sockaddr_in serv_addr , cli_addr;            //internet address of the server and client//
	socklen_t clilen;     
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	
	if(sockfd < 0)
	{
		error("Error opening Socket.");     //socket not created//
	}	
	
	bzero((char*) &serv_addr , sizeof(serv_addr));   //clears the data of the buffer//
	portno = atoi(argv[1]);            //converting the command line argument(port) str to int //
	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr =INADDR_ANY;
	serv_addr.sin_port = htons(portno);
	
	if(bind(sockfd , (struct sockaddr*) &serv_addr , sizeof(serv_addr)) < 0)   //bind function//
		error("Binding Failed");        //returns -1, if gets failed//
		
	listen(sockfd , 5);    //listen functin//
	clilen = sizeof(cli_addr);
	
	newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr , &clilen);  //connection gets accepted//
	
	if(newsockfd < 0) 
	error("Error on Accept");   //connection not accepted//
	
	while(1)
	{
		bzero(buffer, 255);
		n = read(newsockfd , buffer , 255);   //read function//
		if(n < 0)
			error("Error on reading.");   //returns -1 on failure//
			
		printf("Client : %s\n",  buffer);     //message from client//
		bzero(buffer , 255);       	     //clears the buffer//
		fgets(buffer , 255 , stdin);	      //reads the buffer and get reply from server//
		
		n = write(newsockfd , buffer , strlen(buffer));    //write function//
		if(n < 0)
			error("Error on Writing.");
			
		int i = strncmp("Bye" , buffer , 3);
		if (i==0)
		break;
	}
	
	close(newsockfd);      //close the connection//
	close(sockfd);	       //close the connection//
	return 0;
}

#include <stdio.h>

#include <sys/types.h> //define some data types used in system calls
#include <sys/socket.h> //definitions of structures needed for sockets
#include <unistd.h> //contains various constants
#include <netinet/in.h> //constants and structures needed for Internet domain addresses

#include <errno.h> //necessary for errno value
#include <string.h> //necessary for bzero() -->> to fill bytes with 0
#include <stdlib.h> //necessary fors exit()
#include <time.h>


// void error message function
void error(char *msg) {  
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
	exit(1);
}

char* now() { 
	time_t t; time (&t);
	return asctime(localtime(&t));
}


int main (int argc, char *argv[]) {
	int sockid, clientSockid; //socket file descriptors
	int portno; //port number of which the server accepts connections
	socklen_t clientLen;
	int n;
	char buffer[256]; // server reads characters from the socket into this buffer

	//socket structures for the Internet addresses
	struct sockaddr_in serv_addr, cli_addr;

	if (argc<2) error("No port provided in cmd line");

	//creates a stream socket that belongs to INTERNET family
	sockid = socket(PF_INET, SOCK_STREAM, 0);
	if (sockid == -1) error("Cannot open listening socket");

	//sets all values to zero
	bzero((char*)&serv_addr, sizeof(serv_addr));
	portno = atoi(argv[1]);

	//setting individual fields of the sockaddr_in structure
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(portno); // converts to big-endian if necessary

	//binds socket to address of current host and port number on which the sever will be run
	if (bind(sockid, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
		error("Cannot bind to listening socket");
	}	

	//listen on the socket for connections with a backlog queue of 5
	if (listen(sockid,1) == -1) error("Cannot listen");

	int x = 1;

	while (x == 1) {
		//accept() causes the process to block until a client comes to the server
		clientLen = sizeof(cli_addr);
		clientSockid = accept(sockid, (struct sockaddr*)&cli_addr, &clientLen);
		if (clientSockid == -1) error("Server cannot accpet client socket");

		// buffer is initialised and server reads from the client socket descriptor
		bzero(buffer, 256);
		n = read(clientSockid, buffer, 255);
		if (n == -1) error("Server cannot read from client socket");
		printf("here is the message: %s\n", buffer);

		char command[256];
		memset(&command, 0, sizeof(command));

		int buffer_len = strlen(buffer)-1;
		strncpy(command, buffer, buffer_len);


		if (strcmp(command, "/Time") == 0) {
			n = write(clientSockid, now(), 255);
		}

		//writes short message to the client when connection successfully established
		n = write(clientSockid, buffer, 255);
		if (n == -1) error("Server cannot write to client socket");

		//closing sockets before ending main
		close(clientSockid);
	}

	close(sockid);


	return 0;

}





















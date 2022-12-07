#include <stdio.h>

#include <sys/types.h> //define data types used in system calls
#include <sys/socket.h> //definitions of structures needed for sockets
#include <unistd.h> //contains various constants

#include <netinet/in.h> //constants and structures needed for internet domain addresses

#include <netdb.h> //define structures for the server infrmation

#include <errno.h> //necessary for errno value
#include <string.h> //necessary for memset()
#include <stdlib.h> //necessary for exit()

void error(char *msg) {
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
	exit(1);
} 

int main(int argc, char *argv[]) {
	int sockfd; //socket file descriptor
	int portno; //port number of server that client wants to connect
	int n;
	struct sockaddr_in serv_addr; //socket structures for internet addresses

	struct hostent *server; //the variable server is a pointer to a structure of type hostent, defined in netdb.h

	char buffer[256];
	if (argc<3) {
		fprintf(stderr, "usage %s hostname port\n", argv[0]);
		exit(0);
	}

	portno = atoi(argv[2]);
	sockfd = socket(PF_INET, SOCK_STREAM, 0); //client socket
	if (sockfd == -1) {
		error("ERROR opening client socket");
	}

	server = gethostbyname(argv[1]); // returns pointer to a hostent struct
	if (server == NULL) {
		fprintf(stderr, "ERROR, no such host\n");
		exit(0);
	}

	//setting fields in serv_addr
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	bcopy((char*)server -> h_addr, (char*)&serv_addr.sin_addr.s_addr, server -> h_length);
	serv_addr.sin_port = htons(portno);

	//connecting to server
	if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
		error("ERROR connecting to server");
	}

	//communicating with the server
	printf("Enter command: ");
	memset(buffer, 0, 256);
	fgets(buffer, 255, stdin);
	n = write(sockfd, buffer, strlen(buffer)); // sending message to server

	if (n == -1) {
		error("Client: ERROR reading from socket");
	}

	memset(buffer, 0, 256);

	//reading message back from server
	n = read(sockfd, buffer, 255);
	if (n == -1) {
		error("Client: ERROR reading from socket");
	}

	printf("%s\n", buffer);


	close(sockfd); //closing socket

	return 0;

}


























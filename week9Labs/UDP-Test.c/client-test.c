#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> //constants
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> //defines structures for server info

#define BUFSIZE 1024

// error
void error(char *msg) {
	perror(msg);
	exit(0);
}

int main(int argc, char *argv[]) {
	int sockfd, portno, n;
	socklen_t serverlen;
	struct sockaddr_in serveraddr;
	struct hostent *server;
	char *hostname;
	char buf[BUFSIZE];

	//check cmd line arguments
	if (argc != 3) {
		fprintf(stderr, "usage %s <hostname><port>\n", argv[0]);
		exit(0);
	}

	hostname = argv[1];
	portno = atoi(argv[2]);

	//create socket
	sockfd = socket(PF_INET, SOCK_DGRAM, 0);
	if (sockfd < 0) {
		error("ERROR opening socket");
	}

	//gethostbyname: get the server's DNS entry
	server = gethostbyname(argv[1]);
	if (server == NULL) {
		fprintf(stderr, "ERROR, no such host as %s\n", hostname);
		exit(0);
	}	

	//build server internet address
	memset(&serveraddr, 0, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	bcopy((char*)server->h_addr, (char*)&serveraddr.sin_addr.s_addr, server->h_length);
	serveraddr.sin_port = htons(portno);

	//get message from user
	memset(buf, 0, BUFSIZE);
	printf("Please enter msg: ");
	fgets(buf, BUFSIZE, stdin);

	//send message to server
	serverlen = sizeof(serveraddr);
	n = sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr*) &serveraddr, serverlen);
	if (n<0) {
		error("ERROR in sendto");
	}

	//print server reply
	n = recvfrom(sockfd, buf, strlen(buf), 0, (struct sockaddr*) &serveraddr, &serverlen);
	if (n<0) {
		error("ERROR in recvfrom");
	}
	
	printf("Echo from server: %s", buf);
	close(sockfd);
	return 0;



}

































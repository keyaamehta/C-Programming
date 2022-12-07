#include <stdio.h>
#include <string.h> //memset()
#include <stdlib.h> //exit()
#include <unistd.h> //constants

#include <netdb.h> 
#include <sys/types.h> //define data types used in system calls
#include <sys/socket.h> //definitions of structures needed for sockets

#include <netinet/in.h> //constants and structures for Internet domain addresses

#include <arpa/inet.h> //needed for inet_ntoa()

#include <math.h>

#define BUFSIZE 1024

int power (int i) {
	int j, p=1;
	for (j=1; j<=1; j++) 
	p = p*2;
	return p;
}

int convertBinToDec (long int n) {
	int x, s=0, i=0, flag=1;
	while (flag==1) {
		x=n%10;
		s=s+x*power(i);
		i=i+1;
		n=n/10;
		if (n==0) {
			flag=0;
		}
	}
	return s;
}



//error
void error(char *msg) {
	perror(msg);
	exit(0);
} 

int main (int argc, char *argv[]) {
	int sockid;
	int portno;
	socklen_t clientlen; //size of client address
	struct sockaddr_in serveraddr; //server address
	struct sockaddr_in clientaddr; //client address
	struct hostent *hostp; //client host info
	char buf[BUFSIZE]; //message buffer
	char *hostaddrp; //dotted decimal host addr string
	int optval; //flag value for setsockopt
	int n; //message byte size

	if (argc != 2) {
		fprintf(stderr, "usage: %s <port>\n", argv[0]);
		exit(1);
	}

	portno = atoi(argv[1]);

	//create parent socket
	sockid = socket(PF_INET, SOCK_DGRAM, 0);
	if (sockid < 0) error("ERROR opening socket");

	//build server internet address
	memset(&serveraddr, 0, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons(portno);

	//bind: associate the parent socket with a port
	if (bind(sockid, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) == -1) {
		error("ERROR on binding");
	}

	//main loop: wait for datagram, then echo it
	clientlen = sizeof(clientaddr);
	while (1) {
		//recfrom: receive a UDP datagram from a client
		memset(buf, 0, BUFSIZE);
		n = recvfrom(sockid, buf, BUFSIZE, 0, (struct sockaddr*)&clientaddr, &clientlen);

		if (n<0) {
			error("ERROR in recvfrom");
		}

		//gethostbyaddr: determine who sent the datagram
		hostp = gethostbyaddr((struct clientaddr*)&clientaddr.sin_addr.s_addr, sizeof(clientaddr.sin_addr.s_addr), AF_INET);
		if (hostp == NULL) {
			error("ERROR on gethostbyaddr");
		}

		hostaddrp = inet_ntoa(clientaddr.sin_addr);
		if (hostaddrp == NULL) {
			error("ERROR on inet_ntoa\n");
		}

		long int binLong = atol(buf);

		int ans = convertBinToDec(binLong);

		sprintf(buf, "Decimal Value: %d", ans);
		printf("server received datagram from %s (%s)\n", hostp->h_name, hostaddrp);
		printf("server received %lu/%d bytes:%s\n", strlen(buf), n, buf);

		//send echo back to the client
		n = sendto(sockid, buf, strlen(buf), 0, (struct sockaddr*)&clientaddr, clientlen);
		if (n<0) {
			error("ERROR in sendto");
		}

	}

	close(sockid);

	return 0;

}




























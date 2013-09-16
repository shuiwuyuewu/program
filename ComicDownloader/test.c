#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
	int sockfd, n;
	struct sockaddr_in servaddr;
	char recvline[1024 + 1];
	char sendline[512];

	if((n = snprintf(sendline,strlen(sendline),"GET %s HTTP/1.0\n\n",argv[1])) < 0){
			printf("snprintf error\n");
			exit(-8);
	}
	sendline[n] = 0;

	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
			printf("socket error\n");
			exit(-1);
	}

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(80);
	if(inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0){
			printf("inet_pton error\n");
			exit(-2);
	}

	if(connect(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr)) < 0){
			printf("connect error\n");
			exit(-3);
	}

	if(write(sockfd,sendline,strlen(sendline)) == -1){
			printf("write error\n");
			exit(-7);
	}

	while((n = read(sockfd, recvline, 1024)) > 0){
			recvline[n] = 0;
			if(fputs(recvline, stdout) == EOF){
					printf("fputs error\n");
					exit(-4);
			}
	}
	if(n < 0){
		printf("read error");
		exit(-5);
	}
	exit(0);
}

#include "lib/unp.h"

void str_cli(FILE *fp, int sockfd);
int main(int argc, char **argv) {
	int sockfd;
	struct sockaddr_in servaddr;

	if(argc != 2) 
		return -1;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
	connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

	str_cli(stdin, sockfd);

	exit(0);
}


void str_cli(FILE *fp, int sockfd) {
	char recvline[MAXLINE], sendline[MAXLINE];
	while(Fgets(sendline, MAXLINE, fp) != NULL) {
		Writen(sockfd, sendline, strlen(sendline));
		if(Readline(sockfd, recvline, MAXLINE) == 0)
			err_quit("str_cli: server terminated prematurely");
		Fputs(recvline, stdout);
	}
}

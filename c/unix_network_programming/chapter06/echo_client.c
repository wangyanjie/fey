#include "lib/unp.h"

void str_cli(FILE *fp, int sockfd);
int max (int a, int b) { return a > b ? a : b; }
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
	int maxfdp1, stdineof;
	fd_set rset;
	char buf[MAXLINE];
	int n;

	stdineof = 0;
	FD_ZERO(&rset);
	for(;;) {
		if(stdineof == 0) {
			FD_SET(fileno(fp), &rset);
		}
		FD_SET(sockfd, &rset);
		maxfdp1 = max(fileno(fp), sockfd) + 1;
		select(maxfdp1, &rset, NULL, NULL, NULL);

		if(FD_ISSET(sockfd, &rset)) {
			if((n = read(sockfd, buf, MAXLINE)) == 0) {
				if(stdineof == 1) {
					return;
				} else {
					err_quit("str_cli: server terminated prematurely");
				}
			}
			write(fileno(stdout), buf, n);
		}

		if(FD_ISSET(fileno(fp), &rset)) {
			if((n = read(fileno(fp), buf, MAXLINE)) == 0) {
				stdineof = 1;
				shutdown(sockfd, SHUT_WR);
				FD_CLR(fileno(fp), &rset);
				continue;
			}
			Writen(sockfd, buf, n);
		}
	}
}

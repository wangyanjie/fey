#include "lib/unp.h"

int main() {
	int listenfd, connfd, sockfd;
	struct sockaddr_in servaddr, cliaddr;
	socklen_t clilen;
	ssize_t n;
	char buf[MAXLINE];
	fd_set rset, allset;
	int client[FD_SETSIZE];
	int i, maxi, maxfd, nready;

	listenfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(PORT);

	bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
	listen(listenfd, 5);

	maxi = -1;
	for(i = 0; i < FD_SETSIZE; ++i) {
		client[i] = -1;
	}
	maxfd = listenfd;
	FD_ZERO(&allset);
	FD_SET(listenfd, &allset);
	rset = allset;

	for(;;) {
		nready = select(maxfd + 1, &rset, NULL, NULL, NULL);

		if(FD_ISSET(listenfd, &rset)) {
			clilen = sizeof(clilen);
			connfd = accept(listenfd, (struct sockaddr *) &cliaddr, &clilen);
			for(i = 0; i < FD_SETSIZE; ++i) {
				if(client[i] < 0) {
					client[i] = connfd;
					break;
				}
			}
			if(i == FD_SETSIZE) {
				err_quit("too many client");
			}
			FD_SET(connfd, &rset);
			if(connfd > maxfd) {
				maxfd = connfd;
			}
			if(i > maxi) {
				maxi = i;
			}
			if(--nready <= 0) {
				continue;
			}
		}
		
		for(i = 0; i <= maxi; ++i) {
			if((sockfd = client[i]) < 0) {
				continue;
			}
			if(FD_ISSET(sockfd, &rset)) {
				if((n = read(sockfd, buf, MAXLINE)) == 0) {
					close(sockfd);
					FD_CLR(sockfd, &rset);
					client[i] = -1;
				} else {
					writen(sockfd, buf, n);
				}
			}

			if(--nready <= 0) {
				break;
			}
		}
	}
}

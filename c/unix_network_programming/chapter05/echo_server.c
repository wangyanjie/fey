#include "lib/unp.h"

void str_echo(int sockfd);

int main() {
  int listenfd, connfd;
  struct sockaddr_in servaddr, cliaddr;
  socklen_t clilen;
  pid_t childpid;
	void sig_chld(int);

  listenfd = socket(AF_INET, SOCK_STREAM, 0);

  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(PORT);

  bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
  listen(listenfd, 5);

	signal(SIGCHLD, sig_chld);

  for(;;) {
    clilen = sizeof(clilen);
    if((connfd = accept(listenfd, (struct sockaddr *) &servaddr, &clilen))
				< 0) {
			if(errno == EINTR) {
				continue;
			} else {
				err_sys("accept error");
			}
		}

    if((childpid = fork()) == 0) {
      close(listenfd);
      str_echo(connfd) ;
      exit(0);
    }

    close(connfd);
  }
}

void str_echo(int sockfd) {
  ssize_t n;
  char buf[MAXLINE];
again:
  while((n = read(sockfd, buf, MAXLINE)) > 0)
    Writen(sockfd, buf, n);

  if(n < 0 && errno == EINTR)
    goto again;
  else if(n < 0)
		err_sys("str_echo: read error");
}

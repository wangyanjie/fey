objects=lib/unp.h lib/writen.c lib/readn.c lib/readline.c \
				lib/wrapstdio.c lib/signal.c lib/sig_chld.c lib/error.c

main : server client

server : $(objects) echo_server.c
	gcc -g $(objects) echo_server.c -o server

client : $(obkects) echo_client.c
	gcc -g $(objects) echo_client.c -o client

objects=lib/unp.h lib/writen.c lib/readn.c lib/readline.c\
				lib/error.c lib/wrapstdio.c 

main : client server

client : $(objects) echo_client.c
	gcc -g $(objects) echo_client.c -o client

server : $(objects) echo_server.c
	gcc -g $(objects) echo_server.c -o server

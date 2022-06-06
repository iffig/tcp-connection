#include <stdio.h>
#include <unistd.h> 
#include <arpa/inet.h>
#include <string.h>
#include <sys/socket.h>
#include <fcntl.h> 

#define SOCKET_CREATE_FAILURE -2
#define SOCKET_BIND_FAILURE   -3
#define SOCKET_LISTEN_FAILURE -4
#define CLIENT_ACCEPT_FAILURE -5
#define MAX 80

#define SA struct sockaddr
typedef struct sockaddr_in sockaddr_in;
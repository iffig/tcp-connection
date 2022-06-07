#ifndef _TCP_CONNECTION_H
#define _TCP_CONNECTION_H

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

int receive(int socket_id);
sockaddr_in get_socket_address(char *ip, int port);
int create_server_socket(char *ip, int port);
int create_client_socket(char *ip, int port);

void run_server(char *ip, int port);
void run_client(char *ip, int port);
#endif 
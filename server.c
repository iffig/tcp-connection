#include "tcp.h"

int receive(int socket_id) {
    sockaddr_in cli;
    int len = sizeof(cli);
    char buff[MAX];
    int n;

    int connfd = accept(socket_id, (SA*)&cli, &len);
    if (connfd < 0) {
        fprintf(stderr, "Failed to accept client.\n");
        return(CLIENT_ACCEPT_FAILURE);
    }
    fprintf(stderr, "Client accepted.\n");

    while(1) {
        bzero(buff, MAX);
        read(connfd, buff, sizeof(buff));
        fprintf(stderr, "From client: %s\t To client : ", buff);
        bzero(buff, MAX);
        n = 0;
        while ((buff[n++] = getchar()) != '\n');
   
        write(connfd, buff, sizeof(buff));
           if (strncmp("exit", buff, 4) == 0) {
            printf("Server Exit...\n");
            break;
        }
    }
}

sockaddr_in get_socket_address(char *ip, int port){
    fprintf(stderr, "Creating Socket Address: %s:%d\n",ip, port);
    sockaddr_in address; 
    bzero(&address, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(ip);
    address.sin_port = htons(port);
    return address;
}

int establish_server(){
    sockaddr_in servaddr = get_socket_address("127.0.0.1", 8080); 
    int socket_id = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_id == -1) {
        fprintf(stderr, "Failed to create socket.\n");
        return(SOCKET_CREATE_FAILURE);
    }
    fprintf(stderr, "Socket [%d] created.\n", socket_id);
   
    if ((bind(socket_id, (SA*)&servaddr, sizeof(servaddr))) != 0) {
        fprintf(stderr, "Filed to bind socket [%d] to address.\n", socket_id);
        return(SOCKET_BIND_FAILURE);
    }

    fprintf(stderr, "Socket successfully binded..\n");
    if ((listen(socket_id, 5)) != 0) {
        fprintf(stderr, "Failed to listen on socket [%d]\n", socket_id);
        return(SOCKET_LISTEN_FAILURE);
    }
    fprintf(stderr, "Server listening..\n");
    return socket_id; 
}


int main(){
    int socket_id = establish_server();
    if(socket_id < 0){
        return socket_id; 
    }
   
    receive(socket_id);
   
    close(socket_id);
    return(0);
}


   
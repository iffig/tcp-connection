#include "tcp.h"
#include "stdbool.h"
#include <stdlib.h>


void print_usage(char *prog){

    fprintf(stderr, "\n");
    fprintf(stderr, "[ %s Usage ]\n", prog);
    fprintf(stderr, "%s [ Required: -s | -c ] [Optional: -i <ip-address>, -p <port>]>\n", prog);
    fprintf(stderr, "-s | Run server\n");
    fprintf(stderr, "-c | Run client\n");
    fprintf(stderr, "-i | Set ip address, if not set default 127.0.0.1 is used\n");
    fprintf(stderr, "-p | Set port, if not set default 8080 is used\n");
    fprintf(stderr, "\n");
}

int main(int argc, char **argv){

    bool server = false; 
    bool client = false; 
    char ip[16] = "127.0.0.1";
    int port = 8080;
    int opt;  
    while((opt = getopt(argc, argv, "sci:p:")) != -1) { 
        switch(opt) 
        { 
            case 's':
                server = true;
                break; 
            case 'c':
                client = true; 
                break;
            case 'i':
                strcpy(ip,optarg);
                break;
            case 'p':
                port = atoi(optarg); 
                break;
            default:
                print_usage(argv[0]);
                return(-1);
        } 
    } 

    if(client && server){
        fprintf(stderr, "Cannot run server and client in one instance.\n");
        print_usage(argv[0]);
        return(-1);
    }else if(!client && !server){
        fprintf(stderr, "Please choose server or client mode.\n");
        print_usage(argv[0]);
        return(-1);
    }
    fprintf(stderr, "%s:%d\n", ip, port);

    if(client){
        fprintf(stderr, "Running Client.\n");
        run_client(ip, port);
    } else if(server){
        fprintf(stderr, "Running Server.\n");
        run_server(ip, port);
    }

}
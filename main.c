#include "tcp.h"
#include "stdbool.h"

int main(int argc, char **argv){

    bool server = false; 
    bool client = false; 

    int opt;  
    while((opt = getopt(argc, argv, "sc")) != -1) { 
        switch(opt) 
        { 
            case 's':
                server = true;
                break; 
            case 'c':
                client = true; 
                break;
            default:
                return(-1);
        } 
    } 

    if(client && server){
        fprintf(stderr, "Cannot run server and client in one instance.\n");
        return(-1);
    }else if(!client && !server){
        fprintf(stderr, "Please choose server or client mode.\n");
        return(-1);
    }

    if(client){
        fprintf(stderr, "Running Client.\n");
        run_client("127.0.0.1", 8080);
    } else if(server){
        fprintf(stderr, "Running Server.\n");
        run_server("127.0.0.1", 8080);
    }

}
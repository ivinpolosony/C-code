#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h> //read
#include <arpa/inet.h>
#include <string.h>


#define PORT_NO 1234

class Socket_server{
    int socket_file_descriptor , new_socket_file_descriptor ;
    socklen_t client_addr_length;
    char buffer[256];
    struct sockaddr_in server_addr , client_addr;
    struct hostent *client_addr_; /* client host info */
    int read_buffer;

    server_addr.sin_family = AF_INET; // ipv4 ipv6
    server_addr.sin_addr.s_addr = INADDR_ANY; // binds to any interface thats available
    server_addr.sin_port = htons(PORT_NO); //htons converts the host byte order to n/w byte order

    void Socket_server(){
        this.socket_file_descriptor = socket(AF_INET,SOCK_STREAM,0);  //socket(int __domain, int __type, int __protocol)
        if(socket_file_descriptor < 0){
            std::cout << "ERROR OPENING SOCKETS"  << "\n";
            exit(0);
        }
    }


}

    int main(int argc, char *argv[])
    {
        Socket_server obj1;
        return 0;
    }

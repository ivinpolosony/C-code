#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h> //read
#include <arpa/inet.h>
#include <string.h>


#define PORT_NO 1234
void error_0( std::string );

int socket_init(){

    struct hostent *client_addr_; /* client host info */
    int read_buffer,socket_file_descriptor;
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET; // ipv4 ipv6
    server_addr.sin_addr.s_addr = INADDR_ANY; // binds to any interface thats available
    server_addr.sin_port = htons(PORT_NO); //htons converts the host byte order to n/w byte order
    socket_file_descriptor = socket(AF_INET,SOCK_STREAM,0);
    if(socket_file_descriptor < 0)
        error_0("ERROR OPENING SOCKETS");
    return (socket_file_descriptor) ;  //socket(int __domain, int __type, int __protocol)
}

void socket_bind(int *socket_file_descriptor){
    struct sockaddr_in server_addr;
    if ( bind(*socket_file_descriptor , (struct sockaddr * )&server_addr , sizeof(server_addr) )  < 0 ){ // bind(int __fd, const struct sockaddr *__addr, socklen_t __len) "assigning a name to a socket"
        error_0("ERROR on binding");
    }
}

void  socket_listen(int *socket_file_descriptor){
    int backlog= 5;
    listen(*socket_file_descriptor,backlog);
}
void  socket_accept(int *socket_file_descriptor){

}


void error_0( std::string str){
    std::cout << "ERROR on "<< str  << "\n";
    exit(0);
}


int
main(int argc, char *argv[]){

    int socket_file_descriptor , new_socket_file_descriptor , read_buffer;
    char buffer[256];
    struct hostent *client_addr_; /* client host info */
    struct sockaddr_in client_addr;
    socklen_t client_addr_length;

    socket_file_descriptor = socket_init();
    socket_bind(&socket_file_descriptor);
    socket_listen(&socket_file_descriptor);
    client_addr_length = sizeof(sockaddr_in);

    socket_file_descriptor = accept(socket_file_descriptor , (struct sockaddr *) &client_addr , &client_addr_length);
    if(socket_file_descriptor < 0 ){
        error_0("ERROR on accept()" );
    }

    read_buffer = read(new_socket_file_descriptor , buffer ,256 ); // read(int __fd, const struct iovec *__iovec, int __count)

    if(read < 0){
        error_0("ERROR reading from socket");
    }

    client_addr_ = gethostbyaddr((const char *) &client_addr.sin_addr.s_addr,sizeof(client_addr.sin_addr.s_addr) , AF_INET);

    if(client_addr_ !=NULL){
        std::cout << "Server established connection with client "  << client_addr_->h_name << "(" << inet_ntoa(client_addr.sin_addr) << ":"<<  ntohs(client_addr.sin_port) << ")" <<"\n";
    }else{
//        error_0("ERROR getting hostname");
        std::cout << "Server established connection with client  "  << inet_ntoa(client_addr.sin_addr) << ":"<< ntohs(client_addr.sin_port) <<"\n";
    }
    //   char * client_addr_port = inet_ntoa(client_addr.sin_addr);


    //   get_in_addr((struct sockaddr *)&client_addr),s.c_str(), sizeof s);
    std::cout << "Here is the message: "  << client_addr.sin_addr.s_addr<<"\n";
    std::cout << "Here is the message: "  << read_buffer <<"\n";


return 0;
}

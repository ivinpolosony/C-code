#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h> //read

#include <string.h>


#define PORT_NO 1234
#define HOST "localhost"

int main(int argc, char *argv[])
{
    int socket_file_descriptor , write_buffer;
    struct sockaddr_in server_addr;
    struct hostent *server;
    std::string  buffer = "aaaaaaaaaaaaaaaah\n";

    socket_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);

    if(socket_file_descriptor < 0){
        std::cout << "Error opening socket"  << "\n";
        exit(1);
    }

    server = gethostbyname(HOST);
    server_addr.sin_family = AF_INET; // ipv4 ipv6
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length); // src -> dest
    server_addr.sin_port = htons(PORT_NO); //htons converts the host byte order to n/w byte order

    //connect to server
    if( connect(socket_file_descriptor, (struct sockaddr*) &server_addr , sizeof(server_addr)) < 0){
        std::cout << "Error connecting to server "  << "\n";
        exit(1);
    }

    //Sending data to server

    write_buffer = write(socket_file_descriptor, buffer.c_str(), buffer.length());

    if(write_buffer < 0){
        std::cout << "Error reading from socket "  << "\n";
        exit(1);
    }

    std::cout << buffer  << "\n";


    return 0;
}

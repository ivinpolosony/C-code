#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h> //read
#include <arpa/inet.h>
#include <string.h>


#define PORT_NO 1234
// implementation in linux
/////////////////////////////////////////////////////////////////////
// struct sockaddr_in {                                            //
//     short            sin_family;   // e.g. AF_INET              //
//     unsigned short   sin_port;     // e.g. htons(3490)          //
//     struct in_addr   sin_addr;     // see struct in_addr, below //
//     char             sin_zero[8];  // zero this if you want to  //
// };                                                              //
//                                                                 //
// struct in_addr {                                                //
//     unsigned long s_addr;  // load with inet_aton()             //
// };                                                              //
/////////////////////////////////////////////////////////////////////


int main(int argc, char *argv[])
{
    int socket_file_descriptor , new_socket_file_descriptor ;
    socklen_t client_addr_length;
    char buffer[256];
    struct sockaddr_in server_addr , client_addr;
    struct hostent *client_addr_; /* client host info */
    int read_buffer;

    server_addr.sin_family = AF_INET; // ipv4 ipv6
    server_addr.sin_addr.s_addr = INADDR_ANY; // binds to any interface thats available
    server_addr.sin_port = htons(PORT_NO); //htons converts the host byte order to n/w byte order

    socket_file_descriptor = socket(AF_INET,SOCK_STREAM,0);  //socket(int __domain, int __type, int __protocol)
    if(socket_file_descriptor < 0){
        std::cout << "ERROR OPENING SOCKETS"  << "\n";
        exit(0);
    }

    /** bind */
    if ( bind(socket_file_descriptor , (struct sockaddr * )&server_addr , sizeof(server_addr) )  < 0 ){ // bind(int __fd, const struct sockaddr *__addr, socklen_t __len) "assigning a name to a socket"
        std::cout << "ERROR on binding"  << "\n";
        exit(0);
    }

    
    int backlog= 5;
   /**
   listen() marks the socket referred to by sockfd as a passive socket, that is,
   as a socket that will be used to accept incoming connection requests using accept().

   The socket_file_descriptor argument is a file descriptor that refers to a socket of
   type SOCK_STREAM or SOCK_SEQPACKET.

   The backlog argument defines the maximum length to which the queue of pending connections
   for sockfd may grow. If a connection request arrives when the queue is full, the client
   may receive an error with an indication of ECONNREFUSED or, if the underlying protocol
   supports retransmission, the request may be ignored so that a later reattempt at connection succeeds.

    */
    listen(socket_file_descriptor,backlog );

    /*
      accept() extracts the first connection request on the queue of pending connections
      for the listening socket, sockfd, creates a new connected socket, and returns a
      new file descriptor referring to that socket. The newly created socket is not in
      the listening state. The original socket sockfd is unaffected by this call.
    */
    client_addr_length = sizeof(sockaddr_in);
    new_socket_file_descriptor = accept(socket_file_descriptor , (struct sockaddr *) &client_addr , &client_addr_length); // accept(sfd, (struct sockaddr *) &peer_addr,    &peer_addr_size);

    if(new_socket_file_descriptor < 0 ){
        std::cout << "ERROR on accept()"  << "\n";
        exit(0);
    }
    //  read() attempts to read up to count bytes from file descriptor fd into the buffer starting at buf.
    read_buffer = read(new_socket_file_descriptor , buffer ,256 ); // read(int __fd, const struct iovec *__iovec, int __count)

    if(read < 0){
        std::cout << "ERROR reading from socket" << "\n";
        exit(0);
    }
    char s[100];

    ///////////////////////////////////////////////////////////////////////////
    //                               gethostbyaddr                           //
    ///////////////////////////////////////////////////////////////////////////

    client_addr_ = gethostbyaddr((const char *) &client_addr.sin_addr.s_addr,sizeof(client_addr.sin_addr.s_addr) , AF_INET);

    if(client_addr_ ==NULL){
        std::cout << "ERROR getting hostname" << "\n";
    }
//    char * client_addr_port = inet_ntoa(client_addr.sin_addr);
    std::cout << "Server established connection with  "  << client_addr_->h_name << inet_ntoa(client_addr.sin_addr) <<"\n";

//   get_in_addr((struct sockaddr *)&client_addr),s.c_str(), sizeof s);
    std::cout << "Here is the message: "  << client_addr.sin_addr.s_addr<<"\n";
    std::cout << "Here is the message: "  << buffer<<"\n";
return 0;
}

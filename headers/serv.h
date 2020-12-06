#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

class server{
    int serverf, sock, reader;
    struct sockaddr_in address;
    int opt = 1;
    int laddr = sizeof(address);
    char buff[1024] = {0};
   // std::string ip = "";
    int port = 1337;
    //char *hello = "Hello there";
public:
    //server(std::string ip, int port);
    void init_ser();
};
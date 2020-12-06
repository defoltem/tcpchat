#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>

class client{
    int sock, reader;
    struct sockaddr_in addr;
    std::string ip = "127.0.0.1";
    int port = 1337;
    std::string messg = "";
    char buff[1024] = {0};
public:
    void con_to_serv();
};
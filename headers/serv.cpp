#include "serv.h"

//server::server(std::string ip, int port) : ip(ip), port(port) {}

void server::init_ser(){    
    if((serverf = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        std::cout << "falied to create a socket\n";
        exit(0);
    }
    if (setsockopt(serverf, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        std::cout << "error with setsockopt\n";
        exit(0);
    }
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(INADDR_ANY); // there will be an ip instead of localhost
    if (bind(serverf, (struct sockaddr *)&address, sizeof(address)) < 0){
        std::cout << "failed to bind\n";
        exit(0);
    }
    if (listen(serverf, 5) < 0){
        std::cout << "failed to listen\n";
        exit(0);
    }
    if ((sock = accept(serverf, (struct sockaddr *)&address, (socklen_t*)&laddr)) < 0){
        std::cout << "failed to create a new connection\n";
        exit(0);
    }
    std::string hellot = "Hello there";
    reader = read(sock, buff, 1024);
    std::cout << buff << '\n';
    send(sock, hellot.c_str(), hellot.length(), 0);
}
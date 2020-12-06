#include "clie.h"

void client::con_to_serv(){
    std::cout << "write something: ";
    getline(std::cin, messg);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip.c_str()); // creating the addr
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        std::cout << "socket hasn't created\n";
        exit(0);
    }
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0){
        std::cout << "connection failed\n";
        exit(0);
    }
    send(sock, messg.c_str(), messg.length(), 0);
    reader = read(sock, buff, 1024);
    std::cout << buff << '\n';
}
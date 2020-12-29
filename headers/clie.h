#include <iostream>
#include <string>
#include <thread>
#include <functional>
#include <stdio.h>
#include <vector>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>

class client{
    int sock, reader;
    struct sockaddr_in addr;
    std::string ip = "";
    int port = 1337;
    std::vector<char> buff{std::vector<char>(1024)};
    std::string messg = "";
public:
    client(std::string ip, int port);
    void buff_clear(std::vector<char> &b);
    void con_to_serv();
    void waiting_and_display_msg();
};
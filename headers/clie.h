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
    std::string ip = "127.0.0.1";
    int port = 1337;
    std::string messg = "";
public:
    void buff_clear(std::vector<char> &b);
    void con_to_serv();
    void waiting_and_display_msg(int sock, int reader, std::vector<char> &b);
};
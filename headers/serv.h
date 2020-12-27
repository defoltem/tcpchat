#include <iostream>
#include <vector>
#include <thread>
#include <string>
#include <functional>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

class server{
    const std::string alp = "qwertyuiopasdfghjklzxcvbnm1234567890QWERTYUIOPASDFGHJKLZXCVBNM";
    int serverf;
    int id_getter = 0;
    struct sockaddr_in address;
    //std::string name = "";
    //std::string respons = "";
    int opt = 1;
    int laddr = sizeof(address);
    int port = 1337;
    std::vector<int> clients{std::vector<int>(5,0)};
public:
    //server(int port);
    void discuss();
    void buff_clear(std::vector<char> &b);
    void init_ser();
};
#include "clie.h"
// TASK: CHANGE AN INTERFACE TO NCURSES
client::client(std::string ip, int port) : ip(ip), port(port) {}

void client::buff_clear(std::vector<char> &b){
        for(size_t i = 0; i < b.size(); i++){
        if (b.at(i) == '\000') return;
        b.at(i) = '\000';
    }
}

void client::waiting_and_display_msg(){
    while(1){
        reader = read(sock, buff.data(), 1024);
        //std::cout << '\n';
        for(const char c:buff){
            std::cout << c;
        }
        std::cout << '\n';  
    }
}

void client::con_to_serv(){
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
    std::string name = "";
    std::cout << "write your name: ";
    getline(std::cin, name);
    send(sock, name.c_str(), name.length(), 0);
    //std::vector<char> buff(1024);
    std::thread waitndis(std::bind(&client::waiting_and_display_msg, this));
    waitndis.detach();
    while(1){
    std::cout << ">";
    getline(std::cin, messg);
    send(sock, messg.c_str(), messg.length(), 0);
    try{
    }catch(const std::system_error& e) {
        std::cout << "code: " << e.code() << " meaning " << e.what() << '\n';
    }
    messg = "";
    std::cout << '\n';
    }
}
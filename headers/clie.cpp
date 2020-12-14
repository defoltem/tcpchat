#include "clie.h"

void client::buff_clear(std::vector<char> &b){
    for(size_t i = 0; i < b.size(); i++){
        if (b.at(i) == '\000') return;
        b.at(i) = '\000';
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
    std::string perem = "";
    while(1){
    std::cout << ">";
    getline(std::cin, messg);
    send(sock, messg.c_str(), messg.length(), 0);
    //reader = read(sock, buff.data(), 1024);
    //for(const char c:buff){
        //std::cout << c;
     //   perem += c;
   // /
    //size_t pos = perem.find("def");
    //perem = perem.substr(pos);
    std::cout << name << ": " << messg;    
    messg = "";
    std::cout << '\n';
    //buff_clear(buff);
    //std::cout << buff << '\n';
    }
}
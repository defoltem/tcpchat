#include "serv.h"
// TASKS: REMOVE HARDCODE, FIX BUGS 

void server::discuss(){
    int sock, reader;
    int id = id_getter;
    std::string name = "";
    std::string respons = "";
    if ((sock = accept(serverf, (struct sockaddr *)&address, (socklen_t*)&laddr)) < 0){
        std::cout << "failed to create a new connection\n";
        exit(0);
    }
    clients.at(id) = sock;
    std::vector<char> buff(1024);
    reader = read(sock, buff.data(), 1024); // confirming name
    for(const char c:buff){
        //std::cout << c;
        name += c;
    }
    buff_clear(buff);
    for (size_t i = 0; i < name.length(); i++){
        if (alp.find(name.at(i)) == std::string::npos){
            name = name.substr(0, i);
            break;
        }
    }
    std::cout << name << " has connected\n";
    while(1){
    reader = read(sock, buff.data(), 1024);
    //std::cout << name << ": ";
    for(const char c:buff){
       // std::cout << c;
        respons += c;
    }
    respons =  name + ": " + respons;
    std::cout << respons <<'\n';
    for (size_t j = 0; j < 5; j++) {
        send(clients.at(j), respons.c_str(), respons.length(), 0);
    }
    respons = "";
    buff_clear(buff);
    }
}

void server::buff_clear(std::vector<char> &b){
    for(size_t i = 0; i < b.size(); i++){
        if (b.at(i) == '\000') return;
        b.at(i) = '\000';
    }
}

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
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(serverf, (struct sockaddr *)&address, sizeof(address)) < 0){
        std::cout << "failed to bind\n";
        exit(0);
    }
    if (listen(serverf, 5) < 0){
        std::cout << "failed to listen\n";
        exit(0);
    }
    //while(1){
        /*if ((sock = accept(serverf, (struct sockaddr *)&address, (socklen_t*)&laddr)) < 0){
            std::cout << "failed to create a new connection\n";
            exit(0);
        }*/
        for(size_t i = 0; i < 5; i++){
            //if (clients.at(i) == 0) {
                //clients.at(i) = sock;
                std::thread sock_thread(&server::discuss, this); // why the fuck it don't get any varible?
                sock_thread.detach();
                id_getter++;
                //clients_threads.at(i) = std::move(sock_thread);
                //clients_threads.at(i).detach();
                //discuss();
              //  break;
            //}
        }
        while(1) {}; 
    //}
}
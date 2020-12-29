#include "headers/clie.h"
int main(){
    std::string ip = "";
    int port = 0;
    std::cout << "write an ip ? ";
    getline(std::cin, ip);
    std::cout << "write a port ? ";
    std::cin>>port;
    client cl(ip , port);
    cl.con_to_serv();
    return 0;
}

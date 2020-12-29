#include "headers/serv.h"
int main(){
    int port = 0;
    std::cout << "write a port ? ";
    std::cin>>port;
    server sr(port);
    sr.init_ser();
    return 0;
}

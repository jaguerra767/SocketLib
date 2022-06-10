#include <sys/types.h>
#include <sys/socket.h>
#include <string>
#include "Socket.hpp"

extern "C" int getaddrinfo(const char *node, const char *service, const struct addrinfo *hints, struct addrinfo **res);

Socket::Socket(std::string ip_addr, std::string port_no, int type, int domain, int protocol):ip_address(ip_addr),port_number(port_no)
{
    socket_ = socket(domain, type, protocol);
    if (socket_ == -1){
        //handle error
    }
    type_ = type;
    domain_ = domain;
    protocol_ = protocol;
}

bool Socket::getaddrinfo(){
    return getaddrinfo(node.c_str(), port_number.c_str(), &hints, &servinfo)!= 0 ;
}
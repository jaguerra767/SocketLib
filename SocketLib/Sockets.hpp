//
//  Sockets.hpp
//  SocketLib
//
//  Created by Jorge Antonio Guerra on 6/8/22.
//

#ifndef Sockets_hpp
#define Sockets_hpp

#include <sys/types.h>
#include <sys/socket.h>
#include <string>
#include <netdb.h>

class TCPClient{
public:
    TCPClient(std::string ip_address, std::string port_number);
    ~TCPClient();
    int ClientConnect();
private:
    std::string ip_address_;
    std::string port_number_;
    int socket_;
    struct addrinfo hints;
    struct addrinfo *servinfo;
    struct addrinfo *p;
};

TCPClient::TCPClient(std::string ip_address, std::string port_number):ip_address_(ip_address),port_number_(port_number){
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    
} 
int TCPClient::ClientConnect(){
    if (getaddrinfo(ip_address_.c_str(), port_number_.c_str(), &hints, &servinfo)==-1){
        //TODO: Error handling
    }
    for  (p = servinfo; p != NULL; p = p->ai_next){
        socket_ = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (socket_!=-1){
            return connect(socket_, p->ai_addr, p->ai_addrlen);
        }
        return -1;
    }
    


    //int res = connect(socket_, ip)
}

class TCPServer{
    TCPServer();
    ~TCPServer();
};

class UDPClient{
    UDPClient();
    ~UDPClient();
};

class UDPServer{
    UDPServer();
    ~UDPServer();
};



#endif /* Sockets_h */

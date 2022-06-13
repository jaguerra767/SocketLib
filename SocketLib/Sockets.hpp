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
    int Connect();
    int Receive();
    int Send(std::string msg);
private:
    std::string ip_address_;
    std::string port_number_;
    std::string rx_message_;
    int socket_;
    struct addrinfo hints_;
    struct addrinfo *servinfo_;
    struct addrinfo *p_;
};

TCPClient::TCPClient(std::string ip_address, std::string port_number):ip_address_(ip_address),port_number_(port_number){
    hints_.ai_family = AF_UNSPEC;
    hints_.ai_socktype = SOCK_STREAM;
    
} 
int TCPClient::Connect(){
    if (getaddrinfo(ip_address_.c_str(), port_number_.c_str(), &hints_, &servinfo_) == -1){
        return -1;
    }
    for  (p_ = servinfo_; p_ != NULL; p_ = p_->ai_next){
        socket_ = socket(p_->ai_family, p_->ai_socktype, p_->ai_protocol);
        if (socket_!=-1){
            return connect(socket_, p_->ai_addr, p_->ai_addrlen);
        }
        if (p_ == NULL){
            return -1;
        }
    }
}

int TCPClient::Receive(){
    char buffer[1024] = {0};
    rx_message_.clear();
    int res = recv(socket_, buffer, sizeof(buffer), 0);
    rx_message_ = std::string(buffer);
    return res;
}

int TCPClient::Send(std::string msg){
   return send(socket_, msg.c_str(), msg.length(), 0);
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

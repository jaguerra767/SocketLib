//
//  Socket.hpp
//  SocketLib
//
//  Created by Jorge Antonio Guerra on 6/8/22.
//

#ifndef Socket_hpp
#define Socket_hpp

//#include <sys/types.h>
//#include <sys/socket.h>
#include <string>
#include <netdb.h>



class Socket {
public:
    int socket_file_descriptor;
    int error_code;
    struct addrinfo hints;
    struct addrinfo *servinfo;
    struct addrinfo *p;
    bool getaddrinfo(const std::string node, const std::string service, const struct addrinfo *hints, const struct addrinfo **res);
    bool bind(int sockfd, const struct sockaddr *addr, socklen_t address_len); 
    bool connect(int sockfd, const struct sockaddr *addr, socklen_t addres_len);
    bool listen(int sockfd, int backlog);
    bool accept(int sockfd, struct sockaddr *addr, socklen_t *addr_len); 
    bool close(int sockfd);
    bool shutdown(int sockfd, int how);
};

class TCPSocket :public Socket{
public:
    TCPSocket();
    ~TCPSocket();
    template<typename T>
    bool send(int sockfd, const T msg, int len, int flags);
    template<typename T>
    bool recv(int sickfd, T buffer, int len, int flags);
};

class UDPSocket :public Socket{
    UDPSocket();
    ~UDPSocket();
};



#endif /* Socket_h */

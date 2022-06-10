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
    Socket(std::string ip_addr, std::string port_no, int type, int domain, int protocol):ip_address(ip_addr),port_number(port_no){};
    ~Socket();
    int error_code;
    std::string ip_address;
    bool getaddrinfo(const std::string node);
    bool bind(const struct sockaddr *addr, socklen_t address_len); 
    bool connect(const struct sockaddr *addr, socklen_t addres_len);
    bool listen(int backlog);
    bool accept(struct sockaddr *addr, socklen_t *addr_len); 
    bool close();
    bool shutdown(int how);
private:
    struct addrinfo hints;
    struct addrinfo *servinfo;
    struct addrinfo *p;
    int socket_;
    std::string port_number;
    int socket_file_descriptor;
    int type_;
    int domain_;
    int protocol_;
};

class TCPSocket :public Socket{
public:
    TCPSocket(const std::string ip_addr, const std::string port_number);
    ~TCPSocket();
    bool send(int sockfd, void* msg, int len, int flags);
    bool recv(int sockfd, void* buffer, int len, int flags);
};

class UDPSocket :public Socket{
public:
    UDPSocket();
    ~UDPSocket();
    bool sendto(int sockfd, void* msg, int len, int flags);
    bool recvfrom(int sockfd, void* buffer, int len, int flags);
};
#endif /* Socket_h */

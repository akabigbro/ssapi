#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include "inet.h"

class TcpSocket : public Inet
{
protected:
    virtual ssize_t Read(int fd, char * buffer, size_t max, int flags) throw(int&);
    virtual ssize_t Send(int fd, const char * buffer, size_t max, int flags) throw(int&);
public:
    TcpSocket(void) {};
    TcpSocket(unsigned short int port);
    TcpSocket(const char * hostname, unsigned short int port);
    ~TcpSocket(void);

    virtual ssize_t Read(char * buffer, size_t max, int flags = 0) throw(int&);
    virtual ssize_t Send(const char * buffer, size_t max, int flags = 0) throw(int&);
};

#endif//TCPSOCKET_H

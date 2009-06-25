#ifndef UDPSOCKET_H
#define UDPSOCKET_H

#include "inet.h"

class UdpSocket : public Inet
{
protected:
    virtual ssize_t Read(int fd, char * buffer, size_t max, int flags) throw(int&);
    virtual ssize_t Send(int fd, const char * buffer, size_t max, int flags) throw(int&);
public:
    UdpSocket(unsigned short int port);
    UdpSocket(const char * hostname, unsigned short int port);
    ~UdpSocket(void);

    virtual ssize_t Read(char * buffer, size_t max, int flags = 0) throw(int&);
    virtual ssize_t Send(const char * buffer, size_t max, int flags = 0) throw(int&);
};

#endif//UDPSOCKET_H

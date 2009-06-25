#ifndef ADDRESS_H
#define ADDRESS_H

#include "socket.h"

class Address : public Socket
{
protected:
    size_t size;
    struct sockaddr * address;

    virtual ssize_t ReadFrom(int fd, char * buffer, size_t max, int flags) throw(int&);
    virtual ssize_t SendTo(int fd, const char * buffer, size_t max, int flags) throw(int&);

    virtual ssize_t Read(int fd, char * buffer, size_t max, int flags) throw(int&)=0;
    virtual ssize_t Send(int fd, const char * buffer, size_t max, int flags) throw(int&)=0;

    void Bind(sockaddr * address, size_t size);
public:
    Address(void) {};
    Address(int domain, int type, int protocol);
    ~Address(void);

    void Connect(void) throw(int&);
    void Listen(int pending) throw(int&);
    void Accept(Address * address) throw(int&);

    virtual ssize_t Read(char * buffer, size_t max, int flags = 0) throw(int&);
    virtual ssize_t Send(const char * buffer, size_t max, int flags = 0) throw(int&);
};

#endif//ADDRESS_H

#ifndef INET_H
#define INET_H

#include <netinet/in.h>
#include <netdb.h>
#include "address.h"

class Inet : public Address
{
protected:
    struct sockaddr_in address;

    ssize_t ReadFrom(int fd, char * buffer, size_t max, int flags) throw(int&);
    ssize_t SendTo(int fd, const char * buffer, size_t max, int flags) throw(int&);

    virtual ssize_t Read(int fd, char * buffer, size_t max, int flags) throw(int&)=0;
    virtual ssize_t Send(int fd, const char * buffer, size_t max, int flags) throw(int&)=0;
public:
    Inet(void) {};
    Inet(int type, int protocol, unsigned short int port);
    Inet(int type, int protocol, const char * hostname, unsigned short int port);
    ~Inet(void);

    virtual ssize_t Read(char * buffer, size_t max, int flags = 0) throw(int&);
    virtual ssize_t Send(const char * buffer, size_t max, int flags = 0) throw(int&);
};
#endif//INET_H

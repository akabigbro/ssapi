#include "inet.h"

Inet::Inet(int type, int protocol, unsigned short int port)
    : Address(PF_INET, type, protocol)
{
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = INADDR_ANY;
    Bind((sockaddr *) &address, sizeof(address));
}

Inet::Inet(int type, int protocol, const char * hostname, unsigned short int port)
    : Address(PF_INET, type, protocol)
{
    struct hostent * hostinfo = gethostbyname(hostname);
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr = *(struct in_addr *) hostinfo->h_addr;
    Bind((sockaddr *) &address, sizeof(address));
}

Inet::~Inet(void)
{
}

ssize_t Inet::ReadFrom(int fd, char * buffer, size_t max, int flags) throw(int&)
{
    return Address::ReadFrom(fd, buffer, max, flags);
}

ssize_t Inet::SendTo(int fd, const char * buffer, size_t max, int flags) throw(int&)
{
    return Address::SendTo(fd, buffer, max, flags);
}

ssize_t Inet::Read(char * buffer, size_t max, int flags) throw(int&)
{
    return Address::Read(buffer, max, flags);
}

ssize_t Inet::Send(const char * buffer, size_t max, int flags) throw(int&)
{
    return Address::Send(buffer, max, flags);
}


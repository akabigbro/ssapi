#include "udpsocket.h"

UdpSocket::UdpSocket(unsigned short int port)
    : Inet(SOCK_DGRAM, 0, port)
{
}

UdpSocket::UdpSocket(const char * hostname, unsigned short int port)
    : Inet(SOCK_DGRAM, 0, hostname, port)
{
}

UdpSocket::~UdpSocket(void)
{
}

ssize_t UdpSocket::Read(int fd, char * buffer, size_t max, int flags) throw(int&)
{
    return ReadFrom(fd, buffer, max, flags);
}

ssize_t UdpSocket::Send(int fd, const char * buffer, size_t max, int flags) throw(int&)
{
    return SendTo(fd, buffer, max, flags);
}

ssize_t UdpSocket::Read(char * buffer, size_t max, int flags) throw(int&)
{
    return Inet::Read(buffer, max, flags);
}

ssize_t UdpSocket::Send(const char * buffer, size_t max, int flags) throw(int&)
{
    return Inet::Send(buffer, max, flags);
}


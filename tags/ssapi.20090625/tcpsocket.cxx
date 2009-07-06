#include "tcpsocket.h"

TcpSocket::TcpSocket(unsigned short int port)
    : Inet(SOCK_STREAM, 0, port)
{
}

TcpSocket::TcpSocket(const char * hostname, unsigned short int port)
    : Inet(SOCK_STREAM, 0, hostname, port)
{
}

TcpSocket::~TcpSocket(void)
{
}

ssize_t TcpSocket::Read(int fd, char * buffer, size_t max, int flags) throw(int&)
{
    ssize_t length = recv(fd, buffer, max, flags);
    if (-1 == length)
    {
        throw errno;
    }
    return length;
}

ssize_t TcpSocket::Send(int fd, const char * buffer, size_t max, int flags) throw(int&)
{
    ssize_t length = send(fd, buffer, max, flags);
    if (-1 == length)
    {
        throw errno;
    }
    return length;
}

ssize_t TcpSocket::Read(char * buffer, size_t max, int flags) throw(int&)
{
    return Inet::Read(buffer, max, flags);
}

ssize_t TcpSocket::Send(const char * buffer, size_t max, int flags) throw(int&)
{
    return Inet::Send(buffer, max, flags);
}

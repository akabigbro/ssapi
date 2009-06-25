#include "filesocket.h"

FileSocket::FileSocket(const char * filename, int protocol)
    : Unix(SOCK_STREAM, protocol, filename)
{
}

FileSocket::~FileSocket(void)
{
}

ssize_t FileSocket::Read(int fd, char * buffer, size_t max, int flags) throw(int&)
{
    ssize_t length = recv(fd, buffer, max, flags);
    if (-1 == length)
    {
        throw errno;
    }
    return length;
}

ssize_t FileSocket::Send(int fd, const char * buffer, size_t max, int flags) throw(int&)
{
    ssize_t length = send(fd, buffer, max, flags);
    if (-1 == length)
    {
        throw errno;
    }
    return length;
}

ssize_t FileSocket::Read(char * buffer, size_t max, int flags) throw(int&)
{
    return Unix::Read(buffer, max, flags);
}

ssize_t FileSocket::Send(const char * buffer, size_t max, int flags) throw(int&)
{
    return Unix::Send(buffer, max, flags);
}


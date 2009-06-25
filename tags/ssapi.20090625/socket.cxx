#include "socket.h"

Socket::Socket(int domain, int type, int protocol)
{
    fd = socket(domain, type, protocol);
}

Socket::~Socket(void) throw(int&)
{
    close(fd);
}

void Socket::ShutDown(int how) throw(int&)
{
    if (0 != shutdown(fd, how))
    {
        throw errno;
    }
}

ssize_t Socket::Read(char * buffer, size_t max, int flags) throw(int&)
{
    return Read(fd, buffer, max, flags);
}

ssize_t Socket::Send(const char * buffer, size_t max, int flags) throw(int&)
{
    return Send(fd, buffer, max, flags);
}


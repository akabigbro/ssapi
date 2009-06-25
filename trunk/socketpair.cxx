#include "socketpair.h"


ssize_t SocketPair::Read(int fd, char * buffer, size_t max, int flags) throw(int&)
{
    ssize_t length = recv(fd, buffer, max, flags);

    if (-1 == length)
    {
        throw errno;
    }

    return length;
}

ssize_t SocketPair::Send(int fd, const char * buffer, size_t max, int flags) throw(int&)
{
    ssize_t length = send(fd, buffer, max, flags);

    if (-1 == length)
    {
        throw errno;
    }

    return length;
}

void SocketPair::Connect(SocketPair * socketPair) throw(int&)
{
    int fds[2];

    if (0 != socketpair(AF_UNIX, SOCK_STREAM, 0, fds))
    {
        throw errno;
    }
    else
    {
        fd = fds[0];
        socketPair->fd = fds[1];
    }
}

ssize_t SocketPair::Read(char * buffer, size_t max, int flags) throw(int&)
{
    return Socket::Read(buffer, max, flags);
}

ssize_t SocketPair::Send(const char * buffer, size_t max, int flags) throw(int&)
{
    return Socket::Send(buffer, max, flags);
}

#include "address.h"

void Address::Bind(sockaddr * address, size_t size)
{
    this->address = address;
    this->size = size;
    bind(fd, address, size);
}

Address::Address(int domain, int type, int protocol)
    : Socket(domain, type, protocol)
{
}

Address::~Address(void)
{
}

void Address::Connect(void) throw(int&)
{
    if (0 != connect(fd, address, size))
    {
        throw errno;
    }
}

void Address::Listen(int pending) throw(int&)
{
    if (0 != listen(fd, pending))
    {
        throw errno;
    }
}

void Address::Accept(Address * address) throw(int&)
{
    address->fd = accept(this->fd, this->address, (socklen_t *) &this->size);
    if (-1 == address->fd)
    {
        throw errno;
    }
}

ssize_t Address::ReadFrom(int fd, char * buffer, size_t max, int flags) throw(int&)
{
    ssize_t length = recvfrom(fd, buffer, max, flags, address, (socklen_t *) &size);
    if (-1 == length)
    {
        throw errno;
    }
    return length;
}

ssize_t Address::SendTo(int fd, const char * buffer, size_t max, int flags) throw(int&)
{
    ssize_t length = sendto(fd, buffer, max, flags, address, size);
    if (-1 == length)
    {
        throw errno;
    }
    return length;
}

ssize_t Address::Read(char * buffer, size_t max, int flags) throw(int&)
{
    return Socket::Read(buffer, max, flags);
}

ssize_t Address::Send(const char * buffer, size_t max, int flags) throw(int&)
{
    return Socket::Send(buffer, max, flags);
}

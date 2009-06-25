#include "unix.h"

Unix::Unix(int type, int protocol, const char * filename)
    : Address(AF_UNIX, type, protocol)
{
    address.sun_family = AF_UNIX;
    strcpy(address.sun_path, filename);
    Bind((sockaddr *) &address, sizeof(address));
}

Unix::~Unix(void)
{
}

ssize_t Unix::Read(char * buffer, size_t max, int flags) throw(int&)
{
    return Address::Read(buffer, max, flags);
}

ssize_t Unix::Send(const char * buffer, size_t max, int flags) throw(int&)
{
    return Address::Send(buffer, max, flags);
}


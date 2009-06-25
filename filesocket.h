#ifndef FILESOCKET_H
#define FILESOCKET_H

#include "unix.h"

class FileSocket : public Unix
{
protected:
    ssize_t Read(int fd, char * buffer, size_t max, int flags) throw(int&);
    ssize_t Send(int fd, const char * buffer, size_t max, int flags) throw(int&);
public:
    FileSocket(void) {};
    FileSocket(const char * filename, int protocol = 0);
    ~FileSocket(void);

    ssize_t Read(char * buffer, size_t max, int flags = 0) throw(int&);
    ssize_t Send(const char * buffer, size_t max, int flags = 0) throw(int&);
};

#endif//FILESOCKET_H

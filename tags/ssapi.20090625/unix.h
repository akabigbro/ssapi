#ifndef UNIX_H
#define UNIX_H

#include <sys/un.h>
#include "unistd.h"
#include "address.h"

class Unix : public Address
{
    protected:
        struct sockaddr_un address;

        virtual ssize_t Read(int fd, char * buffer, size_t max, int flags) throw(int&)=0;
        virtual ssize_t Send(int fd, const char * buffer, size_t max, int flags) throw(int&)=0;
    public:
        Unix(void) {};
        Unix(int type, int protocol, const char * filename);
        ~Unix(void);

        virtual ssize_t Read(char * buffer, size_t max, int flags = 0) throw(int&);
        virtual ssize_t Send(const char * buffer, size_t max, int flags = 0) throw(int&);
};

#endif//UNIX_H

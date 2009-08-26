#ifndef SOCKET_H
#define SOCKET_H

#include <cerrno>
#include <unistd.h>
#include <sys/socket.h>

class Socket
{
    protected:
        int fd;

        virtual ssize_t Read(int fd, char * buffer, size_t max, int flags) throw(int&)=0;
        virtual ssize_t Send(int fd, const char * buffer, size_t max, int flags) throw(int&)=0;
    public:
        Socket(void) {};
        Socket(int domain, int type, int protocol);
        ~Socket(void) throw(int&);

        void ShutDown(int how) throw(int&);

        virtual ssize_t Read(char * buffer, size_t max, int flags = 0) throw(int&);
        virtual ssize_t Send(const char * buffer, size_t max, int flags = 0) throw(int&);

        void SetOption(int level, int option, const void * value, socklen_t length) throw(int&);
};

#endif//SOCKET_H

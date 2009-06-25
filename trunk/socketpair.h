#ifndef SOCKETPAIR_H
#define SOCKETPAIR_H

#include "socket.h"

class SocketPair : public Socket
{
    private:
        ssize_t Read(int fd, char * buffer, size_t max, int flags) throw(int&);
        ssize_t Send(int fd, const char * buffer, size_t max, int flags) throw(int&);
    public:
        void Connect(SocketPair * socketPair) throw(int&);

        virtual ssize_t Read(char * buffer, size_t max, int flags = 0) throw(int&);
        virtual ssize_t Send(const char * buffer, size_t max, int flags = 0) throw(int&);
};

#endif//SOCKETPAIR_H

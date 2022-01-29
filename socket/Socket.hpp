#ifndef SOCKET

#define SOCKET

#include <arpa/inet.h> //structure for storing address information

class Socket{
protected:
    int sockD;
    int addressLength;
    struct sockaddr_in serverAddress;
    char buffer[1024];
public:
    Socket(uint16_t portNumber);
    virtual void sendString(const char*) const = 0;
    virtual void receiveString() = 0;
    virtual const char* getBuffer() const = 0;
    void endConnection();
};


#endif

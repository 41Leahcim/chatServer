#ifndef SOCKET

#define SOCKET

#include <iostream>
#include <arpa/inet.h> //structure for storing address information
#include <sys/socket.h> //for socket APIs
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

class Socket{
protected:
    int sockD;
    int addressLength;
    struct sockaddr_in serverAddress;
    char buffer[1024];
public:
    Socket(uint16_t portNumber) : addressLength(sizeof(serverAddress)){
        serverAddress.sin_family = AF_INET;
        serverAddress.sin_port = htons(portNumber); // use some unused port number
    }

    virtual void sendString(const char*) const = 0;
    virtual void receiveString() = 0;

    virtual const char* getBuffer() const = 0;

    void endConnection(){
        close(sockD);
    }
};


#endif

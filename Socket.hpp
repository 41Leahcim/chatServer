#ifndef SOCKET

#define SOCKET

#include <iostream>
#include <netinet/in.h> //structure for storing address information
#include <sys/socket.h> //for socket APIs
#include <sys/types.h>
#include <string.h>

class Socket{
protected:
    int sockD;
    struct sockaddr_in serverAddress;
    char buffer[1024];
public:
    Socket(uint16_t portNumber){
        serverAddress.sin_family = AF_INET;
        serverAddress.sin_port
            = htons(9001); // use some unused port number
        serverAddress.sin_addr.s_addr = INADDR_ANY;
    }

    virtual void sendString(const char*) const = 0;
    virtual void receiveString() = 0;

    virtual const char* getBuffer() const = 0;

    void endConnection(){
        shutdown(sockD, SHUT_RDWR);
    }
};


#endif

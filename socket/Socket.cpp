#include "Socket.hpp"
#include <unistd.h>

Socket::Socket(uint16_t portNumber) : addressLength(sizeof(serverAddress)){
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(portNumber); // use some unused port number
}

void Socket::endConnection(){
    close(sockD);
}

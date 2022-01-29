#include "Client.hpp"
#include <string.h>
#include <unistd.h>

Client::Client(uint16_t portNumber, const char *serverAdd) : Socket(portNumber), server(serverAdd){
    if(inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr) <= 0){
        printf("\nInvalid address/ Address not supported \n");
        exit(EXIT_FAILURE);
    }
}

void Client::startConnection(){
    if ((sockD = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        printf("\n Socket creation error \n");
        exit(EXIT_FAILURE);
    }
    if (connect(sockD, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0){
        printf("\nConnection Failed \n");
        exit(EXIT_FAILURE);
    }
}

void Client::sendString(const char *message) const{
    send(sockD, message, strlen(message), 0);
    usleep(1);
}

void Client::receiveString(){
    int32_t length = read(sockD, buffer, sizeof(buffer));
    if(length < 0){
        std::cerr << "ERROR: Failed to receive message!\n";
        exit(EXIT_FAILURE);
    }else if(length >= sizeof(buffer)){
        std::cerr << "ERROR: Message to long!\n";
        std::cerr << length << "\n";
        exit(EXIT_FAILURE);
    }
    buffer[length] = '\0';
    usleep(1);
}

const char* Client::getBuffer() const{
    return buffer;
}

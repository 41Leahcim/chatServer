#ifndef CLIENT

#define CLIENT

#include <iostream>
#include "Socket.hpp"

class Client : public Socket{
private:
public:
    Client(uint16_t portNumber) : Socket(portNumber){}

    void startConnection(){
        sockD = socket(AF_INET, SOCK_STREAM, 0);

        size_t status = connect(sockD, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
        if(status == -1){
            std::cerr << "ERROR: Failed to connect to server!\n";
            exit(EXIT_FAILURE);
        }
    }

    void sendString(const char *message) const{
        send(sockD, message, strlen(message), 0);
    }

    void receiveString(){
        int32_t length = recv(sockD, buffer, sizeof(buffer), 0);
        if(length < 0){
            std::cerr << "ERROR: Failed to receive message!\n";
            exit(EXIT_FAILURE);
        }else if(length > sizeof(buffer) - 1){
            std::cerr << "ERROR: Message to long!\n";
            std::cerr << length << "\n";
            exit(EXIT_FAILURE);
        }
        buffer[length] = '\0';
    }

    const char* getBuffer() const{
        return buffer;
    }
};

#endif

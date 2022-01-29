#include "Server.hpp"
#include <string.h>
#include <unistd.h>
#include <iostream>

Server::Server(uint16_t portNumber) : Socket(portNumber){
    serverAddress.sin_addr.s_addr = INADDR_ANY;	
    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        std::cerr << "ERROR: Failed to create server socket!";
        exit(EXIT_FAILURE);
    }
    if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                &opt, sizeof(opt))){
        std::cerr << "ERROR: Failed to initialize server socket!\n";
        exit(EXIT_FAILURE);
    }
    if (bind(serverSocket, (struct sockaddr *)&serverAddress,
                                sizeof(serverAddress)) < 0){
        std::cerr << "ERROR: Failed to bind server socket!\n";
        exit(EXIT_FAILURE);
    }
}

void Server::startConnection(){
    if (listen(serverSocket, 1) < 0){
        std::cerr << "ERROR: Failed to listen for client!\n";
        exit(EXIT_FAILURE);
    }
    if ((sockD = accept(serverSocket, (struct sockaddr *)&serverAddress,
                    (socklen_t*)&addressLength))<0){
        std::cerr << "ERROR: Failed to accept a client!\n";
        exit(EXIT_FAILURE);
    }
}

void Server::sendString(const char *message) const{
    int64_t length = send(sockD, message, strlen(message), 0);
    if(length < 0){
        std::cerr << "ERROR: Failed to send message!\n";
    }
}

void Server::receiveString(){
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
}

const char* Server::getBuffer() const{
    return buffer;
}

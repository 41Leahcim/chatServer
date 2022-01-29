#ifndef SERVER

#define SERVER

#include "Socket.hpp"

class Server : public Socket{
private:
    int clientSocket;
public:
    Server(uint16_t portNumber) : Socket(portNumber){
        sockD = socket(AF_INET, SOCK_STREAM, 0);
        // bind socket to the specified IP and port
        bind(sockD, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
    }

    void startConnection(){
        listen(sockD, 1);
        clientSocket = accept(sockD, NULL, NULL);
    }

    void sendString(const char *message) const{
        send(clientSocket, message, strlen(message), 0);
    }

    void receiveString(){
        int32_t length = recv(clientSocket, buffer, sizeof(buffer), 0);
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

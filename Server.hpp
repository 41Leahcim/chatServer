#ifndef SERVER

#define SERVER

#include "Socket.hpp"

class Server : public Socket{
private:
    int serverSocket;
    int opt;
public:
    Server(uint16_t portNumber) : Socket(portNumber){
        serverAddress.sin_addr.s_addr = INADDR_ANY;	
        if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == 0){
            perror("socket failed");
            exit(EXIT_FAILURE);
        }
        if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                    &opt, sizeof(opt))){
            perror("setsockopt");
            exit(EXIT_FAILURE);
        }
        if (bind(serverSocket, (struct sockaddr *)&serverAddress,
                                    sizeof(serverAddress)) < 0){
            perror("bind failed");
            exit(EXIT_FAILURE);
        }
    }

    void startConnection(){
        if (listen(serverSocket, 1) < 0){
            perror("listen");
            exit(EXIT_FAILURE);
        }
        if ((sockD = accept(serverSocket, (struct sockaddr *)&serverAddress,
                        (socklen_t*)&addressLength))<0){
            perror("accept");
            exit(EXIT_FAILURE);
        }
    }

    void sendString(const char *message) const{
        send(sockD, message, strlen(message), 0);
    }

    void receiveString(){
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

    const char* getBuffer() const{
        return buffer;
    }
};

#endif

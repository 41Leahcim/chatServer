#ifndef SERVER

#define SERVER

#include "../socket/Socket.hpp"

class Server : public Socket{
private:
    int serverSocket;
    int opt;
public:
    Server(uint16_t portNumber);
    void startConnection();
    void sendString(const char *message) const;
    void receiveString();
    const char* getBuffer() const;
};

#endif

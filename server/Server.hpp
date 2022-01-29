#ifndef SERVER

#define SERVER

#include "../socket/Socket.hpp"
#include "../messageManager/MessageManager.hpp"

class Server : public Socket{
private:
    int serverSocket;
    int opt;
    MessageManager manager;
public:
    Server(uint16_t portNumber);
    void startConnection();
    void sendString(const char *message) const;
    void receiveString();
    const char* getBuffer() const;
    void storeMessage();
    std::string getMessage(uint32_t) const;
    void removeMessage(uint32_t);
    uint32_t getNumberOfMessages() const;
};

#endif

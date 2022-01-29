#ifndef CLIENT

#define CLIENT

#include <iostream>
#include "../socket/Socket.hpp"

class Client : public Socket{
private:
    const char *server;
public:
    Client(uint16_t portNumber, const char *serverAdd);
    void startConnection();
    void sendString(const char *message) const;
    void receiveString();
    const char* getBuffer() const;
};

#endif

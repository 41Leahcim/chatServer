#ifndef MESSAGE_MANAGER
#define MESSAGE_MANAGER

#include <string>
#include <vector>

class MessageManager{
private:
    std::vector<std::string> messages;
public:
    MessageManager();
    void addMessage(std::string);
    void removeMessage(uint32_t);
    std::string getMessage(uint32_t) const;
    uint32_t getNumberOfMessages() const;
};

#endif

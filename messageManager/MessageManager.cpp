#include "MessageManager.hpp"
#include <iostream>

MessageManager::MessageManager(){}

void MessageManager::addMessage(std::string message){
    messages.push_back(message);
}

void MessageManager::removeMessage(uint32_t index){
    if(index < messages.size()){
        messages.erase(messages.begin() + index);
    }
}

std::string MessageManager::getMessage(uint32_t index) const{
    return messages[index];
}

uint32_t MessageManager::getNumberOfMessages() const{
    return messages.size();
}

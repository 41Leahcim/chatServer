#include <unistd.h>
#include <iostream>

#include "Server.hpp"

void sendMessages(Server& server){
	std::string message;
	for(uint64_t i = 0;i < server.getNumberOfMessages();i++){
		server.sendString(server.getMessage(i).c_str());
		std::cout << server.getMessage(i) << "\n";
	} 
	server.sendString("END");
}

int main(int argc, char const* argv[]){
	Server server(9001);
    while(1){
		server.startConnection();
		server.receiveString();
		server.storeMessage();
		sendMessages(server);
		server.endConnection();
    }
	return 0;
}

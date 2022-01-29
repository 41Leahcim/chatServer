#include "Server.hpp"

int main(int argc, char const* argv[]){
	Server server(9001);
    while(1){
		server.startConnection();
		server.receiveString();
		server.sendString(server.getBuffer());
    }
	return 0;
}

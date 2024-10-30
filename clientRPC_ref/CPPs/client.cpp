#include "interfaceRPC_h.h"
#include <Windows.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <Rpcdce.h> 
#include <Rpc.h>
#include <vector>
#include <map>
#include "globals.h"
#include "ICommand.h"
#include "CommandProcessor.h"
#include "ExitCommand.h"
#include "MenuCommand.h"
#include "DeleteCommand.h"
#include "DownloadCommand.h"
#include "UploadCommand.h"
#include "RPCCLient.h"
#pragma comment(lib, "rpcrt4.lib")


void* __RPC_USER midl_user_allocate(size_t size) {
	return malloc(size);
}
void __RPC_USER midl_user_free(void* p) {
	free(p);
}


int main() {

	RpcClient client;

	std::string ip;
	std::cout << "Enter IP: ";
	std::cin >> ip;
	if (!client.connect(ip)) {
		return 1;
	}
	if (!client.authenticate()) {
		return 1;
	}
	std::cout << hand;
	CommandProcessor processor;
	processor.addCommand(1, std::make_shared<UploadCommand>());
	processor.addCommand(2, std::make_shared<DownloadCommand>());
	processor.addCommand(3, std::make_shared<DeleteCommand>());
	processor.addCommand(4, std::make_shared<MenuCommand>());
	processor.addCommand(5, std::make_shared<ExitCommand>());

	int choice = 4;
	while (true) {
		processor.executeCommand(choice);
		std::cout << "Enter command number: ";
		std::cin >> choice;
		std::cout << std::endl;
	}

	return 0;
}

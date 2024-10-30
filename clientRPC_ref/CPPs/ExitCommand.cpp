#include "ExitCommand.h"

void ExitCommand::execute() {
	rpc_close(hand);
	RpcBindingFree(&hand);
	std::cout << "Exiting..." << std::endl;
	exit(0);
}
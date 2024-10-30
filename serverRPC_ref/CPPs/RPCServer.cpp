#include "RPCServer.h"
#include <iostream>


void RPCServer::run()
{
    bindingManager->startBindings();
    std::cout << "Server is listening..." << std::endl;
    RpcServerListen(1, RPC_C_LISTEN_MAX_CALLS_DEFAULT, 0);
}

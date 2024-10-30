#ifndef RPC_SERVER_H
#define RPC_SERVER_H

#include "FileTransferService.h"
#include "RPCBindingManager.h"

class RPCServer {
public:
    RPCServer(RPCBindingManager* bindingManager, IFileTransferService* fileService)
        : bindingManager(bindingManager), fileService(fileService) {}

    void run();

private:
    RPCBindingManager* bindingManager;
    IFileTransferService* fileService;
};


#endif // RPC_SERVER_H

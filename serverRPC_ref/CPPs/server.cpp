#include "interfaceRPC_h.h"
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <rpc.h>
#include <rpcdce.h>
#pragma comment(lib, "rpcrt4.lib")

#include "FileManager.h"
#include "AuthManager.h"
#include "FileTransferService.h"
#include "RPCBindingManager.h"
#include "RPCServer.h"
#include "RPCFuncs.h"

void __RPC_FAR* __RPC_USER midl_user_allocate(size_t len) {
    return (malloc(len));
}
void __RPC_USER midl_user_free(void __RPC_FAR* ptr) {
    free(ptr);
}


int main(int argc, char** argv) {
    
    try {
        IAuthManager* authManager = new AuthManager();
        IFileManager* fileManager = new FileManager();

        IFileTransferService* fileService = new FileTransferService(authManager, fileManager);
        g_fileService = fileService;

        RPCBindingManager bindingManager;
        RPCServer server(&bindingManager, fileService);
        server.run();

        delete fileService;
        delete authManager;
        delete fileManager;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}

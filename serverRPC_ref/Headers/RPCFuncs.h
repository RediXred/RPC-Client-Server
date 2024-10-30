#ifndef RPCFUNCTIONS_H
#define RPCFUNCTIONS_H

#include "IFileTransferService.h"  
#include "IAuthManager.h"
#include <Windows.h>   

extern IFileTransferService* g_fileService;
extern IAuthManager* g_authManager;

extern "C" {
    int _check(handle_t handle, unsigned char* login, unsigned char* pass);
    int _upload(handle_t handle, const unsigned char* filePath, const unsigned char* data, unsigned int size);
    int _download(handle_t handle, const unsigned char* filePath, unsigned char* data, unsigned int size);
    int _delete(handle_t handle, const unsigned char* filePath);
    unsigned int _size(handle_t handle, const unsigned char* filePath);
    void rpc_close(handle_t handle);
}

#endif // RPCFUNCTIONS_H

#include "RPCFuncs.h"
#include "IFileTransferService.h"
#include "IAuthManager.h"

IFileTransferService* g_fileService = nullptr;
IAuthManager* g_authManager = nullptr;

extern "C" {
    int _check(handle_t handle, unsigned char* login, unsigned char* pass) {
        return g_fileService->checkCredentials(handle, login, pass);
    }

    int _upload(handle_t handle, const unsigned char* filePath, const unsigned char* data, unsigned int size) {
        return g_fileService->uploadFile(handle, filePath, data, size);
    }

    int _download(handle_t handle, const unsigned char* filePath, unsigned char* data, unsigned int size) {
        return g_fileService->downloadFile(handle, filePath, data, size);
    }

    int _delete(handle_t handle, const unsigned char* filePath) {
        return g_fileService->deleteFile(handle, filePath);
    }

    unsigned int _size(handle_t handle, const unsigned char* filePath) {
        return g_fileService->getFileSize(handle, filePath);
    }

    void rpc_close(handle_t handle) {
        g_authManager->closeSession(handle);
    }
}
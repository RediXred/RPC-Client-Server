#ifndef FILETRANSFERSERVICE_H
#define FILETRANSFERSERVICE_H

#include "IFileTransferService.h"
#include "IAuthManager.h"
#include "IFileManager.h"

class FileTransferService : public IFileTransferService {
public:
    FileTransferService(IAuthManager* authManager, IFileManager* fileManager);

    int checkCredentials(handle_t handle, const unsigned char* login, const unsigned char* pass) override;
    int uploadFile(handle_t handle, const unsigned char* filePath, const unsigned char* data, unsigned int size) override;
    int downloadFile(handle_t handle, const unsigned char* filePath, unsigned char* data, unsigned int size) override;
    int deleteFile(handle_t handle, const unsigned char* filePath) override;
    unsigned int getFileSize(handle_t handle, const unsigned char* filePath) override;

    int readFile(handle_t handle, const unsigned char* filePath, unsigned char* buffer, unsigned int size, unsigned int offset) override;
    int writeFile(handle_t handle, const unsigned char* filePath, const unsigned char* buffer, unsigned int size, unsigned int offset) override;

private:
    IAuthManager* authManager;
    IFileManager* fileManager;
};

#endif // FILETRANSFERSERVICE_H

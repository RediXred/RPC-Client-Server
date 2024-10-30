#pragma once
#ifndef IFILETRANSFERSERVICE_H
#define IFILETRANSFERSERVICE_H

#include <Windows.h>

class IFileTransferService {
public:
    virtual ~IFileTransferService() = default;

    virtual int checkCredentials(handle_t handle, const unsigned char* login, const unsigned char* pass) = 0;
    virtual int uploadFile(handle_t handle, const unsigned char* filePath, const unsigned char* data, unsigned int size) = 0;
    virtual int downloadFile(handle_t handle, const unsigned char* filePath, unsigned char* data, unsigned int size) = 0;
    virtual int deleteFile(handle_t handle, const unsigned char* filePath) = 0;
    virtual unsigned int getFileSize(handle_t handle, const unsigned char* filePath) = 0;

    virtual int readFile(handle_t handle, const unsigned char* filePath, unsigned char* buffer, unsigned int size, unsigned int offset) = 0;
    virtual int writeFile(handle_t handle, const unsigned char* filePath, const unsigned char* buffer, unsigned int size, unsigned int offset) = 0;
};

#endif // IFILETRANSFERSERVICE_H

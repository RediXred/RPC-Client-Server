#pragma once
#include <gmock/gmock.h>
#include "IFileTransferService.h"

class MockFileTransferService : public IFileTransferService {
public:
    MOCK_METHOD(int, checkCredentials, (handle_t handle, const unsigned char* login, const unsigned char* pass), (override));
    MOCK_METHOD(int, uploadFile, (handle_t handle, const unsigned char* filePath, const unsigned char* data, unsigned int size), (override));
    MOCK_METHOD(int, downloadFile, (handle_t handle, const unsigned char* filePath, unsigned char* data, unsigned int size), (override));
    MOCK_METHOD(int, deleteFile, (handle_t handle, const unsigned char* filePath), (override));
    MOCK_METHOD(unsigned int, getFileSize, (handle_t handle, const unsigned char* filePath), (override));

    MOCK_METHOD(int, readFile, (handle_t handle, const unsigned char* filePath, unsigned char* buffer, unsigned int size, unsigned int offset), (override));
    MOCK_METHOD(int, writeFile, (handle_t handle, const unsigned char* filePath, const unsigned char* buffer, unsigned int size, unsigned int offset), (override));
};
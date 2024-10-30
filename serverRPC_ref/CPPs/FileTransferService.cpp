#include "FileTransferService.h"

FileTransferService::FileTransferService(IAuthManager* authManager, IFileManager* fileManager)
    : authManager(authManager), fileManager(fileManager) {}

int FileTransferService::checkCredentials(handle_t handle, const unsigned char* login, const unsigned char* pass) {
    return authManager->checkCredentials(handle, login, pass);
}

int FileTransferService::uploadFile(handle_t handle, const unsigned char* filePath, const unsigned char* data, unsigned int size) {
    return fileManager->uploadFile(filePath, data, size);
}

int FileTransferService::downloadFile(handle_t handle, const unsigned char* filePath, unsigned char* data, unsigned int size) {
    return fileManager->downloadFile(filePath, data, size);
}

int FileTransferService::deleteFile(handle_t handle, const unsigned char* filePath) {
    return fileManager->deleteFile(filePath);
}

unsigned int FileTransferService::getFileSize(handle_t handle, const unsigned char* filePath) {
    return fileManager->getFileSize(filePath);
}

int FileTransferService::readFile(handle_t handle, const unsigned char* filePath, unsigned char* buffer, unsigned int size, unsigned int offset) {
    return fileManager->readFile(filePath, buffer, size, offset);
}

int FileTransferService::writeFile(handle_t handle, const unsigned char* filePath, const unsigned char* buffer, unsigned int size, unsigned int offset) {
    return fileManager->writeFile(filePath, buffer, size, offset);
}

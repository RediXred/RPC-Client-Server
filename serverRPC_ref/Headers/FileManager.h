#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "IFileManager.h"

class FileManager : public IFileManager {
public:
    int uploadFile(const unsigned char* filePath, const unsigned char* data, unsigned int size) override;
    int downloadFile(const unsigned char* filePath, unsigned char* data, unsigned int size) override;
    int deleteFile(const unsigned char* filePath) override;
    unsigned int getFileSize(const unsigned char* filePath) override;

    int readFile(const unsigned char* filePath, unsigned char* buffer, unsigned int size, unsigned int offset) override;
    int writeFile(const unsigned char* filePath, const unsigned char* buffer, unsigned int size, unsigned int offset) override;
};

#endif // FILEMANAGER_H

#ifndef IFILEMANAGER_H
#define IFILEMANAGER_H

class IFileManager {
public:
    virtual ~IFileManager() = default;

    virtual int uploadFile(const unsigned char* filePath, const unsigned char* data, unsigned int size) = 0;
    virtual int downloadFile(const unsigned char* filePath, unsigned char* data, unsigned int size) = 0;
    virtual int deleteFile(const unsigned char* filePath) = 0;
    virtual unsigned int getFileSize(const unsigned char* filePath) = 0;

    virtual int readFile(const unsigned char* filePath, unsigned char* buffer, unsigned int size, unsigned int offset) = 0;
    virtual int writeFile(const unsigned char* filePath, const unsigned char* buffer, unsigned int size, unsigned int offset) = 0;
};

#endif // IFILEMANAGER_H

#include "FileManager.h"
#include <fstream>
#include <iostream>

int FileManager::uploadFile(const unsigned char* filePath, const unsigned char* data, unsigned int size) {
    std::ofstream f{ (const char*)filePath, std::ios::binary };
    if (f.is_open()) {
        f.write((const char*)data, size);
        f.close();
        return 0;
    }
    return 1;
}

int FileManager::downloadFile(const unsigned char* filePath, unsigned char* data, unsigned int size) {
    std::ifstream f{ (const char*)filePath, std::ios::binary };
    if (f.is_open()) {
        f.read((char*)data, size);
        f.close();
        return 0;
    }
    return 1;
}

int FileManager::deleteFile(const unsigned char* filePath) {
    return std::remove((const char*)filePath) == 0 ? 0 : 1;
}

unsigned int FileManager::getFileSize(const unsigned char* filePath) {
    std::ifstream f{ (const char*)filePath, std::ios::binary | std::ios::ate };

    if (f.is_open()) {
        std::streampos fileSize = f.tellg();
        f.close();

        if (fileSize >= 0) {
            return static_cast<unsigned int>(fileSize);
        }
    }

    return 0;
}


int FileManager::readFile(const unsigned char* filePath, unsigned char* buffer, unsigned int size, unsigned int offset) {
    std::ifstream f{ (const char*)filePath, std::ios::binary };
    if (f.is_open()) {
        f.seekg(offset);
        f.read((char*)buffer, size);
        f.close();
        return 0;
    }
    return 1;
}

int FileManager::writeFile(const unsigned char* filePath, const unsigned char* buffer, unsigned int size, unsigned int offset) {
    std::ofstream f{ (const char*)filePath, std::ios::binary | std::ios::in | std::ios::out };
    if (f.is_open()) {
        f.seekp(offset);
        f.write((const char*)buffer, size);
        f.close();
        return 0;
    }
    return 1;
}

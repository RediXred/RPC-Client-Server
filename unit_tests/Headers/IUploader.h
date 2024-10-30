#pragma once
// IUploader.h
#include <string>
#include <vector>

class IUploader {
public:
    virtual ~IUploader() = default;
    virtual int _upload(const std::string& remoteFilePath, const std::vector<unsigned char>& data) = 0;
};

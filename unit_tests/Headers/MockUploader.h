#pragma once
#include "IUploader.h"
#include <gmock/gmock.h>

class MockUploader : public IUploader {
public:
    MOCK_METHOD(int, _upload, (const std::string& remoteFilePath, const std::vector<unsigned char>& data), (override));
};
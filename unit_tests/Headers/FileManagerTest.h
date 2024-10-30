#pragma once
#include <gtest/gtest.h>
#include "FileManager.h"

class FileManagerTest : public ::testing::Test {
protected:
    FileManager fileManager;
    const char* testFilePath = "testfile.txt";
    const char* testData = "Hello, World!";
    unsigned int testDataSize = 13;

    void SetUp() override {
        fileManager.uploadFile(reinterpret_cast<const unsigned char*>(testFilePath),
            reinterpret_cast<const unsigned char*>(testData),
            testDataSize);
    }

    void TearDown() override {
        fileManager.deleteFile(reinterpret_cast<const unsigned char*>(testFilePath));
    }
};
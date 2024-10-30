#include "pch.h"

#include "uploadcommand/UploadCommand.h"
#include "uploadcommand/IUploader.h"

#include "processorcommand/CommandProcessor.h"

#include "RPCServerClass/RPCServer.h"
#include "RPCServerClass/RPCBindingManager.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

#include "uploadcommand/MockUploader.h"

TEST(UploadCommandTest, ExecuteUpload_Success) {
    MockUploader mockUploader;

    UploadCommand command(&mockUploader);

    std::string localFilePath = "test_upload.txt";
    std::ofstream out(localFilePath);
    out << "Test file content";
    out.close();

    std::streambuf* originalCout = std::cout.rdbuf();
    std::ostringstream capturedOutput;
    std::cout.rdbuf(capturedOutput.rdbuf());

    EXPECT_CALL(mockUploader, _upload(testing::_, testing::_))
        .WillOnce(testing::Return(0));

    std::istringstream simulatedInput(localFilePath + "\nuploaded.txt\n");
    std::cin.rdbuf(simulatedInput.rdbuf());

    command.execute();

    std::string output = capturedOutput.str();
    EXPECT_NE(output.find("File uploaded."), std::string::npos);

    std::cout.rdbuf(originalCout);

    std::remove(localFilePath.c_str());
}



#include "processorcommand/MockCommander.h"
TEST(CommandProcessorTest, ExecuteCommand_Success) {
    CommandProcessor processor;

    auto mockCommand = std::make_shared<MockCommand>();

    EXPECT_CALL(*mockCommand, execute()).Times(1);

    processor.addCommand(1, mockCommand);

    processor.executeCommand(1);
}

TEST(CommandProcessorTest, ExecuteCommand_WrongCommand) {
    CommandProcessor processor;

    std::stringstream outputBuffer;
    std::streambuf* originalCout = std::cout.rdbuf();
    std::cout.rdbuf(outputBuffer.rdbuf());

    processor.executeCommand(999);

    std::cout.rdbuf(originalCout);

    EXPECT_EQ(outputBuffer.str(), "Wrong command.\n");
}

#include "RPCServerClass/MockRPCBindingManager.h"
#include "RPCServerClass/MockFileTransferService.h"
TEST(RPCServerTest, Run_StartBindingsCalled) {
    MockRPCBindingManager mockBindingManager;
    MockFileTransferService mockFileService;

    //startBindings будет вызван один раз
    EXPECT_CALL(mockBindingManager, startBindings()).Times(1);

    RPCServer server(&mockBindingManager, &mockFileService);

    //stdout для проверки вывода
    std::stringstream outputBuffer;
    std::streambuf* originalCout = std::cout.rdbuf();
    std::cout.rdbuf(outputBuffer.rdbuf());

    server.run();

    std::cout.rdbuf(originalCout);

    std::string output = outputBuffer.str();
    EXPECT_NE(output.find("Server is listening..."), std::string::npos);
}

#include "FileManager/FileManager.h"
#include "FileManager/FileManagerTest.h"

TEST_F(FileManagerTest, UploadFile_Success) {
    //file was created successfully
    unsigned int fileSize = fileManager.getFileSize(reinterpret_cast<const unsigned char*>(testFilePath));
    EXPECT_EQ(fileSize, testDataSize);
}

TEST_F(FileManagerTest, DownloadFile_Success) {
    unsigned char buffer[50]; //store downloaded data
    int result = fileManager.downloadFile(reinterpret_cast<const unsigned char*>(testFilePath),
        buffer,
        testDataSize);

    EXPECT_EQ(result, 0); //successful download (0)
    EXPECT_STREQ(reinterpret_cast<const char*>(buffer), testData); //if the downloaded data matches
}

TEST_F(FileManagerTest, DeleteFile_Success) {
    //ensure the file exists
    EXPECT_EQ(fileManager.getFileSize(reinterpret_cast<const unsigned char*>(testFilePath)), testDataSize);

    //delete the file
    EXPECT_EQ(fileManager.deleteFile(reinterpret_cast<const unsigned char*>(testFilePath)), 0); //expect success (0)

    //file has been deleted
    EXPECT_EQ(fileManager.getFileSize(reinterpret_cast<const unsigned char*>(testFilePath)), 0);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
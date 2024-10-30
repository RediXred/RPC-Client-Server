#include "UploadCommand.h"

void UploadCommand::execute() {
	{
		std::string localFilePath, remoteFilePath;
		std::cout << "The path to the file to upload: ";
		std::cin >> localFilePath;
		std::cout << std::endl;
		std::vector<char> buffer;
		if (!readFile(localFilePath, buffer)) {
			return;
		}

		std::cout << "The path to uploaded file on server: ";
		std::cin >> remoteFilePath;

		if (_upload(hand, (const unsigned char*)remoteFilePath.c_str(), (const unsigned char*)buffer.data(), buffer.size())) {
			std::cout << "Access denied." << std::endl;
			return;
		}
		std::cout << "File uploaded." << std::endl;
	}
}

bool UploadCommand::readFile(const std::string& filePath, std::vector<char>& buffer) {
	std::ifstream f{ filePath, std::ios::binary | std::ios::ate };
	if (!f.is_open()) {
		std::cout << "Error: can't open the file." << std::endl;
		return false;
	}

	size_t fileSize = f.tellg();
	buffer.resize(fileSize);
	f.seekg(0, std::ios::beg);
	f.read(buffer.data(), fileSize);
	f.close();

	return true;
}
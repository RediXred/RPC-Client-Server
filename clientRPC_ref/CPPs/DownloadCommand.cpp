#include "DownloadCommand.h"


void DownloadCommand::execute() {
	std::string remoteFilePath, localFilePath;
	std::cout << "The path to the file to download: ";
	std::cin >> remoteFilePath;
	std::cout << std::endl;
	unsigned int fileSize = _size(hand, (unsigned char*)remoteFilePath.c_str());
	if (fileSize == 0) {
		std::cout << "Access denied." << std::endl;
		return;
	}

	std::vector<char> buffer(fileSize);
	if (_download(hand, (unsigned char*)remoteFilePath.c_str(), (unsigned char*)buffer.data(), fileSize)) {
		std::cout << "Access denied." << std::endl;
		return;
	}

	std::cout << "The path to save the downloaded file: ";
	std::cin >> localFilePath;
	std::cout << std::endl;
	if (!writeFile(localFilePath, buffer)) {
		std::cout << "Failed to save the file." << std::endl;
		return;
	}

	std::cout << "File downloaded." << std::endl;
}

bool DownloadCommand::writeFile(const std::string& filePath, const std::vector<char>& buffer) {
	std::ofstream f{ filePath, std::ios::binary };
	if (!f.is_open()) {
		std::cout << "Error: can't open the file for writing." << std::endl;
		return false;
	}

	f.write(buffer.data(), buffer.size());
	f.close();

	return true;
}
#include "DeleteCommand.h"


void DeleteCommand::execute() {
	{
		std::string remoteFilePath;
		std::cout << "Path: ";
		std::cin >> remoteFilePath;
		std::cout << std::endl;
		if (_delete(hand, (const unsigned char*)remoteFilePath.c_str())) {
			std::cout << "Error: can't delete." << std::endl;
		}
		else {
			std::cout << "File deleted." << std::endl;
		}
	}
}
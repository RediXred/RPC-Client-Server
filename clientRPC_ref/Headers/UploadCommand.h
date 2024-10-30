#pragma once
#include "globals.h"
#include "ICommand.h"
#include "interfaceRPC_h.h"
#include <iostream>
#include <vector>
#include <fstream>


class UploadCommand : public ICommand {
public:
	void execute() override;

private:
	bool readFile(const std::string& filePath, std::vector<char>& buffer);
};
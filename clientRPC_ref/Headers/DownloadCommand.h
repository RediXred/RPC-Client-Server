#pragma once
#include "globals.h"
#include "ICommand.h"
#include "interfaceRPC_h.h"
#include <iostream>
#include <vector>
#include <fstream>


class DownloadCommand : public ICommand {
public:
	void execute() override;

private:
	bool writeFile(const std::string& filePath, const std::vector<char>& buffer);
};
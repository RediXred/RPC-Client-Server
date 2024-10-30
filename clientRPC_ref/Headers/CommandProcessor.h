#pragma once
#include <iostream>
#include <map>
#include "ICommand.h"

class CommandProcessor {
private:
	std::map<int, std::shared_ptr<ICommand>> commands;
public:
	CommandProcessor() {}
	~CommandProcessor() {}
	void addCommand(int key, std::shared_ptr<ICommand> command);
	void executeCommand(int key);
};
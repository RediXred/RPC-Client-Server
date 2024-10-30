#include <iostream>
#include <map>
#include "ICommand.h"
#include "CommandProcessor.h"


void CommandProcessor::addCommand(int key, std::shared_ptr<ICommand> command)
{
	commands[key] = command;
}

void CommandProcessor::executeCommand(int key)
{
	if (commands.find(key) != commands.end()) {
		commands[key]->execute();
	}
	else {
		std::cout << "Wrong command." << std::endl;
	}
}

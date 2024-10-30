#pragma once
#include "ICommand.h"
#include "interfaceRPC_h.h"
#include "iostream"
#include "globals.h"

class ExitCommand : public ICommand {
public:
	void execute() override;
};
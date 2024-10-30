#pragma once
#include "globals.h"
#include "ICommand.h"
#include "interfaceRPC_h.h"
#include <iostream>


class DeleteCommand : public ICommand {
public:
	void execute() override;
};
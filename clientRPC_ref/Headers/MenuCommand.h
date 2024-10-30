#pragma once
#include "globals.h"
#include "ICommand.h"
#include <iostream>


class MenuCommand : public ICommand {
public:
	void execute() override;
};
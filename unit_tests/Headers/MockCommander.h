#pragma once
#include "../../../../serov_g_lab_2_oldproject/ref_rpc/module_testing/uploadcommand/ICommand.h"
#include <gmock/gmock.h>

class MockCommand : public ICommand {
public:
    MOCK_METHOD(void, execute, (), (override));
};
#pragma once

#include "RPCBindingManager.h"
#include <gmock/gmock.h>

class MockRPCBindingManager : public RPCBindingManager {
public:
    MOCK_METHOD(void, startBindings, (), (override));
};
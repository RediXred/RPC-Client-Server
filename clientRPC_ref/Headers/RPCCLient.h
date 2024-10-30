#pragma once
#include "globals.h"
#include "interfaceRPC_h.h"
#include <iostream>
#include <string>

class RpcClient {
public:
    RpcClient() {}
    ~RpcClient() {
        if (hand) {
            RpcBindingFree(&hand);
        }
    }

    bool connect(const std::string& ip);
    bool authenticate();
};

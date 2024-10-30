#include "RPCCLient.h"

bool RpcClient::connect(const std::string& ip) {
    RPC_STATUS status;
    unsigned char* StringBinding = NULL;

    // Создание строкового привязочного дескриптора
    status = RpcStringBindingComposeA(
        NULL,
        (RPC_CSTR)("ncacn_ip_tcp"),
        (RPC_CSTR)(ip.c_str()),
        (RPC_CSTR)("9000"),
        NULL,
        &StringBinding
    );

    if (status) {
        std::cerr << "Error: failed to create a string binding descriptor" << std::endl;
        return false;
    }

    // Создание привязки на основе строкового дескриптора
    status = RpcBindingFromStringBindingA(StringBinding, &hand);
    RpcStringFreeA(&StringBinding); 

    if (status) {
        std::cerr << "Error: failed to bind to the server" << std::endl;
        return false;
    }
    return true;
}

bool RpcClient::authenticate() {
    std::string username, pass;
    int authStatus = 1;  // 1 - неудачная аутентификация, 0 - успешная

    while (authStatus) {
        std::cout << "Login: ";
        std::cin >> username;
        std::cout << "Password: ";
        std::cin >> pass;
        std::cout << "Checking...." << std::endl;

        authStatus = _check(hand, (unsigned char*)username.c_str(), (unsigned char*)pass.c_str());
        if (authStatus) {
            std::cerr << "Invalid Input" << std::endl;
        }
    }
    std::cout << "Access allowed" << std::endl;
    return true;
}

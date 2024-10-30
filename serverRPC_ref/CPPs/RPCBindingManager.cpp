#include "RPCBindingManager.h"
#include "interfaceRPC_h.h"


void RPCBindingManager::startBindings()
{
    RPC_STATUS status = RpcServerUseProtseqEpA((RPC_CSTR)"ncacn_ip_tcp", RPC_C_PROTSEQ_MAX_REQS_DEFAULT, (RPC_CSTR)"9000", NULL);
    if (status != RPC_S_OK) throw std::runtime_error("RPC server binding error");
    status = RpcServerRegisterIf2(InterfaceRPC_v1_0_s_ifspec, NULL, NULL, RPC_IF_ALLOW_CALLBACKS_WITH_NO_AUTH, RPC_C_LISTEN_MAX_CALLS_DEFAULT, -1, NULL);
    if (status != RPC_S_OK) throw std::runtime_error("RPC interface registration error");
}

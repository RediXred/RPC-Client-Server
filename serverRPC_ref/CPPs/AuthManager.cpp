#include "AuthManager.h"
#include <Windows.h>
#include <iostream>

int AuthManager::checkCredentials(handle_t handle, const unsigned char* login, const unsigned char* pass) {
    int status = LogonUserA((LPCSTR)login, NULL, (LPCSTR)pass, LOGON32_LOGON_INTERACTIVE, LOGON32_PROVIDER_DEFAULT, &sessionHandle);
    if (status) {
        ImpersonateLoggedOnUser(sessionHandle);
        return 0;
    }
    else {
        return 1;
    }
}

void AuthManager::closeSession(handle_t handle) {
    RevertToSelf();
    CloseHandle(sessionHandle);
}

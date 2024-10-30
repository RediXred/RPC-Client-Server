#ifndef AUTHMANAGER_H
#define AUTHMANAGER_H

#include "IAuthManager.h"

class AuthManager : public IAuthManager {
public:
    int checkCredentials(handle_t handle, const unsigned char* login, const unsigned char* pass) override;
    void closeSession(handle_t handle) override;

private:
    HANDLE sessionHandle = 0;
};

#endif // AUTHMANAGER_H

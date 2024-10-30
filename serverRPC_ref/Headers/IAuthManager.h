#ifndef IAUTHMANAGER_H
#define IAUTHMANAGER_H

#include <Windows.h>

class IAuthManager {
public:
    virtual ~IAuthManager() = default;

    virtual int checkCredentials(handle_t handle, const unsigned char* login, const unsigned char* pass) = 0;
    virtual void closeSession(handle_t handle) = 0;
};

#endif // IAUTHMANAGER_H

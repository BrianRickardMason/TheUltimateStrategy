
#include "Credentials.h"

Credentials::Credentials(const std::string &aUsername, const std::string &aPassword)
    :   Username(aUsername), Password(aPassword) {}

Credentials::Credentials(const char* aUsername, const char* aPassword)
    :   Username(aUsername), Password(aPassword) {}

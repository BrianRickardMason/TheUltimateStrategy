
#ifndef _CREDENTIALS_H_
#define _CREDENTIALS_H_

#include <string>
#include <Poco/SharedPtr.h>

class Credentials{
public:
    Credentials(const std::string &aUsername, const std::string& aPassword)
    :   Username(aUsername), Password(aPassword) {}
    
    const std::string Username;
    const std::string Password;
    
    typedef Poco::SharedPtr<Credentials> Handle;
};

#endif

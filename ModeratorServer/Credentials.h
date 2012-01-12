
#ifndef _CREDENTIALS_H_
#define _CREDENTIALS_H_

#include <string>
#include <Poco/SharedPtr.h>

class Credentials {
public:
    explicit Credentials(const std::string& aUsername, const std::string& aPassword);
    explicit Credentials(const char* const aUsername, const char* const aPassword);

	~Credentials();

    const std::string Username;
    const std::string Password;
    
    typedef Poco::SharedPtr<Credentials> Handle;

	Credentials(const Credentials& orig): Username(orig.Username), Password(orig.Password){}
private:
	Credentials(){}
};

#endif

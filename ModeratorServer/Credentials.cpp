
#include "Credentials.h"

#include <iostream>

Credentials::Credentials(const std::string & aUsername, const std::string & aPassword)
    :   Username(aUsername), Password(aPassword) {
	std::clog << "meh..." << std::endl;	
}

Credentials::Credentials(const char* aUsername, const char* aPassword)
    :   Username(aUsername), Password(aPassword) {}

Credentials::~Credentials(){
	std::clog << "duh..." << std::endl;
}


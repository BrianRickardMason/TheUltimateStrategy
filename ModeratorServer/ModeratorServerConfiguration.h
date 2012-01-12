
#ifndef _MODERATORSERVERCONFIGURATION_H_
#define _MODERATORSERVERCONFIGURATION_H_

#include "IModeratorServerConfiguration.h"
#include <string>

class ModeratorServerConfiguration: public IModeratorServerConfiguration {
public:
    virtual std::string getAddress() const;
    virtual unsigned int getPort() const;
    
    void setAddress(const std::string& aAddress);
    void setPort(unsigned aPort);
private:
    std::string mAddress;
    unsigned mPort;
};

#endif

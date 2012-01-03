
#ifndef _BOTCONNECTIONCONFIGURATION_H_
#define _BOTCONNECTIONCONFIGURATION_H_

#include "IBotConnectionConfiguration.h"

class BotConnectionConfiguration: public IBotConnectionConfiguration {
public:
    virtual std::string getServerAddress() const;
    virtual unsigned getServerPort() const;
    
    void setServerAddress(const std::string& aAddress);
    void setServerPort(unsigned aPort);
private:
    std::string mServerAddress;
    unsigned mServerPort;
};

#endif

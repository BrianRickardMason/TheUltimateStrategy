
#ifndef _IBOTCONNECTIONCONFIGURATION_H_
#define _IBOTCONNECTIONCONFIGURATION_H_

#include <string>

class IBotConnectionConfiguration{
public:
    virtual std::string getServerAddress() const = 0;
    virtual unsigned    getServerPort() const = 0;
    
    virtual ~IBotConnectionConfiguration(){}
protected:
    IBotConnectionConfiguration(){}
};

#endif

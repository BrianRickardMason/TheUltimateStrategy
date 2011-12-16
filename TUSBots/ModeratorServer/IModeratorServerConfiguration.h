
#ifndef _IMODERATORSERVERCONFIGURATION_H_
#define _IMODERATORSERVERCONFIGURATION_H_

#include <string>

class IModeratorServerConfiguration {
public:
    virtual unsigned    getPort()const = 0;
    virtual std::string getAddress()const = 0;
    
    virtual ~IModeratorServerConfiguration(){}
protected:
    IModeratorServerConfiguration(){}
};

#endif

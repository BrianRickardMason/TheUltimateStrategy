
#ifndef _GENERALCONFIG_H_
#define _GENERALCONFIG_H_

#include <map>
#include <string>
#include <sstream>
#include <stdexcept>

class GeneralConfig: public std::map<std::string, std::string> {
public:
    typedef std::map<std::string, std::string> StringMap;
    
    GeneralConfig(): StringMap(){};
    ~ GeneralConfig(){}
    
    bool hasKey(const std::string& aKey)const{
        StringMap::const_iterator it = find(aKey);
        return it != end();
    }
    
    template <typename T>
    T get(const std::string& aKey) const{
        StringMap::const_iterator it = find(aKey);
        if(it == end())throw std::runtime_error("key does not exist");
        
        std::stringstream conv( it->second );
        // automatically detect the base, depending on prefix; thanks stackoverflow
        conv.unsetf(std::ios_base::basefield);
        conv << std::noskipws;
        
        T tmp;
        conv >> tmp;
        return tmp;
    }
};

#endif

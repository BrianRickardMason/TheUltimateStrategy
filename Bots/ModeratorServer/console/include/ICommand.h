
#ifndef _ICOMMAND_H_
#define _ICOMMAND_H_

#include <memory>
#include <map>
#include <vector>
#include <string>

#include <Poco/SharedPtr.h>

class ICommand {
public:
    typedef std::auto_ptr<ICommand> SingleHandle;
    typedef Poco::SharedPtr<ICommand> Handle;
    
    //typedef std::map<std::string,std::string> Params;
    class Params {
    public:
        Params(): mParameters(){}
        
        // building
        
        void addParameter(const std::string& aValue){
            StrHandle s( new std::string(aValue));
            
            mParamMap[getParamId(mParamVec.size())] = s;
            mParamVec.push_back(s);
        }
        void addParameter(const std::string& aKey, const std::string& aValue){
            StrHandle s( new std::string(aValue));
            
            mParamMap[aKey] = s;
            mParamMap[getParamId(mParamVec.size())] = s;
            mParamVec.push_back(s);
        }
        
        void setParameterString(const std::string& aValue){
            mParameters = aValue;
        }
        
        // accessing
        
        const std::string& getParameter(size_t aIndex)const{
            return *(mParamVec.at(aIndex));
        }
        
        const std::string& getParameter(const std::string& aKey)const{
            return *(mParamMap.at(aKey));
        }
        
        const std::string& getParameterString()const{
            return mParameters;
        }
        
        size_t count()const{
            return mParamVec.size();
        }
        
        std::vector<std::string> getKeys() const {
            std::vector<std::string> ret;
            for(std::map <std::string, StrHandle>::const_iterator it = mParamMap.begin(); it != mParamMap.end(); ++it){
                ret.push_back(it->first);
            }
            return ret;
        }
        
        const std::string& operator[](const std::string& aKey) const{ 
            return getParameter(aKey);
        }
        
        const std::string& operator[](size_t aIndex) const{ 
            return getParameter(aIndex);
        }
    private:
        typedef Poco::SharedPtr <std::string> StrHandle;
    
        std::map <std::string, StrHandle> mParamMap;
        std::vector <StrHandle> mParamVec;
        
        std::string mParameters;
        
        std::string getParamId(int aParamNumber)const{
            std::stringstream str;
            str << "_" << aParamNumber << "=";
            return str.str();
        }
    };
    
    virtual const Params& getParams()const = 0;
    
    virtual int execute() const = 0;
    
    virtual ~ICommand(){}
protected:
    ICommand(){}
};

#endif

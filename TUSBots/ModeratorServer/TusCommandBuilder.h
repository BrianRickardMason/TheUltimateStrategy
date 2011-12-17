
#ifndef _TUSCOMMANDBUILDER_H_
#define _TUSCOMMANDBUILDER_H_

#include <memory>
#include <string>

#include <Poco/DOM/Document.h>
#include <Poco/DOM/Element.h>
#include <Poco/DOM/NodeList.h>
#include <stdexcept>
#include "Credentials.h"

class TusCommand: public Poco::XML::Document {
public:
    typedef std::auto_ptr<TusCommand> SingleHandle;
    
    TusCommand(Poco::XML::NamePool* pNamePool = 0)
    :   Document(pNamePool){}
    
    virtual ~TusCommand(){};
};

class TusReturnValue: public Poco::XML::Document {
public:
    typedef std::auto_ptr<TusReturnValue> SingleHandle;
    
    TusReturnValue(Poco::XML::NamePool* pNamePool = 0)
    :   Document(pNamePool){}
    
    virtual ~TusReturnValue(){};
};

class TusCommandBuilder {
public:
    void makeCommand(const std::string aCommandName){
        using Poco::XML::Document;
        
        mDocument.reset( new TusCommand() );
        mCurrentNode = mDocument.get();
        
        Poco::XML::Element *el = mDocument->createElement("request") ;
        el->setAttribute("id",aCommandName);
        mCurrentNode = mCurrentNode->appendChild( el );
    }
    
    void setCredentials(const Credentials& aCredentials){
        Poco::XML::Element *el;
        
        el = mDocument->createElement("user");
        mDocument->documentElement()->appendChild(el);
        mCurrentNode = el;
        
        el = mDocument->createElement("login");
        el->setAttribute("value", aCredentials.Username);
        mCurrentNode->appendChild(el);
        
        el = mDocument->createElement("password");
        el->setAttribute("value", aCredentials.Password);
        mCurrentNode->appendChild(el);
        
        mCurrentNode = mDocument->documentElement();
    }
    
    void openParamSet(){
        Poco::XML::Element *el;
        Poco::XML::NodeList *nl = mDocument->getElementsByTagName("parameters");
        
        if( nl->length() == 1){
            mCurrentNode = nl->item(0);
        }
        else if(nl->length() == 0){
            el = mDocument->createElement("parameters");
            mDocument->documentElement()->appendChild(el);
            mCurrentNode = el;
        }
        else {
            throw std::runtime_error("command DOM corrupted");
        }
    }
    
    void closeParamSet(){
        mCurrentNode = mCurrentNode->parentNode();
    }
    
    void addParam(const std::string aParam, const std::string aValue){
        Poco::XML::Element *el;
        el = mDocument->createElement(aParam);
        el->setAttribute("value", aValue);
        mCurrentNode->appendChild(el);
    }
    
    std::auto_ptr<TusCommand> extract(){
        return mDocument;
    }
private:
    std::auto_ptr<TusCommand> mDocument;
    Poco::XML::Node* mCurrentNode;
};

#endif


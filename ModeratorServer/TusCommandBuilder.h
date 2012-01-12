
#ifndef _TUSCOMMANDBUILDER_H_
#define _TUSCOMMANDBUILDER_H_

#include <memory>
#include <string>

#include <Poco/DOM/DOMImplementation.h>
#include <Poco/DOM/Document.h>
#include <Poco/DOM/Element.h>
#include <Poco/DOM/NodeList.h>
#include <Poco/DOM/DocumentType.h>

#include <stdexcept>
#include "Credentials.h"
#include <Poco/AutoPtr.h>

class TusCommand: public Poco::XML::Document {
public:
    typedef std::auto_ptr<TusCommand> SingleHandle;
    
    TusCommand(Poco::XML::NamePool* pNamePool = 0)
    :   Document(pNamePool){}
    
    TusCommand(Poco::XML::DocumentType* pDocumentType, Poco::XML::NamePool* pNamePool = 0)
    :   Document(pDocumentType, pNamePool){}
    
    virtual ~TusCommand(){};
};

class TusReturnValue: public Poco::XML::Document {
public:
    typedef std::auto_ptr<TusReturnValue> SingleHandle;
    
    TusReturnValue(Poco::XML::NamePool* pNamePool = 0)
    :   Document(pNamePool){}
    
    TusReturnValue(Poco::XML::DocumentType* pDocumentType, Poco::XML::NamePool* pNamePool = 0)
    :   Document(pDocumentType, pNamePool){}
    
    virtual ~TusReturnValue(){};
};

class TusIndication: public std::string {
public:
    typedef std::auto_ptr<TusIndication> SingleHandle;
    
    TusIndication(const std::string& aValue): std::string(aValue){};
    
    virtual ~TusIndication(){};
};

class TusCommandBuilder {
public:
    void makeCommand(const std::string aCommandName){
        using Poco::XML::Document;
        using Poco::XML::DocumentType;
        
        Poco::AutoPtr<DocumentType> dtd(
            Poco::XML::DOMImplementation::instance().createDocumentType(
                "message","TUS 1.0 -- RPC protocol","Protocol.dtd"));
        
        mDocument.reset( new TusCommand(dtd.get()) );
        mCurrentNode = mDocument.get();
        
        Poco::AutoPtr<Poco::XML::Element> el = mDocument->createElement("request") ;
        el->setAttribute("id",aCommandName);
        mCurrentNode = mCurrentNode->appendChild( el.get() );
    }
    
    void setCredentials(const Credentials& aCredentials){
        Poco::AutoPtr<Poco::XML::Element> el;
        
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
        Poco::AutoPtr<Poco::XML::Element> el;
        Poco::AutoPtr<Poco::XML::NodeList> nl = mDocument->getElementsByTagName("parameters");
        
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
        Poco::AutoPtr<Poco::XML::Element> el;
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


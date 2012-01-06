
#ifndef _ICOMMANDCREATOR_H_
#define _ICOMMANDCREATOR_H_

#include <memory>
#include <Poco/SharedPtr.h>

class ICommandCreator {
public:
    typedef Poco::SharedPtr <ICommandCreator> Handle;
    typedef std::auto_ptr <ICommandCreator>   SingleHandle;

    /**
     * Creates particular command
     */
    virtual ICommand::SingleHandle create(const ICommand::Params& aParams) = 0;

    /**
     * Return description of created command (help text)
     */
    virtual std::string getDescription()const = 0;

    virtual ~ICommandCreator(){}
protected:
    ICommandCreator(){}
};

#endif

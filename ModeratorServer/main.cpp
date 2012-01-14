
#include <iostream>

#include "ModeratorContext.h"
#include "ModeratorContextBuilder.h"

#include "Moderator.h"

void test();

int main(int aNumberOfArguments, char **aArguments){
    std::clog << "***hack" << std::endl;
    test();
    std::clog << "###slash" << std::endl;
    //^ quick hack tests, see below

    std::auto_ptr< Moderator > moderator;
    {
        ModeratorContextBuilder ctxBuider;
        ctxBuider.make();
        ctxBuider.fillDefault();
        // config for SimpleGameControl
        ctxBuider.peek().Config()["sgc_ticks"] = "20";
        ctxBuider.peek().Config()["sgc_epochs"] = "1";
        ctxBuider.peek().Config()["sgc_world"] = "World";
        ctxBuider.peek().Config()["sgc_notify"] = "1";
        ctxBuider.peek().Config()["sgc_sleep"] = "1250"/*ms*/;

        moderator.reset( new Moderator(ctxBuider.extract()) );
    }

    return moderator->run(aNumberOfArguments, aArguments);
}

#include "TusCommandBuilder.h"
#include "TusCommands.h"

#include <Poco/DOM/DOMWriter.h>
#include <Poco/XML/XMLWriter.h>
#include <Protocol/Xml/Cpp/MessageFactory.hpp>

void test(){
    TusCommandBuilder b;
    b.makeCommand(CREATE_WORLD);
    b.setCredentials( Credentials("modbot","modbotpass") );
    b.openParamSet();
    b.addParam("world_name","World");
    b.closeParamSet();

    std::auto_ptr<TusCommand> cmd( b.extract() );

    Poco::XML::DOMWriter writer;
    writer.setOptions(
            Poco::XML::XMLWriter::PRETTY_PRINT
        |   Poco::XML::XMLWriter::WRITE_XML_DECLARATION
    );

    writer.writeNode(std::clog, cmd.get());
    std::clog << "\n\n" << std::endl;

    TUSProtocol::MessageFactory fac;
    TUSProtocol::Message::Handle msg = fac.createCreateWorldRequest("modbot","modbotpass","World");

    writer.writeNode(std::clog, msg.get());
    std::clog << "\n\n" << std::endl;
}

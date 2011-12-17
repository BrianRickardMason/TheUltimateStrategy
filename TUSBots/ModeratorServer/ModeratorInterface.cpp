
#include "ModeratorInterface.h"

#include "IBotConnectionConfiguration.h"
#include "TusCommands.h"

#include <Poco/Net/StreamSocket.h>
#include <Poco/Net/SocketStream.h>
#include <Poco/DOM/DOMWriter.h>
#include <Poco/DOM/DOMParser.h>
#include <Poco/DOM/NamedNodeMap.h>
#include <Poco/SAX/InputSource.h>

#include <sstream>
#include <iostream>

ModeratorInterface::ModeratorInterface(IModeratorContext::Handle aContext, IBotManager::Handle aManager): 
    mContext(aContext), mBotManager(aManager) {

}

std::auto_ptr< TusCommand > ModeratorInterface::prepareWorldCommand(const std::string& aCommandName){
    mCmdBuilder.makeCommand(aCommandName);
    mCmdBuilder.setCredentials(*mCredentials);
    mCmdBuilder.openParamSet();
    mCmdBuilder.addParam("world_name", mCurrentWorld);
    mCmdBuilder.closeParamSet();
    
    return mCmdBuilder.extract();
}

int ModeratorInterface::createEpoch(const std::string& aEpochName) {
    mCmdBuilder.makeCommand(CREATE_EPOCH);
    mCmdBuilder.setCredentials(*mCredentials);
    mCmdBuilder.openParamSet();
    mCmdBuilder.addParam("world_name", mCurrentWorld);
    mCmdBuilder.addParam("epoch_name", aEpochName);
    mCmdBuilder.closeParamSet();
    
    TusCommand::SingleHandle cmd = mCmdBuilder.extract();
    return executeCommand(cmd);
}

int ModeratorInterface::createWorld(const std::string& aWorldName) {
    mCmdBuilder.makeCommand(CREATE_WORLD);
    mCmdBuilder.setCredentials(*mCredentials);
    mCmdBuilder.openParamSet();
    mCmdBuilder.addParam("world_name", aWorldName);
    mCmdBuilder.closeParamSet();
    
    TusCommand::SingleHandle cmd = mCmdBuilder.extract();
    return executeCommand(cmd);
}

int ModeratorInterface::activateEpoch() {
    std::auto_ptr< TusCommand > cmd = prepareWorldCommand(ACTIVATE_EPOCH);
    
    return executeCommand(cmd);
}

int ModeratorInterface::deactivateEpoch() {
    std::auto_ptr< TusCommand > cmd = prepareWorldCommand(DEACTIVATE_EPOCH);
    
    return executeCommand(cmd);
}

int ModeratorInterface::deleteEpoch() {
    std::auto_ptr< TusCommand > cmd = prepareWorldCommand(DELETE_EPOCH);
    
    return executeCommand(cmd);
}

int ModeratorInterface::finishEpoch() {
    std::auto_ptr< TusCommand > cmd = prepareWorldCommand(FINISH_EPOCH);
    
    return executeCommand(cmd);
}

int ModeratorInterface::tickEpoch() {
    std::auto_ptr< TusCommand > cmd = prepareWorldCommand(TICK_EPOCH);
    
    return executeCommand(cmd);
}

void ModeratorInterface::setCurrentWorld(const std::string& aWorldName) {
    mCurrentWorld = aWorldName;
}

void ModeratorInterface::setModeratorCredentials(const Credentials& aCredenetials) {
    mCredentials = new Credentials(aCredenetials);
}

int ModeratorInterface::executeCommand(std::auto_ptr< TusCommand >& in){
    std::auto_ptr< TusReturnValue > ret;
    
    sendCommand(in,ret);

    std::stringstream status;
    status << ret->getElementsByTagName("status")->item(0)->
                attributes()->getNamedItem("value")->getNodeValue();
    int r = -1;
    status >> r;
    
    return r;
}

void ModeratorInterface::sendCommand(std::auto_ptr< TusCommand >& in, std::auto_ptr< TusReturnValue >& out) {
    const IBotConnectionConfiguration& conf( mContext->getBotConnectionConf());
    Poco::Net::SocketAddress address(conf.getServerAddress(), conf.getServerPort());
    Poco::Net::StreamSocket server(address);
    Poco::Net::SocketStream stream(server);
    Poco::XML::DOMWriter writer;
    
    stream << std::noskipws << std::nounitbuf;

// writer.writeNode(std::clog, in.get());
    writer.writeNode(stream, in.get());
    stream.flush();
    
    Poco::XML::DOMParser parser;
    Poco::XML::InputSource is(stream);
    
    Poco::XML::Document* doc(parser.parse(&is));
    stream.close();
    
// writer.writeNode(std::clog, doc);
    out.reset( new TusReturnValue );
    out->appendChild( out->importNode(doc->documentElement(), true) );

    doc->release();
}

void ModeratorInterface::notifyTick() {
    TusIndication notification("<reply isdummy=\"true\">dummy</reply>\n");
    
    mBotManager->broadcast(notification);
}

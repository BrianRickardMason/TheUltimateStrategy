
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
    mContext(aContext), mBotManager(aManager), mCredentials() {

    // TODO get this from context / factory / facade / implementation when available
    mReqBuilder.reset( new TUSLanguage::UserRequestBuilder(new TUSLanguage::RequestBuilder));
    mToProtocol.reset( new Protocol::LanguageToProtocolTranslator);
    mToLanguage.reset( new Protocol::ProtocolToLanguageTranslator);
}

int ModeratorInterface::createEpoch(const std::string& aEpochName) {
    TUSLanguage::ICommand::Handle cmd = 
        mReqBuilder->buildCreateEpochRequest(aEpochName);
    return executeCommand(cmd);
}

int ModeratorInterface::createWorld(const std::string& aWorldName) {
    TUSLanguage::ICommand::Handle cmd =
        mReqBuilder->buildCreateWorldRequest(aWorldName);
    return executeCommand(cmd);
}

int ModeratorInterface::activateEpoch() {
    TUSLanguage::ICommand::Handle cmd =
        mReqBuilder->buildActivateEpochRequest();
    return executeCommand(cmd);
}

int ModeratorInterface::deactivateEpoch() {
    TUSLanguage::ICommand::Handle cmd =
        mReqBuilder->buildDeactivateEpochRequest();
    return executeCommand(cmd);
}

int ModeratorInterface::deleteEpoch() {
    TUSLanguage::ICommand::Handle cmd =
        mReqBuilder->buildDeleteEpochRequest();
    return executeCommand(cmd);
}

int ModeratorInterface::finishEpoch() {
    TUSLanguage::ICommand::Handle cmd =
        mReqBuilder->buildFinishEpochRequest();
    return executeCommand(cmd);
}

int ModeratorInterface::tickEpoch() {
    TUSLanguage::ICommand::Handle cmd =
        mReqBuilder->buildTickEpochRequest();
    return executeCommand(cmd);
}

void ModeratorInterface::setCurrentWorld(const std::string& aWorldName) {
    mCurrentWorld = aWorldName;

    mReqBuilder->setWorld(aWorldName);
}

void ModeratorInterface::setModeratorCredentials(const Credentials& aCredenetials) {
    mCredentials = new Credentials(aCredenetials);

    mReqBuilder->setCredenials(
        mCredentials->Username,
        mCredentials->Password
    );
}

int ModeratorInterface::executeCommand(TUSLanguage::ICommand::Handle in){
    TUSLanguage::ICommand::Handle ret;

    sendCommand(in,ret);

    return ret->getCode();
}

void ModeratorInterface::sendCommand(
    TUSLanguage::ICommand::Handle& in,
    TUSLanguage::ICommand::Handle& out
) {
    const IBotConnectionConfiguration& conf( mContext->getBotConnectionConf());
    Poco::Net::SocketAddress address(
        conf.getServerAddress(), conf.getServerPort()
    );
    Poco::Net::StreamSocket server(address);
    Poco::Net::SocketStream stream(server);
    Poco::XML::DOMWriter writer;

    Protocol::Message::Handle req = mToProtocol->translate(in);
    
    stream << std::noskipws << std::nounitbuf;

// writer.writeNode(std::clog, req.get());
    writer.writeNode(stream, req.get());
    stream.flush();
    
    Poco::XML::DOMParser parser;
    Poco::XML::InputSource is(stream);
    
    Poco::XML::Document* doc(parser.parse(&is));
    stream.close();

    Protocol::Message::Handle resp( new Protocol::Message());
    resp->appendChild( resp->importNode(doc->documentElement(), true) );

    out = mToLanguage->translate(resp);

// writer.writeNode(std::clog, doc);

    doc->release();
}

void ModeratorInterface::notifyTick() {
    TusIndication notification("<reply isdummy=\"true\">dummy</reply>\n");
    
    mBotManager->broadcast(notification);
}

#include <iostream>
#include <vector>

#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/TCPServer.h>

#include "BotConnectionFactory.h"
#include "BotConnectionManager.h"
#include "ModeratorContext.h"
#include "ModeratorContextBuilder.h"
#include "IModeratorServerConfiguration.h"


/**
 * Interface for game server
 * 
 * Rather for moderator's operations
 */
class GameServerAgent{
};

/**
 * Strategy/algorithm class controlling how the gameplay look like.
 * 
 * @description This class creates game on server, and controls ticks, epochs and so on.
 */
class GameControl{
}; 

class BotConnectionManager;

/**
 * Binds all the parts together, main application object
 */
class Moderator{
public:
    Moderator(IModeratorContext::Handle aContext)
        :   mContext(aContext){
        }
    
    void startServer(){
        using Poco::Net::SocketAddress;
        using Poco::Net::ServerSocket;
        using Poco::Net::TCPServer;
        
        SocketAddress addr(
            mContext->getModeratorServerConf().getAddress(), 
            mContext->getModeratorServerConf().getPort()
        );
    
        ServerSocket sock(addr);
        
        mBotManger = new BotConnectionManager(mContext);
        mServer.reset( new TCPServer(mBotManger, sock));
        
        mServer->start();
    }
    
    void startInputRead(){
        std::vector<char> buf(255,0);
        
        std::clog << "Press enter to close the application" << std::endl;
        
        std::cin.getline(&buf[0],buf.size());
    }
private:
    BotConnectionManager::Ptr mBotManger;
    std::auto_ptr<Poco::Net::TCPServer> mServer;
    IModeratorContext::Handle mContext;
    
//     GameServerAgent& mGameServer;
//     GameControl& mGameControl;
};

#include "TusCommandBuilder.h"
#include <Poco/DOM/DOMWriter.h>

const std::string CREATE_WORLD = "22";
const std::string FINISH_EPOCH = "27";
const std::string GET_BUILDING = "13";
const std::string GET_LAND = "5";
const std::string CREATE_USER = "21";
const std::string GET_LANDS = "6";
const std::string ACTIVATE_EPOCH = "25";
const std::string DELETE_LAND = "4";
const std::string GET_EPOCH = "29";
const std::string BUILD_BUILDING = "11";
const std::string CREATE_EPOCH = "23";
const std::string CREATE_LAND = "3";
const std::string TICK_EPOCH = "28";
const std::string GET_HUMANS = "18";
const std::string DELETE_SETTLEMENT = "8";
const std::string GET_BUILDINGS = "14";
const std::string GET_RESOURCES = "20";
const std::string DESTROY_BUILDING = "12";
const std::string ECHO = "1";
const std::string ERROR = "2";
const std::string DEACTIVATE_EPOCH = "26";
const std::string DISMISS_HUMAN = "15";
const std::string TRANSPORT_HUMAN = "30";
const std::string TRANSPORT_RESOURCE = "31";
const std::string CREATE_SETTLEMENT = "7";
const std::string GET_SETTLEMENT = "9";
const std::string ENGAGE_HUMAN = "16";
const std::string GET_HUMAN = "17";
const std::string GET_SETTLEMENTS = "10";
const std::string DELETE_EPOCH = "24";
const std::string GET_RESOURCE = "19";


int main(int aNumberOfArguments, char **aArguments){
    ModeratorContextBuilder ctxBuider;
    ctxBuider.make();
    ctxBuider.fillDefault();
    
    std::auto_ptr< Moderator > moderator( new Moderator(ctxBuider.extract()) );
    
    moderator->startServer();

    TusCommandBuilder b;
    b.makeCommand(CREATE_WORLD);
    b.setCredentials("modbot","modbotpass");
    b.openParamSet();
    b.addParam("world_name","World");
    b.closeParamSet();
    
    std::auto_ptr<TusCommand> cmd( b.extract() );
    
    Poco::XML::DOMWriter writer;
    writer.writeNode(std::clog, cmd.get()); 
    
    moderator->startInputRead();
    
    return 0;
}


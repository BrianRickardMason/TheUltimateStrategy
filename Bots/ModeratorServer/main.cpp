#include <iostream>
#include <vector>

#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/TCPServer.h>

#include "BotConnectionFactory.h"
#include "BotConnectionManager.h"
#include "ModeratorContext.h"
#include "ModeratorContextBuilder.h"
#include "IModeratorServerConfiguration.h"
#include "SimpleGameControl.h"


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
        
        std::clog << '\n' << "Press enter to close the application" << std::endl;
        
        std::cin.getline(&buf[0],buf.size());
    }
    
    void startGame(){
        SimpleGameControl game(mContext, mBotManger);
        game.run();
    }
private:
    Poco::SharedPtr<BotConnectionManager> mBotManger;
    std::auto_ptr<Poco::Net::TCPServer> mServer;
    IModeratorContext::Handle mContext;
    
//     GameServerAgent& mGameServer;
//     GameControl& mGameControl;
};

int main(int aNumberOfArguments, char **aArguments){
    ModeratorContextBuilder ctxBuider;
    ctxBuider.make();
    ctxBuider.fillDefault();
    // config for SimpleGameControl
    ctxBuider.peek().Config()["sgc_ticks"] = "20";
    ctxBuider.peek().Config()["sgc_epochs"] = "1";
    ctxBuider.peek().Config()["sgc_world"] = "World";
    ctxBuider.peek().Config()["sgc_notify"] = "1";
    ctxBuider.peek().Config()["sgc_sleep"] = "1250"/*ms*/;
    
    std::auto_ptr< Moderator > moderator( new Moderator(ctxBuider.extract()) );
    
    moderator->startServer();
    moderator->startGame();    
    //moderator->startInputRead();
    
    return 0;
}

#include "TusCommandBuilder.h"
#include "TusCommands.h"

#include <Poco/DOM/DOMWriter.h>

void test(){
    TusCommandBuilder b;
    b.makeCommand(CREATE_WORLD);
    b.setCredentials( Credentials("modbot","modbotpass") );
    b.openParamSet();
    b.addParam("world_name","World");
    b.closeParamSet();
    
    std::auto_ptr<TusCommand> cmd( b.extract() );
    
    Poco::XML::DOMWriter writer;
    writer.writeNode(std::clog, cmd.get()); 
    
    std::clog << "\n\n" << std::endl;
}

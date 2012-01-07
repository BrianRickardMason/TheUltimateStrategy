#include <iostream>
#include <vector>

#include <Poco/Util/ServerApplication.h>
#include <Poco/Util/HelpFormatter.h>
#include <Poco/Util/Option.h>
#include <Poco/Util/OptionSet.h>

#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/TCPServer.h>

#include "BotConnectionFactory.h"
#include "BotConnectionManager.h"
#include "ModeratorContext.h"
#include "ModeratorContextBuilder.h"
#include "IModeratorServerConfiguration.h"
#include "SimpleGameControl.h"
#include "console/Console.h"
#include "console/ConfigurableCommandFactory.h"
#include "console/EchoCommand.h"
#include "console/CloseCommand.h"


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
class Moderator: public Poco::Util::ServerApplication {
public:
    Moderator(IModeratorContext::Handle aContext)
        :   mContext(aContext), mServerRunning(false), 
            mConsole(new Console(std::cin, std::cout, std::cerr, std::clog)) {
        //---
        setupCommands();
    }
    
    void startServer(){
        if(mServerRunning) {
            // TODO report
            std::clog << "Server is already running" << std::endl;
        }
        else {
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
            mServerRunning = true;
        }
    }
    
    /**
     * Starts interpreting commands
     * 
     * @remark Blocking in the current thread
     */
    void startInputRead(){
        mConsole->echo("*** Moderator console");
        mConsole->echo("*   Type 'close' to end the application");
        
        mConsole->run();
    }
    
    void startGame(){
        if(mGameThread.isRunning()){
            // TODO report
            std::clog << "Game is already running" << std::endl;
        }
        else {
            mGameControl.reset(new SimpleGameControl(mContext, mBotManger));
            mGameThread.start(*mGameControl);
        }
    }
private:
    Poco::SharedPtr<BotConnectionManager> mBotManger;
    
    bool mServerRunning;
    std::auto_ptr<Poco::Net::TCPServer> mServer;
    
    IModeratorContext::Handle mContext;
    
    std::auto_ptr<SimpleGameControl> mGameControl;
    Poco::Thread mGameThread;
    
    IConfigurableCommandFactory::Handle mCommands;
    Poco::SharedPtr<Console> mConsole;
    
//     GameServerAgent& mGameServer;
    bool mHelpRequested;
private:
    void setupCommands() {
        mCommands = new ConfigurableCommandFactory();
        
        mCommands->addCreator("echo", ICommandCreator::SingleHandle(new EchoCommandCreator(*mConsole)));
        mCommands->addCreator("close", ICommandCreator::SingleHandle(new CloseCommandCreator(*mConsole)));
        
        mConsole->setCommandFactory(mCommands);
    }
    
protected:
    void initialize(Application& self) {
        Poco::Util::ServerApplication::initialize(self);
    }

    void uninitialize() {
        Poco::Util::ServerApplication::uninitialize();
    }

    void defineOptions(Poco::Util::OptionSet& options) {
        Poco::Util::ServerApplication::defineOptions(options);

        options.addOption(
        Poco::Util::Option("help", "h", "display argument help information")
            .required(false)
            .repeatable(false)
            .callback(Poco::Util::OptionCallback<Moderator>(
                this, &Moderator::handleHelp))
        );
        
        options.addOption(
        Poco::Util::Option("interactive", "i", "runs interactive mode")
            .required(false)
            .repeatable(false)
            .binding("interactive")
            .noArgument()
        );
    }

    void handleHelp(const std::string& name, const std::string& value) {
        Poco::Util::HelpFormatter helpFormatter(options());
        helpFormatter.setCommand(commandName());
        helpFormatter.setUsage("OPTIONS");
        helpFormatter.setHeader("Moderator server for The Ultimate Strategy");
        helpFormatter.setFooter(
            "Moderator controls the game -- creates epochs, ticks the turns etc. "
            "The program can be run in interactive mode -- controlls happen by stdin, "
            "or in normal mode, when the game is started automatically and blah blah blah");
        helpFormatter.format(std::cout);
        
        stopOptionsProcessing();
        mHelpRequested = true;
    }

    int main(const std::vector<std::string>& args) {
        if (!mHelpRequested) {
            if(! config().hasOption("interactive")){
                std::clog << "noninteractive" << std::endl;
                startServer();
                startGame();    
                
                mGameThread.join();
            }
            else {
                std::clog << "interactive" << std::endl;
                startInputRead();
                
                // TODO use this, and be compatible with deamon mode
                //waitForTerminationRequest();
            }
        }
        
        return Poco::Util::Application::EXIT_OK;
    }

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
    return moderator->run(aNumberOfArguments, aArguments);
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

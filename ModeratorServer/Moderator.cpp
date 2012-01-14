
#include "Moderator.h"

#include <vector>

#include <Poco/Util/ServerApplication.h>
#include <Poco/Util/HelpFormatter.h>
#include <Poco/Util/Option.h>
#include <Poco/Util/OptionSet.h>

#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/TCPServer.h>

#include "BotConnectionFactory.h"
#include "BotConnectionManager.h"
#include "SimpleGameControl.h"
#include "IModeratorServerConfiguration.h"

#include <ConsoleFacade.h>


Moderator::Moderator(IModeratorContext::Handle aContext)
    :   mContext(aContext), mServerRunning(false), mHelpRequested(false), mBotManger(),
        mConsole(mContext->getConsoleFacade().createConsole(std::cin, std::cout, std::cerr, std::clog)) {
    //---
    setupCommands();
}

void Moderator::startServer(){
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
void Moderator::startInputRead(){
    mConsole->echo("*** Moderator console");
    mConsole->echo("*   Type 'close' to end the application");

    mConsole->run();
}

void Moderator::startGame(){
    if(mGameThread.isRunning()){
        // TODO report
        std::clog << "Game is already running" << std::endl;
    }
    else {
        mGameControl.reset(new SimpleGameControl(mContext, mBotManger));
        mGameThread.start(*mGameControl);
    }
}

void Moderator::setupCommands() {
    mCommands = mContext->getConsoleFacade().createConfigurableCommandFactory();

    mCommands->addCreator("echo", mContext->getConsoleFacade().getEchoCmdCreator (*mConsole) );
    mCommands->addCreator("close", mContext->getConsoleFacade().getCloseCmdCreator (*mConsole) );

    mConsole->setCommandFactory(mCommands);
}

void Moderator::initialize(Application& self) {
    Poco::Util::ServerApplication::initialize(self);
}

void Moderator::uninitialize() {
    Poco::Util::ServerApplication::uninitialize();
}

void Moderator::defineOptions(Poco::Util::OptionSet& options) {
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

void Moderator::handleHelp(const std::string& name, const std::string& value) {
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

int Moderator::main(const std::vector<std::string>& args) {
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

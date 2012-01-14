
#ifndef _MODERATOR_H_
#define _MODERATOR_H_

#include <Poco/Util/ServerApplication.h>
#include <Poco/Net/TCPServer.h>

#include <IConfigurableCommandFactory.h>
#include <IConsole.h>

#include "IModeratorContext.h"
#include "BotConnectionManager.h"
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

/**
 * Binds all the parts together, main application object
 */
class Moderator: public Poco::Util::ServerApplication {
public:
    Moderator(IModeratorContext::Handle aContext);

    void startServer();

    /**
     * Starts interpreting commands
     *
     * @remark Blocking in the current thread
     */
    void startInputRead();
    void startGame();
private:
    Poco::SharedPtr<BotConnectionManager> mBotManger;

    bool mServerRunning;
    std::auto_ptr<Poco::Net::TCPServer> mServer;

    IModeratorContext::Handle mContext;

    std::auto_ptr<SimpleGameControl> mGameControl;
    Poco::Thread mGameThread;

    IConfigurableCommandFactory::Handle mCommands;
    Poco::SharedPtr<IConsole> mConsole;

    bool mHelpRequested;
private:
    void setupCommands();

protected:
    void initialize(Application& self);
    void uninitialize();

    void defineOptions(Poco::Util::OptionSet& options);

    void handleHelp(const std::string& name, const std::string& value);

    int main(const std::vector<std::string>& args);
};

#endif

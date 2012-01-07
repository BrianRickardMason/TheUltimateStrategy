project(moderator)

add_executable(moderator 
    main.cpp
    BotConnection.cpp
    BotConnectionManager.cpp
    BotConnectionConfiguration.cpp
    ModeratorContext.cpp
    ModeratorContextBuilder.cpp
    ModeratorServerConfiguration.cpp
    TusMessageBuffer.cpp
    ModeratorInterface.cpp
)

target_link_libraries(moderator
    PocoNet PocoFoundation PocoXML PocoUtil
)

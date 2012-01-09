cmake_minimum_required(VERSION 2.8)

project(moderator)

include_directories(
    console/include
)

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
    console
    PocoNet PocoFoundation PocoXML PocoUtil
)

add_subdirectory(console)

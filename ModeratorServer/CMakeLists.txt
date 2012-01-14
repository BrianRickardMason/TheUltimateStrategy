cmake_minimum_required(VERSION 2.8)

project(moderator)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fno-inline")

include_directories(
    console/include
    ${CMAKE_CURRENT_SOURCE_DIR}/..
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
    Credentials.cpp
)

target_link_libraries(moderator
    protocolxmlcpp
    interface
    console
    PocoNet PocoFoundation PocoXML PocoUtil
)

add_subdirectory(console)

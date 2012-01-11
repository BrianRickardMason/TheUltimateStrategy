cmake_minimum_required(VERSION 2.8)

add_executable(console_ut 
    main.cpp
    ConsoleMocks.cpp
    ConsoleFacadeShould.cpp
    ConsoleFacadeProvidedEchoCommandShould.cpp
    ICommandParamsShould.cpp
    ConsoleFacadeProvidedCloseCommandShould.cpp
)

target_link_libraries(console_ut
    console
    gmock
    gtest
)

set(CMAKE_BUILD_TYPE Debug)

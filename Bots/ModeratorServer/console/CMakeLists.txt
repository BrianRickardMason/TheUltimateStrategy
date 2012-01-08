cmake_minimum_required(VERSION 2.8)

project(console)

include_directories(
    include
)

add_library(console
    src/Console.cpp
    src/ConsoleInterpreter.cpp
    src/ConsoleFacade.cpp
    src/ConfigurableCommandFactory.cpp
)

target_link_libraries(console
    PocoFoundation 
)

add_subdirectory(ut)

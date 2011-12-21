PROJECT(gameserverut)

INCLUDE_DIRECTORIES(${PROJECT_BINARY_DIR}/..)

FILE(GLOB_RECURSE FILES_GAMESERVERUT *.cpp)

ADD_EXECUTABLE(gameserverut
    ${FILES_GAMESERVERUT}
)

TARGET_LINK_LIBRARIES(gameserverut
    xmlrpcserver
    gmock
    gtest
    pthread
)

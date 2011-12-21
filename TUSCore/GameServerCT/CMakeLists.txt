PROJECT(gameserverct)

INCLUDE_DIRECTORIES(${PROJECT_BINARY_DIR}/..)

FILE(GLOB_RECURSE FILES_GAMESERVERCT *.cpp)

ADD_EXECUTABLE(gameserverct
    ${FILES_GAMESERVERCT}
)

TARGET_LINK_LIBRARIES(gameserverct
    xmlrpcserver
    gmock
    gtest
    pthread
)

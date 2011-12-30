PROJECT(networkut)

INCLUDE_DIRECTORIES(${PROJECT_BINARY_DIR}/../..)

FILE(GLOB_RECURSE FILES_NETWORKUT *.cpp)

ADD_EXECUTABLE(networkut
    ${FILES_NETWORKUT}
)

TARGET_LINK_LIBRARIES(networkut
    xmlrpcserver
    xmlrpccommon
    boost_system
    boost_thread
    gtest
    gmock
    pthread
    log4cpp
)

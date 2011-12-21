PROJECT(integrationstress)

INCLUDE_DIRECTORIES(${PROJECT_BINARY_DIR}/..)

FILE(GLOB_RECURSE FILES_INTEGRATIONSTRESS *.cpp)

ADD_EXECUTABLE(integrationstress
    ${FILES_INTEGRATIONSTRESS}
)

ADD_DEPENDENCIES(integrationstress
    server
)

TARGET_LINK_LIBRARIES(integrationstress
    boost_system
    boost_thread
    gmock
    gtest
    log4cpp
    pthread
    xmlrpcserver
    xmlrpccommon
    integrationcommon
    gameserver
    PocoFoundation
)

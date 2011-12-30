PROJECT(xmlrpcserver)

INCLUDE_DIRECTORIES(${PROJECT_BINARY_DIR}/../../..)
INCLUDE_DIRECTORIES(${PROJECT_BINARY_DIR}/../../../TUSGame)

FILE(GLOB_RECURSE FILES_XMLRPCSERVER *.cpp)
FILE(GLOB_RECURSE FILES_XMLRPCSERVER_FILTERED xml_server_main.cpp)

LIST(REMOVE_ITEM FILES_XMLRPCSERVER ${FILES_XMLRPCSERVER_FILTERED})

ADD_LIBRARY(xmlrpcserver
    ${FILES_XMLRPCSERVER}
)

ADD_EXECUTABLE(server
    xml_server_main.cpp
)

TARGET_LINK_LIBRARIES(xmlrpcserver
    gameserver
)

TARGET_LINK_LIBRARIES(server
    boost_system
    boost_thread
    log4cpp
    xmlrpcserver
    xmlrpccommon
)

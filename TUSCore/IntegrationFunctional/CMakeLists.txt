PROJECT(integrationfunctional)

INCLUDE_DIRECTORIES(${PROJECT_BINARY_DIR}/..)

FILE(GLOB_RECURSE FILES_INTEGRATIONFUNCTIONAL *.cpp)

ADD_EXECUTABLE(integrationfunctional
    ${FILES_INTEGRATIONFUNCTIONAL}
)

ADD_DEPENDENCIES(integrationfunctional
    server
)

TARGET_LINK_LIBRARIES(integrationfunctional
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

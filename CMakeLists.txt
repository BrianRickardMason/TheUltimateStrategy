# Copyright (C) 2010 and 2011 Marcin Arkadiusz Skrobiranda.
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
# 3. Neither the name of the project nor the names of its contributors
#    may be used to endorse or promote products derived from this software
#    without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS "AS IS" AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
# OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
# OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
# SUCH DAMAGE.

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(TheUltimateStrategy)

SET(LIBRARY_OUTPUT_PATH lib)
SET(EXECUTABLE_OUTPUT_PATH bin)

include_directories(TUSCore)

FILE(GLOB_RECURSE files_pugixml TUSCore/3rdParty/*.cpp)
FILE(GLOB_RECURSE files_gameserver TUSCore/GameServer/*.cpp)
FILE(GLOB_RECURSE files_xmlrpcserver TUSCore/Network/XmlRPCServer/*.cpp)
FILE(GLOB_RECURSE files_xmlrpcserver_filtered TUSCore/Network/XmlRPCServer/xml_server_main.cpp)
FILE(GLOB_RECURSE files_gameserverut TUSCore/GameServerUT/*.cpp)
FILE(GLOB_RECURSE files_gameserverct TUSCore/GameServerCT/*.cpp)
FILE(GLOB_RECURSE files_xmlrpccommon TUSCore/Network/XmlRPCCommon/*.cpp)
FILE(GLOB_RECURSE files_xmlrpcclientacync TUSCore/Network/XmlRPCClientAsync/*.cpp)
FILE(GLOB_RECURSE files_networkut TUSCore/NetworkUT/*.cpp)
FILE(GLOB_RECURSE files_server TUSCore/Network/XmlRPCServer/xml_server_main.cpp
                               TUSCore/Network/XmlRPCServer/Configurator.cpp)
FILE(GLOB_RECURSE files_client TUSCore/Network/XmlRPCClientAsync/xml_client_async_main.cpp)
FILE(GLOB_RECURSE files_integrationcommon TUSCore/IntegrationCommon/*.cpp)
FILE(GLOB_RECURSE files_integrationfunctional TUSCore/IntegrationFunctional/*.cpp)
FILE(GLOB_RECURSE files_integrationstress TUSCore/IntegrationStress/*.cpp)

LIST(REMOVE_ITEM files_xmlrpcserver ${files_xmlrpcserver_filtered})

ADD_LIBRARY(pugixml ${files_pugixml})
ADD_LIBRARY(gameserver ${files_gameserver})
ADD_LIBRARY(xmlrpcserver ${files_xmlrpcserver})
ADD_LIBRARY(xmlrpccommon ${files_xmlrpccommon})
ADD_LIBRARY(xmlrpcclientasync ${files_xmlrpcclientacync})
ADD_LIBRARY(integrationcommon ${files_integrationcommon})

ADD_EXECUTABLE(gameserverut ${files_gameserverut})
ADD_EXECUTABLE(gameserverct ${files_gameserverct})
ADD_EXECUTABLE(networkut ${files_networkut})
ADD_EXECUTABLE(server ${files_server})
ADD_EXECUTABLE(client ${files_client})
ADD_EXECUTABLE(integrationfunctional ${files_integrationfunctional})
ADD_EXECUTABLE(integrationstress ${files_integrationstress})

TARGET_LINK_LIBRARIES(gameserver pugixml pqxx)
TARGET_LINK_LIBRARIES(xmlrpcserver gameserver)
TARGET_LINK_LIBRARIES(gameserverut gtest gmock pthread xmlrpcserver)
TARGET_LINK_LIBRARIES(gameserverct gtest gmock pthread xmlrpcserver)
TARGET_LINK_LIBRARIES(networkut boost_system boost_thread gtest gmock pthread log4cpp xmlrpcserver xmlrpccommon)
TARGET_LINK_LIBRARIES(server boost_system boost_thread log4cpp xmlrpcserver xmlrpccommon)
TARGET_LINK_LIBRARIES(client boost_system boost_thread pthread xmlrpcclientasync xmlrpccommon)
TARGET_LINK_LIBRARIES(integrationfunctional boost_system boost_thread gmock gtest
                      log4cpp pthread xmlrpcserver xmlrpccommon integrationcommon gameserver PocoFoundation)
TARGET_LINK_LIBRARIES(integrationstress boost_system boost_thread gmock gtest
                      log4cpp pthread xmlrpcserver xmlrpccommon integrationcommon gameserver PocoFoundation)

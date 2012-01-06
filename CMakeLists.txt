# Copyright (C) 2010, 2011 and 2012 Marcin Arkadiusz Skrobiranda.
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

SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

ADD_SUBDIRECTORY(Bots/ModeratorServer)
ADD_SUBDIRECTORY(Game/3rdParty)
ADD_SUBDIRECTORY(Game/GameServer)
ADD_SUBDIRECTORY(Game/GameServerCT)
ADD_SUBDIRECTORY(Game/GameServerUT)
ADD_SUBDIRECTORY(Integration/IntegrationCommon)
ADD_SUBDIRECTORY(Integration/IntegrationFunctional)
ADD_SUBDIRECTORY(Integration/IntegrationStress)
ADD_SUBDIRECTORY(Language/Interface)
ADD_SUBDIRECTORY(Language/InterfaceUT)
ADD_SUBDIRECTORY(Protocol/Xml/Cpp)
ADD_SUBDIRECTORY(Server/Network/XmlRPCCommon)
ADD_SUBDIRECTORY(Server/Network/XmlRPCServer)
ADD_SUBDIRECTORY(Server/NetworkUT)

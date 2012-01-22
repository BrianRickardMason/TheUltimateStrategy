// Copyright (C) 2010, 2011 and 2012 Marcin Arkadiusz Skrobiranda.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
// 3. Neither the name of the project nor the names of its contributors
//    may be used to endorse or promote products derived from this software
//    without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
// OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
// OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
// SUCH DAMAGE.

#include <Poco/DOM/DOMParser.h>
#include <Poco/DOM/Element.h>
#include <Server/Server/include/Configurator.hpp>
#include <boost/lexical_cast.hpp>

namespace Server
{

Configurator::Configurator()
{
    configure();
}

bool Configurator::configure()
{
    if (!loadXml())
    {
        return false;
    }

    if (!parseXml())
    {
        return false;
    }

    return true;
}

std::string Configurator::getHost() const
{
    return mHost;
}

std::string Configurator::getPort() const
{
    return mPort;
}

unsigned short int Configurator::getThreads() const
{
    return mThreads;
}

int Configurator::getLoggerPriority() const
{
    return mLoggerPriority;
}

std::string Configurator::getPersistence() const
{
    return mPersistence;
}

std::string Configurator::getConfigurationPath() const
{
    return mConfigurationPath;
}

std::string Configurator::getConfigurationSelected() const
{
    return mConfigurationSelected;
}

bool Configurator::loadXml()
{
    Poco::XML::DOMParser parser;

    // TODO: Guess the path.
    mServerConfigXml =
        parser.parse("/home/brian/workspace/TheUltimateStrategy/Server/Server/serverconfig.xml");

    return true;
}

bool Configurator::parseXml()
{
    Poco::XML::Element * documentElement = mServerConfigXml->documentElement();

    mHost = documentElement->getChildElement("host")->innerText();
    mPort = documentElement->getChildElement("port")->innerText();
    mThreads = boost::lexical_cast<unsigned short int>(documentElement->getChildElement("threads")->innerText());
    mLoggerPriority =
        boost::lexical_cast<int>(documentElement->getChildElement("logger")->getChildElement("priority")->innerText());
    mPersistence = documentElement->getChildElement("persistence")->innerText();
    mConfigurationPath = documentElement->getChildElement("configuration")->getChildElement("path")->innerText();
    mConfigurationSelected =
        documentElement->getChildElement("configuration")->getChildElement("selected")->innerText();

    return true;
}

} // namespace Server

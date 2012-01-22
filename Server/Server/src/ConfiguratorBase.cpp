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
#include <Server/Server/include/ConfiguratorBase.hpp>
#include <boost/lexical_cast.hpp>

namespace Server
{

ConfiguratorBase::ConfiguratorBase(
    IConfiguratorShrPtr const aConfigurator
)
    : mConfigurator(aConfigurator)
{
    configure();
}

bool ConfiguratorBase::configure()
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

unsigned short int ConfiguratorBase::getFamineDeathFactor() const
{
    return mFamineDeathFactor;
}

unsigned short int ConfiguratorBase::getHumanExperienceFactor() const
{
    return mHumanExperienceFactor;
}

unsigned short int ConfiguratorBase::getHumanReproduceFactor() const
{
    return mHumanReproduceFactor;
}

unsigned short int ConfiguratorBase::getPovertyDismissFactor() const
{
    return mPovertyDismissFactor;
}

bool ConfiguratorBase::loadXml()
{
    Poco::XML::DOMParser parser;

    std::string path =
        mConfigurator->getConfigurationPath() + mConfigurator->getConfigurationSelected() + "/Base/base.xml";

    mBaseXml = parser.parse(path);

    return true;
}

bool ConfiguratorBase::parseXml()
{
    // TODO: Add verification here.

    Poco::XML::Element * documentElement = mBaseXml->documentElement();

    mFamineDeathFactor =
        boost::lexical_cast<unsigned short int>(documentElement->getChildElement("faminedeathfactor")->innerText());
    mHumanExperienceFactor =
        boost::lexical_cast<unsigned short int>(documentElement->getChildElement("humanexperiencefactor")->innerText());
    mHumanReproduceFactor =
        boost::lexical_cast<unsigned short int>(documentElement->getChildElement("humanreproducefactor")->innerText());
    mPovertyDismissFactor =
        boost::lexical_cast<unsigned short int>(documentElement->getChildElement("povertydismissfactor")->innerText());

    return true;
}

} // namespace Server

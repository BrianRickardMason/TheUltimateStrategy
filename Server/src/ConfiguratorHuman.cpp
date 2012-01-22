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

#include <Game/GameServer/Configuration/Configurator/Human/Human.hpp>
#include <Poco/AutoPtr.h>
#include <Poco/DOM/DOMParser.h>
#include <Poco/DOM/Element.h>
#include <Poco/DOM/NodeList.h>
#include <Server/include/ConfiguratorHuman.hpp>
#include <boost/lexical_cast.hpp>

namespace Server
{

ConfiguratorHuman::ConfiguratorHuman(
    IConfiguratorShrPtr const aConfigurator
)
    : mConfigurator(aConfigurator)
{
    configure();
}

bool ConfiguratorHuman::configure()
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

GameServer::Configuration::IHumanShrPtr ConfiguratorHuman::getHuman(
    GameServer::Configuration::IKey const aKey
) const
{
    // FIXME: Use find and provide the exception handling.
    return mHumans.at(aKey);
}

GameServer::Configuration::IHumanMap const & ConfiguratorHuman::getHumans() const
{
    return mHumans;
}

bool ConfiguratorHuman::loadXml()
{
    Poco::XML::DOMParser parser;

    std::string pathHumansXml =
        mConfigurator->getConfigurationPath() + mConfigurator->getConfigurationSelected() + "/Human/humans.xml";
    std::string pathCostsXml =
        mConfigurator->getConfigurationPath() + mConfigurator->getConfigurationSelected() + "/Human/costs.xml";
    std::string pathPlacesOfWorkXml =
          mConfigurator->getConfigurationPath() + mConfigurator->getConfigurationSelected() + "/Human/placesofwork.xml";
    std::string pathProductionXml =
        mConfigurator->getConfigurationPath() + mConfigurator->getConfigurationSelected() + "/Human/production.xml";
    std::string pathPropertiesXml =
        mConfigurator->getConfigurationPath() + mConfigurator->getConfigurationSelected() + "/Human/properties.xml";

    mHumansXml       = parser.parse(pathHumansXml);
    mCostsXml        = parser.parse(pathCostsXml);
    mPlacesOfWorkXml = parser.parse(pathPlacesOfWorkXml);
    mProductionXml   = parser.parse(pathProductionXml);
    mPropertiesXml   = parser.parse(pathPropertiesXml);

    return true;
}

bool ConfiguratorHuman::parseXml()
{
    // TODO: Add verification here.

    typedef GameServer::Configuration::IKey    IKey;
    typedef GameServer::Resource::Volume       Volume;
    typedef Poco::XML::Element *               Element;
    typedef Poco::AutoPtr<Poco::XML::NodeList> NodeList;

    Element documentElement = mHumansXml->documentElement();

    NodeList humans = documentElement->getElementsByTagName("human");

    for (int i = 0; i < humans->length(); ++i)
    {
        Element human = static_cast<Poco::XML::Element *>(humans->item(i));

        IKey                   const humanKey         = human->getChildElement("key")->innerText();
        std::string            const humanClass       = human->getChildElement("class")->innerText();
        std::string            const humanName        = human->getChildElement("name")->innerText();
        std::string            const humanExperience  = human->getChildElement("experience")->innerText();
        bool                         humanDismissable = false;
        bool                         humanEngageable  = false;
        unsigned int                 humanProduction  = 0;
        std::map<IKey, Volume>       humanCostsToDismiss;
        std::map<IKey, Volume>       humanCostsToEngage;
        std::map<IKey, Volume>       humanCostsToLive;
        IKey                         resourceProduced;
        IKey                         placeOfWork;

        // Get the costs.
        {
            NodeList referredHumans = mCostsXml->documentElement()->getElementsByTagName("human");

            for (int j = 0; j < referredHumans->length(); ++j)
            {
                Element referredHuman = static_cast<Poco::XML::Element *>(referredHumans->item(j));

                Element key = referredHuman->getChildElement("key");

                if (key->innerText() == humanKey)
                {
                    NodeList resources = referredHuman->getChildElement("dismiss")->getChildElement("resources")->
                        getElementsByTagName("resource");

                    for (int k = 0; k < resources->length(); ++k)
                    {
                        Element resource = static_cast<Poco::XML::Element *>(resources->item(k));
                        humanCostsToDismiss[resource->getChildElement("key")->innerText()] =
                            boost::lexical_cast<Volume>(resource->getChildElement("volume")->innerText());
                    }

                    resources = referredHuman->getChildElement("engage")->getChildElement("resources")->
                        getElementsByTagName("resource");

                    for (int k = 0; k < resources->length(); ++k)
                    {
                        Element resource = static_cast<Poco::XML::Element *>(resources->item(k));
                        humanCostsToEngage[resource->getChildElement("key")->innerText()] =
                            boost::lexical_cast<Volume>(resource->getChildElement("volume")->innerText());
                    }

                    resources = referredHuman->getChildElement("live")->getChildElement("resources")->
                        getElementsByTagName("resource");

                    for (int k = 0; k < resources->length(); ++k)
                    {
                        Element resource = static_cast<Poco::XML::Element *>(resources->item(k));
                        humanCostsToLive[resource->getChildElement("key")->innerText()] =
                            boost::lexical_cast<Volume>(resource->getChildElement("volume")->innerText());
                    }
                }
            }
        }

        // Get the place of work.
        {
            NodeList referredHumans = mPlacesOfWorkXml->documentElement()->getElementsByTagName("human");

            for (int j = 0; j < referredHumans->length(); ++j)
            {
                Element referredHuman = static_cast<Poco::XML::Element *>(referredHumans->item(j));

                Element key = referredHuman->getChildElement("key");

                if (key->innerText() == humanKey)
                {
                    placeOfWork = referredHuman->getChildElement("building")->getChildElement("key")->innerText();
                }
            }
        }

        // Get the production.
        {
            NodeList referredHumans = mProductionXml->documentElement()->getElementsByTagName("human");

            for (int j = 0; j < referredHumans->length(); ++j)
            {
                Element referredHuman = static_cast<Poco::XML::Element *>(referredHumans->item(j));

                Element key = referredHuman->getChildElement("key");

                if (key->innerText() == humanKey)
                {
                    resourceProduced = referredHuman->getChildElement("resource")->getChildElement("key")->innerText();
                }
            }
        }

        // Get the properties.
        {
            NodeList referredHumans = mPropertiesXml->documentElement()->getElementsByTagName("human");

            for (int j = 0; j < referredHumans->length(); ++j)
            {
                Element referredHuman = static_cast<Poco::XML::Element *>(referredHumans->item(j));

                Element key = referredHuman->getChildElement("key");

                if (key->innerText() == humanKey)
                {
                    humanDismissable =
                        (referredHuman->getChildElement("dismissable")->innerText() == "true") ? true : false;
                    humanEngageable =
                        (referredHuman->getChildElement("engageable")->innerText() == "true") ? true : false;
                    humanProduction =
                        boost::lexical_cast<unsigned int>(referredHuman->getChildElement("production")->innerText());
                }
            }
        }

        // Create the human.
        GameServer::Configuration::IHumanShrPtr createdHuman(
            new GameServer::Configuration::Human(
                    humanKey, humanClass, humanName, humanExperience, humanDismissable, humanEngageable,
                    humanProduction, humanCostsToDismiss, humanCostsToEngage, humanCostsToLive, resourceProduced,
                    placeOfWork
                )
        );

        mHumans.insert(std::make_pair(humanKey, createdHuman));
    }

    return true;
}

} // namespace Server

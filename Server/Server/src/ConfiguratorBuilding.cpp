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

#include <Game/GameServer/Configuration/Configurator/Building/Building.hpp>
#include <Poco/DOM/DOMParser.h>
#include <Poco/DOM/Element.h>
#include <Poco/DOM/NodeList.h>
#include <Server/Server/include/ConfiguratorBuilding.hpp>
#include <boost/lexical_cast.hpp>

namespace Server
{

ConfiguratorBuilding::ConfiguratorBuilding(
    IConfiguratorShrPtr const aConfigurator
)
    : mConfigurator(aConfigurator)
{
    configure();
}

bool ConfiguratorBuilding::configure()
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

GameServer::Configuration::IBuildingShrPtr ConfiguratorBuilding::getBuilding(
    GameServer::Configuration::IKey const a_key
) const
{
    // FIXME: Use find and provide the exception handling.
    return mBuildings.at(a_key);
}

GameServer::Configuration::IBuildingMap const & ConfiguratorBuilding::getBuildings() const
{
    return mBuildings;
}

bool ConfiguratorBuilding::loadXml()
{
    Poco::XML::DOMParser parser;

    std::string pathBuildingsXml =
        mConfigurator->getConfigurationPath() + mConfigurator->getConfigurationSelected() + "/Building/buildings.xml";
    std::string pathCostsXml =
        mConfigurator->getConfigurationPath() + mConfigurator->getConfigurationSelected() + "/Building/costs.xml";
    std::string pathHumansHostedXml =
          mConfigurator->getConfigurationPath()
        + mConfigurator->getConfigurationSelected()
        + "/Building/humanshosted.xml";
    std::string pathPropertiesXml =
        mConfigurator->getConfigurationPath() + mConfigurator->getConfigurationSelected() + "/Building/properties.xml";

    mBuildingsXml    = parser.parse(pathBuildingsXml);
    mCostsXml        = parser.parse(pathCostsXml);
    mHumansHostedXml = parser.parse(pathHumansHostedXml);
    mPropertiesXml   = parser.parse(pathPropertiesXml);

    return true;
}

bool ConfiguratorBuilding::parseXml()
{
    // TODO: Add verification here.

    typedef GameServer::Configuration::IKey IKey;
    typedef GameServer::Resource::Volume Volume;
    typedef Poco::XML::Element * Element;
    typedef Poco::XML::NodeList * NodeList;

    Element documentElement = mBuildingsXml->documentElement();

    NodeList buildings = documentElement->getElementsByTagName("building");

    for (int i = 0; i < buildings->length(); ++i)
    {
        Element building = static_cast<Poco::XML::Element *>(buildings->item(i));

        IKey                   const buildingKey      = building->getChildElement("key")->innerText();
        std::string            const buildingClass    = building->getChildElement("class")->innerText();
        std::string            const buildingName     = building->getChildElement("name")->innerText();
        unsigned int                 buildingCapacity = 0;
        std::map<IKey, Volume>       buildingCostsToBuild;
        std::map<IKey, Volume>       buildingCostsToDestroy;

        // Get the costs.
        {
            NodeList referredBuildings = mCostsXml->documentElement()->getElementsByTagName("building");

            for (int j = 0; j < referredBuildings->length(); ++j)
            {
                Element referredBuilding = static_cast<Poco::XML::Element *>(referredBuildings->item(j));

                Element key = referredBuilding->getChildElement("key");

                if (key->innerText() == buildingKey)
                {
                    NodeList resources = referredBuilding->getChildElement("build")->getChildElement("resources")->
                        getElementsByTagName("resource");

                    for (int k = 0; k < resources->length(); ++k)
                    {
                        Element resource = static_cast<Poco::XML::Element *>(resources->item(k));
                        buildingCostsToBuild[resource->getChildElement("key")->innerText()] =
                            boost::lexical_cast<Volume>(resource->getChildElement("volume")->innerText());
                    }

                    resources = referredBuilding->getChildElement("destroy")->getChildElement("resources")->
                        getElementsByTagName("resource");

                    for (int k = 0; k < resources->length(); ++k)
                    {
                        Element resource = static_cast<Poco::XML::Element *>(resources->item(k));
                        buildingCostsToDestroy[resource->getChildElement("key")->innerText()] =
                            boost::lexical_cast<Volume>(resource->getChildElement("volume")->innerText());
                    }
                }
            }
        }

        // Get the hosted humans.
        std::vector<IKey> hostedHumansVector;
        {
            NodeList referredBuildings = mHumansHostedXml->documentElement()->getElementsByTagName("building");

            for (int j = 0; j < referredBuildings->length(); ++j)
            {
                Element referredBuilding = static_cast<Poco::XML::Element *>(referredBuildings->item(j));

                Element key = referredBuilding->getChildElement("key");

                if (key->innerText() == buildingKey)
                {
                    NodeList hostedHumans = referredBuilding->getChildElement("humans")->getElementsByTagName("human");


                    for (int k = 0; k < hostedHumans->length(); ++k)
                    {
                        Element hostedHuman = static_cast<Poco::XML::Element *>(hostedHumans->item(k));
                        hostedHumansVector.push_back(hostedHuman->getChildElement("key")->innerText());
                    }
                }
            }
        }

        // Get the properties.
        {
            NodeList referredBuildings = mPropertiesXml->documentElement()->getElementsByTagName("building");

            for (int j = 0; j < referredBuildings->length(); ++j)
            {
                Element referredBuilding = static_cast<Poco::XML::Element *>(referredBuildings->item(j));

                Element key = referredBuilding->getChildElement("key");

                if (key->innerText() == buildingKey)
                {
                    buildingCapacity =
                        boost::lexical_cast<unsigned int>(referredBuilding->getChildElement("capacity")->innerText());
                }
            }
        }

        // Create the building.
        GameServer::Configuration::IBuildingShrPtr createdBuilding(
            new GameServer::Configuration::Building(
                    buildingKey, buildingClass, buildingName, buildingCapacity,
                    buildingCostsToBuild, buildingCostsToDestroy, hostedHumansVector
                )
        );

        mBuildings.insert(std::make_pair(buildingKey, createdBuilding));
    }

    return true;
}

} // namespace Server

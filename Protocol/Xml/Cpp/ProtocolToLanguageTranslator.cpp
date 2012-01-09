// Copyright (C) 2010, 2011 and 2012 Marcin Arkadiusz Skrobiranda.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with and without
// modification, are permitted provided that the following conditions
// are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
// 3. Neither the name of the project nor the names of its contributors
//    may be used to endorse and promote products derived from this software
//    without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS and IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE PROJECT and CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, and CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
// and SERVICES; LOSS OF USE, DATA, and PROFITS; and BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, and TORT (INCLUDING NEGLIGENCE and OTHERWISE) ARISING IN ANY WAY
// OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
// SUCH DAMAGE.

#include <Language/Interface/RequestBuilder.hpp>
#include <Poco/AutoPtr.h>
#include <Poco/DOM/Element.h>
#include <Protocol/Xml/Cpp/ProtocolToLanguageTranslator.hpp>
#include <boost/assert.hpp>
#include <boost/lexical_cast.hpp>

namespace TUSProtocol
{

TUSLanguage::ICommand::SingleHandle ProtocolToLanguageTranslator::translate(
    Message::SingleHandle a_message
) const
{
    typedef Poco::AutoPtr<Poco::XML::Element> Element;

    TUSLanguage::RequestBuilder request_builder;

    // Default values.
    unsigned short int id(0); // TODO: Verify the initialization!
    std::string login, password;

    Element message = a_message->documentElement();
    if (not message) throw std::exception();

    Element header = message->getChildElement("header");
    if (not header) throw std::exception();

    // Extract what you can.
    Element element_id = header->getChildElement("id");
    if (not element_id) throw std::exception();

    id = boost::lexical_cast<unsigned short int>(element_id->innerText().c_str());

    Element user = header->getChildElement("user");
    if (user)
    {
        Element element_login = user->getChildElement("login");
        Element element_password = user->getChildElement("password");
        if (not (element_login and element_password)) throw std::exception();

        login = element_login->innerText().c_str();
        password = element_password->innerText().c_str();
    }

    switch (id)
    {
        case TUSLanguage::ID_COMMAND_ECHO_REQUEST:
            return request_builder.buildEchoRequest();

        case TUSLanguage::ID_COMMAND_ERROR_REQUEST:
            return request_builder.buildErrorRequest();

        case TUSLanguage::ID_COMMAND_CREATE_LAND_REQUEST:
        {
            Element request = message->getChildElement("request");
            if (not request) throw std::exception();

            Element specific_request = request->getChildElement("create_land_request");
            if (not specific_request) throw std::exception();

            Element world_name = specific_request->getChildElement("world_name");
            Element land_name = specific_request->getChildElement("land_name");
            if (not (world_name and land_name)) throw std::exception();

            return request_builder.buildCreateLandRequest(
                       login,
                       password,
                       world_name->innerText().c_str(),
                       land_name->innerText().c_str()
                   );
        }

        case TUSLanguage::ID_COMMAND_DELETE_LAND_REQUEST:
        {
            Element request = message->getChildElement("request");
            if (not request) throw std::exception();

            Element specific_request = request->getChildElement("delete_land_request");
            if (not specific_request) throw std::exception();

            Element world_name = specific_request->getChildElement("world_name");
            Element land_name = specific_request->getChildElement("land_name");
            if (not (world_name and land_name)) throw std::exception();

            return request_builder.buildDeleteLandRequest(
                       login,
                       password,
                       land_name->innerText().c_str()
                   );
        }

        case TUSLanguage::ID_COMMAND_GET_LAND_REQUEST:
        {
            Element request = message->getChildElement("request");
            if (not request) throw std::exception();

            Element specific_request = request->getChildElement("get_land_request");
            if (not specific_request) throw std::exception();

            Element land_name = specific_request->getChildElement("land_name");
            if (not land_name) throw std::exception();

            return request_builder.buildGetLandRequest(
                       login,
                       password,
                       land_name->innerText().c_str()
                   );
        }

        case TUSLanguage::ID_COMMAND_GET_LANDS_REQUEST:
        {
            Element request = message->getChildElement("request");
            if (not request) throw std::exception();

            Element specific_request = request->getChildElement("get_lands_request");
            if (not specific_request) throw std::exception();

            return request_builder.buildGetLandsRequest(
                       login,
                       password
                   );
        }

        case TUSLanguage::ID_COMMAND_CREATE_SETTLEMENT_REQUEST:
        {
            Element request = message->getChildElement("request");
            if (not request) throw std::exception();

            Element specific_request = request->getChildElement("create_settlement_request");
            if (not specific_request) throw std::exception();

            Element land_name = specific_request->getChildElement("land_name");
            Element settlement_name = specific_request->getChildElement("settlement_name");
            if (not (land_name and settlement_name)) throw std::exception();

            return request_builder.buildCreateSettlementRequest(
                       login,
                       password,
                       land_name->innerText().c_str(),
                       settlement_name->innerText().c_str()
                   );
        }

        case TUSLanguage::ID_COMMAND_DELETE_SETTLEMENT_REQUEST:
        {
            Element request = message->getChildElement("request");
            if (not request) throw std::exception();

            Element specific_request = request->getChildElement("delete_settlement_request");
            if (not specific_request) throw std::exception();

            Element settlement_name = specific_request->getChildElement("settlement_name");
            if (not settlement_name) throw std::exception();

            return request_builder.buildDeleteSettlementRequest(
                       login,
                       password,
                       settlement_name->innerText().c_str()
                   );
        }

        case TUSLanguage::ID_COMMAND_GET_SETTLEMENT_REQUEST:
        {
            Element request = message->getChildElement("request");
            if (not request) throw std::exception();

            Element specific_request = request->getChildElement("get_settlement_request");
            if (not specific_request) throw std::exception();

            Element settlement_name = specific_request->getChildElement("settlement_name");
            if (not settlement_name) throw std::exception();

            return request_builder.buildGetSettlementRequest(
                       login,
                       password,
                       settlement_name->innerText().c_str()
                   );
        }

        case TUSLanguage::ID_COMMAND_GET_SETTLEMENTS_REQUEST:
        {
            Element request = message->getChildElement("request");
            if (not request) throw std::exception();

            Element specific_request = request->getChildElement("get_settlements_request");
            if (not specific_request) throw std::exception();

            Element land_name = specific_request->getChildElement("land_name");
            if (not land_name) throw std::exception();

            return request_builder.buildGetSettlementsRequest(
                       login,
                       password,
                       land_name->innerText().c_str()
                   );
        }

        case TUSLanguage::ID_COMMAND_BUILD_BUILDING_REQUEST:
        {
            Element request = message->getChildElement("request");
            if (not request) throw std::exception();

            Element specific_request = request->getChildElement("build_building_request");
            if (not specific_request) throw std::exception();

            Element idholderclass = specific_request->getChildElement("idholderclass");
            Element holder_name = specific_request->getChildElement("holder_name");
            Element buildingkey = specific_request->getChildElement("buildingkey");
            Element volume = specific_request->getChildElement("volume");
            if (not (idholderclass and holder_name and buildingkey and volume)) throw std::exception();

            return request_builder.buildBuildBuildingRequest(
                       login,
                       password,
                       idholderclass->innerText().c_str(),
                       holder_name->innerText().c_str(),
                       buildingkey->innerText().c_str(),
                       volume->innerText().c_str()
                   );
        }

        case TUSLanguage::ID_COMMAND_DESTROY_BUILDING_REQUEST:
        {
            Element request = message->getChildElement("request");
            if (not request) throw std::exception();

            Element specific_request = request->getChildElement("destroy_building_request");
            if (not specific_request) throw std::exception();

            Element idholderclass = specific_request->getChildElement("idholderclass");
            Element holder_name = specific_request->getChildElement("holder_name");
            Element buildingkey = specific_request->getChildElement("buildingkey");
            Element volume = specific_request->getChildElement("volume");
            if (not (idholderclass and holder_name and buildingkey and volume)) throw std::exception();

            return request_builder.buildDestroyBuildingRequest(
                       login,
                       password,
                       idholderclass->innerText().c_str(),
                       holder_name->innerText().c_str(),
                       buildingkey->innerText().c_str(),
                       volume->innerText().c_str()
                   );
        }

        case TUSLanguage::ID_COMMAND_GET_BUILDING_REQUEST:
        {
            Element request = message->getChildElement("request");
            if (not request) throw std::exception();

            Element specific_request = request->getChildElement("get_building_request");
            if (not specific_request) throw std::exception();

            Element idholderclass = specific_request->getChildElement("idholderclass");
            Element holder_name = specific_request->getChildElement("holder_name");
            Element buildingkey = specific_request->getChildElement("buildingkey");
            if (not (idholderclass and holder_name and buildingkey)) throw std::exception();

            return request_builder.buildGetBuildingRequest(
                       login,
                       password,
                       idholderclass->innerText().c_str(),
                       holder_name->innerText().c_str(),
                       buildingkey->innerText().c_str()
                   );
        }

        case TUSLanguage::ID_COMMAND_GET_BUILDINGS_REQUEST:
        {
            Element request = message->getChildElement("request");
            if (not request) throw std::exception();

            Element specific_request = request->getChildElement("get_buildings_request");
            if (not specific_request) throw std::exception();

            Element idholderclass = specific_request->getChildElement("idholderclass");
            Element holder_name = specific_request->getChildElement("holder_name");
            if (not (idholderclass and holder_name)) throw std::exception();

            return request_builder.buildGetBuildingsRequest(
                       login,
                       password,
                       idholderclass->innerText().c_str(),
                       holder_name->innerText().c_str()
                   );
        }

        case TUSLanguage::ID_COMMAND_DISMISS_HUMAN_REQUEST:
        {
            Element request = message->getChildElement("request");
            if (not request) throw std::exception();

            Element specific_request = request->getChildElement("dismiss_human_request");
            if (not specific_request) throw std::exception();

            Element idholderclass = specific_request->getChildElement("idholderclass");
            Element holder_name = specific_request->getChildElement("holder_name");
            Element humankey = specific_request->getChildElement("humankey");
            Element volume = specific_request->getChildElement("volume");
            if (not (idholderclass and holder_name and humankey and volume)) throw std::exception();

            return request_builder.buildDismissHumanRequest(
                       login,
                       password,
                       idholderclass->innerText().c_str(),
                       holder_name->innerText().c_str(),
                       humankey->innerText().c_str(),
                       volume->innerText().c_str()
                   );
        }

        case TUSLanguage::ID_COMMAND_ENGAGE_HUMAN_REQUEST:
        {
            Element request = message->getChildElement("request");
            if (not request) throw std::exception();

            Element specific_request = request->getChildElement("engage_human_request");
            if (not specific_request) throw std::exception();

            Element idholderclass = specific_request->getChildElement("idholderclass");
            Element holder_name = specific_request->getChildElement("holder_name");
            Element humankey = specific_request->getChildElement("humankey");
            Element volume = specific_request->getChildElement("volume");
            if (not (idholderclass and holder_name and humankey and volume)) throw std::exception();

            return request_builder.buildEngageHumanRequest(
                       login,
                       password,
                       idholderclass->innerText().c_str(),
                       holder_name->innerText().c_str(),
                       humankey->innerText().c_str(),
                       volume->innerText().c_str()
                   );
        }

        case TUSLanguage::ID_COMMAND_GET_HUMAN_REQUEST:
        {
            Element request = message->getChildElement("request");
            if (not request) throw std::exception();

            Element specific_request = request->getChildElement("get_human_request");
            if (not specific_request) throw std::exception();

            Element idholderclass = specific_request->getChildElement("idholderclass");
            Element holder_name = specific_request->getChildElement("holder_name");
            Element humankey = specific_request->getChildElement("humankey");
            if (not (idholderclass and holder_name and humankey)) throw std::exception();

            return request_builder.buildGetHumanRequest(
                       login,
                       password,
                       idholderclass->innerText().c_str(),
                       holder_name->innerText().c_str(),
                       humankey->innerText().c_str()
                   );
        }

        case TUSLanguage::ID_COMMAND_GET_HUMANS_REQUEST:
        {
            Element request = message->getChildElement("request");
            if (not request) throw std::exception();

            Element specific_request = request->getChildElement("get_humans_request");
            if (not specific_request) throw std::exception();

            Element idholderclass = specific_request->getChildElement("idholderclass");
            Element holder_name = specific_request->getChildElement("holder_name");
            if (not (idholderclass and holder_name)) throw std::exception();

            return request_builder.buildGetHumansRequest(
                       login,
                       password,
                       idholderclass->innerText().c_str(),
                       holder_name->innerText().c_str()
                   );
        }

        case TUSLanguage::ID_COMMAND_GET_RESOURCE_REQUEST:
        {
            Element request = message->getChildElement("request");
            if (not request) throw std::exception();

            Element specific_request = request->getChildElement("get_resource_request");
            if (not specific_request) throw std::exception();

            Element idholderclass = specific_request->getChildElement("idholderclass");
            Element holder_name = specific_request->getChildElement("holder_name");
            Element resourcekey = specific_request->getChildElement("resourcekey");
            if (not (idholderclass and holder_name and resourcekey)) throw std::exception();

            return request_builder.buildGetHumanRequest(
                       login,
                       password,
                       idholderclass->innerText().c_str(),
                       holder_name->innerText().c_str(),
                       resourcekey->innerText().c_str()
                   );
        }

        case TUSLanguage::ID_COMMAND_GET_RESOURCES_REQUEST:
        {
            Element request = message->getChildElement("request");
            if (not request) throw std::exception();

            Element specific_request = request->getChildElement("get_resources_request");
            if (not specific_request) throw std::exception();

            Element idholderclass = specific_request->getChildElement("idholderclass");
            Element holder_name = specific_request->getChildElement("holder_name");
            if (not (idholderclass and holder_name)) throw std::exception();

            return request_builder.buildGetResourcesRequest(
                       login,
                       password,
                       idholderclass->innerText().c_str(),
                       holder_name->innerText().c_str()
                   );
        }

        case TUSLanguage::ID_COMMAND_CREATE_USER_REQUEST:
        {
            Element request = message->getChildElement("request");
            if (not request) throw std::exception();

            Element specific_request = request->getChildElement("create_user_request");
            if (not specific_request) throw std::exception();

            Element login = specific_request->getChildElement("login");
            Element password = specific_request->getChildElement("password");
            if (not (login and password)) throw std::exception();

            return request_builder.buildCreateUserRequest(
                       login->innerText().c_str(),
                       password->innerText().c_str()
                   );
        }

        case TUSLanguage::ID_COMMAND_CREATE_WORLD_REQUEST:
        {
            Element request = message->getChildElement("request");
            if (not request) throw std::exception();

            Element specific_request = request->getChildElement("create_world_request");
            if (not specific_request) throw std::exception();

            Element world_name = specific_request->getChildElement("world_name");
            if (not world_name) throw std::exception();

            return request_builder.buildCreateWorldRequest(
                       login,
                       password,
                       world_name->innerText().c_str()
                   );
        }

        case TUSLanguage::ID_COMMAND_CREATE_EPOCH_REQUEST:
        {
            Element request = message->getChildElement("request");
            if (not request) throw std::exception();

            Element specific_request = request->getChildElement("create_epoch_request");
            if (not specific_request) throw std::exception();

            Element world_name = specific_request->getChildElement("world_name");
            Element epoch_name = specific_request->getChildElement("epoch_name");
            if (not (world_name and epoch_name)) throw std::exception();

            return request_builder.buildCreateEpochRequest(
                       login,
                       password,
                       world_name->innerText().c_str(),
                       epoch_name->innerText().c_str()
                   );
        }

        case TUSLanguage::ID_COMMAND_DELETE_EPOCH_REQUEST:
        {
            Element request = message->getChildElement("request");
            if (not request) throw std::exception();

            Element specific_request = request->getChildElement("delete_epoch_request");
            if (not specific_request) throw std::exception();

            Element world_name = specific_request->getChildElement("world_name");
            if (not world_name) throw std::exception();

            return request_builder.buildDeleteEpochRequest(
                       login,
                       password,
                       world_name->innerText().c_str()
                   );
        }

        case TUSLanguage::ID_COMMAND_ACTIVATE_EPOCH_REQUEST:
        {
            Element request = message->getChildElement("request");
            if (not request) throw std::exception();

            Element specific_request = request->getChildElement("activate_epoch_request");
            if (not specific_request) throw std::exception();

            Element world_name = specific_request->getChildElement("world_name");
            if (not world_name) throw std::exception();

            return request_builder.buildActivateEpochRequest(
                       login,
                       password,
                       world_name->innerText().c_str()
                   );
        }

        case TUSLanguage::ID_COMMAND_DEACTIVATE_EPOCH_REQUEST:
        {
            Element request = message->getChildElement("request");
            if (not request) throw std::exception();

            Element specific_request = request->getChildElement("deactivate_epoch_request");
            if (not specific_request) throw std::exception();

            Element world_name = specific_request->getChildElement("world_name");
            if (not world_name) throw std::exception();

            return request_builder.buildDeactivateEpochRequest(
                       login,
                       password,
                       world_name->innerText().c_str()
                   );
        }

        case TUSLanguage::ID_COMMAND_FINISH_EPOCH_REQUEST:
        {
            Element request = message->getChildElement("request");
            if (not request) throw std::exception();

            Element specific_request = request->getChildElement("finish_epoch_request");
            if (not specific_request) throw std::exception();

            Element world_name = specific_request->getChildElement("world_name");
            if (not world_name) throw std::exception();

            return request_builder.buildFinishEpochRequest(
                       login,
                       password,
                       world_name->innerText().c_str()
                   );
        }

        case TUSLanguage::ID_COMMAND_TICK_EPOCH_REQUEST:
        {
            Element request = message->getChildElement("request");
            if (not request) throw std::exception();

            Element specific_request = request->getChildElement("tick_epoch_request");
            if (not specific_request) throw std::exception();

            Element world_name = specific_request->getChildElement("world_name");
            if (not world_name) throw std::exception();

            return request_builder.buildTickEpochRequest(
                       login,
                       password,
                       world_name->innerText().c_str()
                   );
        }

        case TUSLanguage::ID_COMMAND_GET_EPOCH_REQUEST:
        {
            Element request = message->getChildElement("request");
            if (not request) throw std::exception();

            Element specific_request = request->getChildElement("get_epoch_request");
            if (not specific_request) throw std::exception();

            Element world_name = specific_request->getChildElement("world_name");
            if (not world_name) throw std::exception();

            return request_builder.buildGetEpochRequest(
                       login,
                       password,
                       world_name->innerText().c_str()
                   );
        }

        case TUSLanguage::ID_COMMAND_TRANSPORT_HUMAN_REQUEST:
        {
            Element request = message->getChildElement("request");
            if (not request) throw std::exception();

            Element specific_request = request->getChildElement("transport_human_request");
            if (not specific_request) throw std::exception();

            Element settlement_name_source = specific_request->getChildElement("settlement_name_source");
            Element settlement_name_destination = specific_request->getChildElement("settlement_name_destination");
            Element humankey = specific_request->getChildElement("humankey");
            Element volume = specific_request->getChildElement("volume");

            if (not (settlement_name_source and settlement_name_destination and humankey and volume))
                throw std::exception();

            return request_builder.buildTransportHumanRequest(
                       login,
                       password,
                       settlement_name_source->innerText().c_str(),
                       settlement_name_destination->innerText().c_str(),
                       humankey->innerText().c_str(),
                       volume->innerText().c_str()
                   );
        }

        case TUSLanguage::ID_COMMAND_TRANSPORT_RESOURCE_REQUEST:
        {
            Element request = message->getChildElement("request");
            if (not request) throw std::exception();

            Element specific_request = request->getChildElement("transport_resource_request");
            if (not specific_request) throw std::exception();

            Element settlement_name_source = specific_request->getChildElement("settlement_name_source");
            Element settlement_name_destination = specific_request->getChildElement("settlement_name_destination");
            Element resourcekey = specific_request->getChildElement("resourcekey");
            Element volume = specific_request->getChildElement("volume");

            if (not (settlement_name_source and settlement_name_destination and resourcekey and volume))
                throw std::exception();

            return request_builder.buildTransportResourceRequest(
                       login,
                       password,
                       settlement_name_source->innerText().c_str(),
                       settlement_name_destination->innerText().c_str(),
                       resourcekey->innerText().c_str(),
                       volume->innerText().c_str()
                   );
        }

        default:
            BOOST_ASSERT_MSG(false, "Invalid command ID.");
    }
}

} // namespace TUSProtocol

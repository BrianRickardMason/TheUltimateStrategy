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

#include <Language/Interface/ReplyBuilder.hpp>
#include <Language/Interface/RequestBuilder.hpp>
#include <Poco/AutoPtr.h>
#include <Poco/DOM/Element.h>
#include <Poco/DOM/ElementsByTagNameList.h>
#include <Protocol/Xml/Cpp/ProtocolToLanguageTranslator.hpp>
#include <boost/assert.hpp>
#include <boost/lexical_cast.hpp>

namespace TUSProtocol
{

// TODO: Add UTs for both translators.

TUSLanguage::ICommand::SingleHandle ProtocolToLanguageTranslator::translate(
    Message::SingleHandle a_message
) const
{
    typedef Poco::AutoPtr<Poco::XML::Element> Element;

    TUSLanguage::RequestBuilder request_builder;
    TUSLanguage::ReplyBuilder reply_builder;

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

    id = boost::lexical_cast<unsigned short int>(element_id->innerText());

    Element user = header->getChildElement("user");
    if (user)
    {
        Element element_login = user->getChildElement("login");
        Element element_password = user->getChildElement("password");
        if (not (element_login and element_password)) throw std::exception();

        login = element_login->innerText();
        password = element_password->innerText();
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
                       world_name->innerText(),
                       land_name->innerText()
                   );
        }

        case TUSLanguage::ID_COMMAND_DELETE_LAND_REQUEST:
        {
            Element request = message->getChildElement("request");
            if (not request) throw std::exception();

            Element specific_request = request->getChildElement("delete_land_request");
            if (not specific_request) throw std::exception();

            Element land_name = specific_request->getChildElement("land_name");
            if (not (land_name)) throw std::exception();

            return request_builder.buildDeleteLandRequest(
                       login,
                       password,
                       land_name->innerText()
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
                       land_name->innerText()
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
                       land_name->innerText(),
                       settlement_name->innerText()
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
                       settlement_name->innerText()
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
                       settlement_name->innerText()
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
                       land_name->innerText()
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
                       idholderclass->innerText(),
                       holder_name->innerText(),
                       buildingkey->innerText(),
                       volume->innerText()
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
                       idholderclass->innerText(),
                       holder_name->innerText(),
                       buildingkey->innerText(),
                       volume->innerText()
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
                       idholderclass->innerText(),
                       holder_name->innerText(),
                       buildingkey->innerText()
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
                       idholderclass->innerText(),
                       holder_name->innerText()
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
                       idholderclass->innerText(),
                       holder_name->innerText(),
                       humankey->innerText(),
                       volume->innerText()
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
                       idholderclass->innerText(),
                       holder_name->innerText(),
                       humankey->innerText(),
                       volume->innerText()
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
                       idholderclass->innerText(),
                       holder_name->innerText(),
                       humankey->innerText()
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
                       idholderclass->innerText(),
                       holder_name->innerText()
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

            return request_builder.buildGetResourceRequest(
                       login,
                       password,
                       idholderclass->innerText(),
                       holder_name->innerText(),
                       resourcekey->innerText()
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
                       idholderclass->innerText(),
                       holder_name->innerText()
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
                       login->innerText(),
                       password->innerText()
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
                       world_name->innerText()
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
                       world_name->innerText(),
                       epoch_name->innerText()
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
                       world_name->innerText()
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
                       world_name->innerText()
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
                       world_name->innerText()
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
                       world_name->innerText()
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
                       world_name->innerText()
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
                       world_name->innerText()
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
                       settlement_name_source->innerText(),
                       settlement_name_destination->innerText(),
                       humankey->innerText(),
                       volume->innerText()
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
                       settlement_name_source->innerText(),
                       settlement_name_destination->innerText(),
                       resourcekey->innerText(),
                       volume->innerText()
                   );
        }

        case TUSLanguage::ID_COMMAND_ECHO_REPLY:
        {
            Element reply = message->getChildElement("reply");
            if (not reply) throw std::exception();

            Element code = reply->getChildElement("code");
            if (not code) throw std::exception();

            Element specific_reply = reply->getChildElement("echo_reply");
            if (not specific_reply) throw std::exception();

            return reply_builder.buildEchoReply(boost::lexical_cast<unsigned short int>(code->innerText()));
        }

        case TUSLanguage::ID_COMMAND_ERROR_REPLY:
        {
            Element reply = message->getChildElement("reply");
            if (not reply) throw std::exception();

            Element code = reply->getChildElement("code");
            if (not code) throw std::exception();

            Element specific_reply = reply->getChildElement("error_reply");
            if (not specific_reply) throw std::exception();

            return reply_builder.buildErrorReply(boost::lexical_cast<unsigned short int>(code->innerText()));
        }

        case TUSLanguage::ID_COMMAND_CREATE_LAND_REPLY:
        {
            Element reply = message->getChildElement("reply");
            if (not reply) throw std::exception();

            Element code = reply->getChildElement("code");
            Element message = reply->getChildElement("message");
            if (not (code and message)) throw std::exception();

            Element specific_reply = reply->getChildElement("create_land_reply");
            if (not specific_reply) throw std::exception();

            return reply_builder.buildCreateLandReply(
                       boost::lexical_cast<unsigned short int>(code->innerText()),
                       message->innerText()
                   );
        }

        case TUSLanguage::ID_COMMAND_DELETE_LAND_REPLY:
        {
            Element reply = message->getChildElement("reply");
            if (not reply) throw std::exception();

            Element code = reply->getChildElement("code");
            Element message = reply->getChildElement("message");
            if (not (code and message)) throw std::exception();

            Element specific_reply = reply->getChildElement("delete_land_reply");
            if (not specific_reply) throw std::exception();

            return reply_builder.buildDeleteLandReply(
                       boost::lexical_cast<unsigned short int>(code->innerText()),
                       message->innerText()
                   );
        }

        case TUSLanguage::ID_COMMAND_GET_LAND_REPLY:
        {
            Element reply = message->getChildElement("reply");
            if (not reply) throw std::exception();

            Element code = reply->getChildElement("code");
            Element message = reply->getChildElement("message");
            if (not (code and message)) throw std::exception();

            Element specific_reply = reply->getChildElement("get_land_reply");
            if (not specific_reply) throw std::exception();

            Element land = specific_reply->getChildElement("land");
            if (not land) throw std::exception();

            Element login = land->getChildElement("login");
            Element world_name = land->getChildElement("world_name");
            Element land_name = land->getChildElement("land_name");
            Element granted = land->getChildElement("granted");
            if (not (login and world_name and land_name and granted)) throw std::exception();

            TUSLanguage::ICommand::Object object;
            object.insert(std::make_pair("login", login->innerText()));
            object.insert(std::make_pair("world_name", world_name->innerText()));
            object.insert(std::make_pair("land_name", land_name->innerText()));
            object.insert(std::make_pair("granted", granted->innerText()));

            return reply_builder.buildGetLandReply(
                       boost::lexical_cast<unsigned short int>(code->innerText()),
                       message->innerText(),
                       object
                   );
        }

        case TUSLanguage::ID_COMMAND_GET_LANDS_REPLY:
        {
            Element reply = message->getChildElement("reply");
            if (not reply) throw std::exception();

            Element code = reply->getChildElement("code");
            Element message = reply->getChildElement("message");
            if (not (code and message)) throw std::exception();

            Element specific_reply = reply->getChildElement("get_lands_reply");
            if (not specific_reply) throw std::exception();

            Element get_lands_reply = specific_reply->getChildElement("get_lands_reply");
            if (not get_lands_reply) throw std::exception();

            Element lands = get_lands_reply->getChildElement("lands");
            if (not lands) throw std::exception();

            Poco::AutoPtr<Poco::XML::NodeList> elements = lands->getElementsByTagName("land");

            TUSLanguage::ICommand::Objects objects;

            for (int i = 0; i < elements->length(); ++i)
            {
                Element land = static_cast<Poco::XML::Element*>(elements->item(i));

                Element login = land->getChildElement("login");
                Element world_name = land->getChildElement("world_name");
                Element land_name = land->getChildElement("land_name");
                Element granted = land->getChildElement("granted");
                if (not (login and world_name and land_name and granted)) throw std::exception();

                TUSLanguage::ICommand::Object object;
                object.insert(std::make_pair("login", login->innerText()));
                object.insert(std::make_pair("world_name", world_name->innerText()));
                object.insert(std::make_pair("land_name", land_name->innerText()));
                object.insert(std::make_pair("granted", granted->innerText()));

                objects.push_back(object);
            }

            return reply_builder.buildGetLandsReply(
                       boost::lexical_cast<unsigned short int>(code->innerText()),
                       message->innerText(),
                       objects
                   );
        }

        case TUSLanguage::ID_COMMAND_CREATE_SETTLEMENT_REPLY:
        {
            Element reply = message->getChildElement("reply");
            if (not reply) throw std::exception();

            Element code = reply->getChildElement("code");
            Element message = reply->getChildElement("message");
            if (not (code and message)) throw std::exception();

            Element specific_reply = reply->getChildElement("create_settlement_reply");
            if (not specific_reply) throw std::exception();

            return reply_builder.buildCreateSettlementReply(
                       boost::lexical_cast<unsigned short int>(code->innerText()),
                       message->innerText()
                   );
        }

        case TUSLanguage::ID_COMMAND_DELETE_SETTLEMENT_REPLY:
        {
            Element reply = message->getChildElement("reply");
            if (not reply) throw std::exception();

            Element code = reply->getChildElement("code");
            Element message = reply->getChildElement("message");
            if (not (code and message)) throw std::exception();

            Element specific_reply = reply->getChildElement("delete_settlement_reply");
            if (not specific_reply) throw std::exception();

            return reply_builder.buildDeleteSettlementReply(
                       boost::lexical_cast<unsigned short int>(code->innerText()),
                       message->innerText()
                   );
        }

        case TUSLanguage::ID_COMMAND_GET_SETTLEMENT_REPLY:
        {
            Element reply = message->getChildElement("reply");
            if (not reply) throw std::exception();

            Element code = reply->getChildElement("code");
            Element message = reply->getChildElement("message");
            if (not (code and message)) throw std::exception();

            Element specific_reply = reply->getChildElement("get_settlement_reply");
            if (not specific_reply) throw std::exception();

            Element settlement = specific_reply->getChildElement("settlement");
            if (not settlement) throw std::exception();

            Element land_name = settlement->getChildElement("land_name");
            Element settlement_name = settlement->getChildElement("settlement_name");
            if (not (land_name and settlement_name)) throw std::exception();

            TUSLanguage::ICommand::Object object;
            object.insert(std::make_pair("land_name", land_name->innerText()));
            object.insert(std::make_pair("settlement_name", settlement_name->innerText()));

            return reply_builder.buildGetSettlementReply(
                       boost::lexical_cast<unsigned short int>(code->innerText()),
                       message->innerText(),
                       object
                   );
        }

        case TUSLanguage::ID_COMMAND_GET_SETTLEMENTS_REPLY:
        {
            Element reply = message->getChildElement("reply");
            if (not reply) throw std::exception();

            Element code = reply->getChildElement("code");
            Element message = reply->getChildElement("message");
            if (not (code and message)) throw std::exception();

            Element specific_reply = reply->getChildElement("get_settlements_reply");
            if (not specific_reply) throw std::exception();

            Element get_settlements_reply = specific_reply->getChildElement("get_settlements_reply");
            if (not get_settlements_reply) throw std::exception();

            Element settlements = get_settlements_reply->getChildElement("settlements");
            if (not settlements) throw std::exception();

            Poco::AutoPtr<Poco::XML::NodeList> elements = settlements->getElementsByTagName("settlement");

            TUSLanguage::ICommand::Objects objects;

            for (int i = 0; i < elements->length(); ++i)
            {
                Element settlement = static_cast<Poco::XML::Element*>(elements->item(i));

                Element land_name = settlement->getChildElement("land_name");
                Element settlement_name = settlement->getChildElement("settlement_name");
                if (not (land_name and settlement_name)) throw std::exception();

                TUSLanguage::ICommand::Object object;
                object.insert(std::make_pair("land_name", land_name->innerText()));
                object.insert(std::make_pair("settlement_name", settlement_name->innerText()));

                objects.push_back(object);
            }

            return reply_builder.buildGetSettlementsReply(
                       boost::lexical_cast<unsigned short int>(code->innerText()),
                       message->innerText(),
                       objects
                   );
        }

        case TUSLanguage::ID_COMMAND_BUILD_BUILDING_REPLY:
        {
            Element reply = message->getChildElement("reply");
            if (not reply) throw std::exception();

            Element code = reply->getChildElement("code");
            Element message = reply->getChildElement("message");
            if (not (code and message)) throw std::exception();

            Element specific_reply = reply->getChildElement("build_building_reply");
            if (not specific_reply) throw std::exception();

            return reply_builder.buildBuildBuildingReply(
                       boost::lexical_cast<unsigned short int>(code->innerText()),
                       message->innerText()
                   );
        }

        case TUSLanguage::ID_COMMAND_DESTROY_BUILDING_REPLY:
        {
            Element reply = message->getChildElement("reply");
            if (not reply) throw std::exception();

            Element code = reply->getChildElement("code");
            Element message = reply->getChildElement("message");
            if (not (code and message)) throw std::exception();

            Element specific_reply = reply->getChildElement("destroy_building_reply");
            if (not specific_reply) throw std::exception();

            return reply_builder.buildDestroyBuildingReply(
                       boost::lexical_cast<unsigned short int>(code->innerText()),
                       message->innerText()
                   );
        }

        case TUSLanguage::ID_COMMAND_GET_BUILDING_REPLY:
        {
            Element reply = message->getChildElement("reply");
            if (not reply) throw std::exception();

            Element code = reply->getChildElement("code");
            Element message = reply->getChildElement("message");
            if (not (code and message)) throw std::exception();

            Element specific_reply = reply->getChildElement("get_building_reply");
            if (not specific_reply) throw std::exception();

            Element get_building_reply = specific_reply->getChildElement("get_building_reply");
            if (not get_building_reply) throw std::exception();

            Element building = get_building_reply->getChildElement("building");
            if (not building) throw std::exception();

            Element buildingclass = building->getChildElement("buildingclass");
            Element buildingname = building->getChildElement("buildingname");
            Element volume = building->getChildElement("volume");
            if (not (buildingclass and buildingname and volume)) throw std::exception();

            TUSLanguage::ICommand::Object object;
            object.insert(std::make_pair("buildingclass", buildingclass->innerText()));
            object.insert(std::make_pair("buildingname", buildingname->innerText()));
            object.insert(std::make_pair("volume", volume->innerText()));

            return reply_builder.buildGetBuildingReply(
                       boost::lexical_cast<unsigned short int>(code->innerText()),
                       message->innerText(),
                       object
                   );
        }

        case TUSLanguage::ID_COMMAND_GET_BUILDINGS_REPLY:
        {
            Element reply = message->getChildElement("reply");
            if (not reply) throw std::exception();

            Element code = reply->getChildElement("code");
            Element message = reply->getChildElement("message");
            if (not (code and message)) throw std::exception();

            Element specific_reply = reply->getChildElement("get_buildings_reply");
            if (not specific_reply) throw std::exception();

            Element get_buildings_reply = specific_reply->getChildElement("get_buildings_reply");
            if (not get_buildings_reply) throw std::exception();

            Element buildings = get_buildings_reply->getChildElement("buildings");
            if (not buildings) throw std::exception();

            Poco::AutoPtr<Poco::XML::NodeList> elements = buildings->getElementsByTagName("building");

            TUSLanguage::ICommand::Objects objects;

            for (int i = 0; i < elements->length(); ++i)
            {
                Element building = static_cast<Poco::XML::Element*>(elements->item(i));

                Element buildingclass = building->getChildElement("buildingclass");
                Element buildingname = building->getChildElement("buildingname");
                Element volume = building->getChildElement("volume");
                if (not (buildingclass and buildingname and volume)) throw std::exception();

                TUSLanguage::ICommand::Object object;
                object.insert(std::make_pair("buildingclass", buildingclass->innerText()));
                object.insert(std::make_pair("buildingname", buildingname->innerText()));
                object.insert(std::make_pair("volume", volume->innerText()));

                objects.push_back(object);
            }

            return reply_builder.buildGetBuildingsReply(
                       boost::lexical_cast<unsigned short int>(code->innerText()),
                       message->innerText(),
                       objects
                   );
        }

        case TUSLanguage::ID_COMMAND_DISMISS_HUMAN_REPLY:
        {
            Element reply = message->getChildElement("reply");
            if (not reply) throw std::exception();

            Element code = reply->getChildElement("code");
            Element message = reply->getChildElement("message");
            if (not (code and message)) throw std::exception();

            Element specific_reply = reply->getChildElement("dismiss_human_reply");
            if (not specific_reply) throw std::exception();

            return reply_builder.buildDismissHumanReply(
                       boost::lexical_cast<unsigned short int>(code->innerText()),
                       message->innerText()
                   );
        }

        case TUSLanguage::ID_COMMAND_ENGAGE_HUMAN_REPLY:
        {
            Element reply = message->getChildElement("reply");
            if (not reply) throw std::exception();

            Element code = reply->getChildElement("code");
            Element message = reply->getChildElement("message");
            if (not (code and message)) throw std::exception();

            Element specific_reply = reply->getChildElement("engage_human_reply");
            if (not specific_reply) throw std::exception();

            return reply_builder.buildEngageHumanReply(
                       boost::lexical_cast<unsigned short int>(code->innerText()),
                       message->innerText()
                   );
        }

        case TUSLanguage::ID_COMMAND_GET_HUMAN_REPLY:
        {
            Element reply = message->getChildElement("reply");
            if (not reply) throw std::exception();

            Element code = reply->getChildElement("code");
            Element message = reply->getChildElement("message");
            if (not (code and message)) throw std::exception();

            Element specific_reply = reply->getChildElement("get_human_reply");
            if (not specific_reply) throw std::exception();

            Element get_human_reply = specific_reply->getChildElement("get_human_reply");
            if (not get_human_reply) throw std::exception();

            Element human = get_human_reply->getChildElement("human");
            if (not human) throw std::exception();

            Element humanclass = human->getChildElement("humanclass");
            Element humanname = human->getChildElement("humanname");
            Element experience = human->getChildElement("experience");
            Element volume = human->getChildElement("volume");
            if (not (humanclass and humanname and experience and volume)) throw std::exception();

            TUSLanguage::ICommand::Object object;
            object.insert(std::make_pair("humanclass", humanclass->innerText()));
            object.insert(std::make_pair("humanname", humanname->innerText()));
            object.insert(std::make_pair("experience", experience->innerText()));
            object.insert(std::make_pair("volume", volume->innerText()));

            return reply_builder.buildGetHumanReply(
                       boost::lexical_cast<unsigned short int>(code->innerText()),
                       message->innerText(),
                       object
                   );
        }

        case TUSLanguage::ID_COMMAND_GET_HUMANS_REPLY:
        {
            Element reply = message->getChildElement("reply");
            if (not reply) throw std::exception();

            Element code = reply->getChildElement("code");
            Element message = reply->getChildElement("message");
            if (not (code and message)) throw std::exception();

            Element specific_reply = reply->getChildElement("get_humans_reply");
            if (not specific_reply) throw std::exception();

            Element get_humans_reply = specific_reply->getChildElement("get_humans_reply");
            if (not get_humans_reply) throw std::exception();

            Element humans = get_humans_reply->getChildElement("humans");
            if (not humans) throw std::exception();

            Poco::AutoPtr<Poco::XML::NodeList> elements = humans->getElementsByTagName("human");

            TUSLanguage::ICommand::Objects objects;

            for (int i = 0; i < elements->length(); ++i)
            {
                Element human = static_cast<Poco::XML::Element*>(elements->item(i));

                Element humanclass = human->getChildElement("humanclass");
                Element humanname = human->getChildElement("humanname");
                Element experience = human->getChildElement("experience");
                Element volume = human->getChildElement("volume");
                if (not (humanclass and humanname and experience and volume)) throw std::exception();

                TUSLanguage::ICommand::Object object;
                object.insert(std::make_pair("humanclass", humanclass->innerText()));
                object.insert(std::make_pair("humanname", humanname->innerText()));
                object.insert(std::make_pair("experience", experience->innerText()));
                object.insert(std::make_pair("volume", volume->innerText()));

                objects.push_back(object);
            }

            return reply_builder.buildGetHumansReply(
                       boost::lexical_cast<unsigned short int>(code->innerText()),
                       message->innerText(),
                       objects
                   );
        }

        case TUSLanguage::ID_COMMAND_GET_RESOURCE_REPLY:
        {
            Element reply = message->getChildElement("reply");
            if (not reply) throw std::exception();

            Element code = reply->getChildElement("code");
            Element message = reply->getChildElement("message");
            if (not (code and message)) throw std::exception();

            Element specific_reply = reply->getChildElement("get_resource_reply");
            if (not specific_reply) throw std::exception();

            Element get_resource_reply = specific_reply->getChildElement("get_resource_reply");
            if (not get_resource_reply) throw std::exception();

            Element resource = get_resource_reply->getChildElement("resource");
            if (not resource) throw std::exception();

            Element resourcename = resource->getChildElement("resourcename");
            Element volume = resource->getChildElement("volume");
            if (not (resourcename and volume)) throw std::exception();

            TUSLanguage::ICommand::Object object;
            object.insert(std::make_pair("resourcename", resourcename->innerText()));
            object.insert(std::make_pair("volume", volume->innerText()));

            return reply_builder.buildGetResourceReply(
                       boost::lexical_cast<unsigned short int>(code->innerText()),
                       message->innerText(),
                       object
                   );
        }

        case TUSLanguage::ID_COMMAND_GET_RESOURCES_REPLY:
        {
            Element reply = message->getChildElement("reply");
            if (not reply) throw std::exception();

            Element code = reply->getChildElement("code");
            Element message = reply->getChildElement("message");
            if (not (code and message)) throw std::exception();

            Element specific_reply = reply->getChildElement("get_resources_reply");
            if (not specific_reply) throw std::exception();

            Element get_resources_reply = specific_reply->getChildElement("get_resources_reply");
            if (not get_resources_reply) throw std::exception();

            Element resources = get_resources_reply->getChildElement("resources");
            if (not resources) throw std::exception();

            Poco::AutoPtr<Poco::XML::NodeList> elements = resources->getElementsByTagName("resource");

            TUSLanguage::ICommand::Objects objects;

            for (int i = 0; i < elements->length(); ++i)
            {
                Element resource = static_cast<Poco::XML::Element*>(elements->item(i));

                Element resourcename = resource->getChildElement("resourcename");
                Element volume = resource->getChildElement("volume");
                if (not (resourcename and volume)) throw std::exception();

                TUSLanguage::ICommand::Object object;
                object.insert(std::make_pair("resourcename", resourcename->innerText()));
                object.insert(std::make_pair("volume", volume->innerText()));

                objects.push_back(object);
            }

            return reply_builder.buildGetResourcesReply(
                       boost::lexical_cast<unsigned short int>(code->innerText()),
                       message->innerText(),
                       objects
                   );
        }

        case TUSLanguage::ID_COMMAND_CREATE_USER_REPLY:
        {
            Element reply = message->getChildElement("reply");
            if (not reply) throw std::exception();

            Element code = reply->getChildElement("code");
            Element message = reply->getChildElement("message");
            if (not (code and message)) throw std::exception();

            Element specific_reply = reply->getChildElement("create_user_reply");
            if (not specific_reply) throw std::exception();

            return reply_builder.buildCreateUserReply(
                       boost::lexical_cast<unsigned short int>(code->innerText()),
                       message->innerText()
                   );
        }

        case TUSLanguage::ID_COMMAND_CREATE_WORLD_REPLY:
        {
            Element reply = message->getChildElement("reply");
            if (not reply) throw std::exception();

            Element code = reply->getChildElement("code");
            Element message = reply->getChildElement("message");
            if (not (code and message)) throw std::exception();

            Element specific_reply = reply->getChildElement("create_world_reply");
            if (not specific_reply) throw std::exception();

            return reply_builder.buildCreateWorldReply(
                       boost::lexical_cast<unsigned short int>(code->innerText()),
                       message->innerText()
                   );
        }

        case TUSLanguage::ID_COMMAND_CREATE_EPOCH_REPLY:
        {
            Element reply = message->getChildElement("reply");
            if (not reply) throw std::exception();

            Element code = reply->getChildElement("code");
            Element message = reply->getChildElement("message");
            if (not (code and message)) throw std::exception();

            Element specific_reply = reply->getChildElement("create_epoch_reply");
            if (not specific_reply) throw std::exception();

            return reply_builder.buildCreateEpochReply(
                       boost::lexical_cast<unsigned short int>(code->innerText()),
                       message->innerText()
                   );
        }

        case TUSLanguage::ID_COMMAND_DELETE_EPOCH_REPLY:
        {
            Element reply = message->getChildElement("reply");
            if (not reply) throw std::exception();

            Element code = reply->getChildElement("code");
            Element message = reply->getChildElement("message");
            if (not (code and message)) throw std::exception();

            Element specific_reply = reply->getChildElement("delete_epoch_reply");
            if (not specific_reply) throw std::exception();

            return reply_builder.buildDeleteEpochReply(
                       boost::lexical_cast<unsigned short int>(code->innerText()),
                       message->innerText()
                   );
        }

        case TUSLanguage::ID_COMMAND_ACTIVATE_EPOCH_REPLY:
        {
            Element reply = message->getChildElement("reply");
            if (not reply) throw std::exception();

            Element code = reply->getChildElement("code");
            Element message = reply->getChildElement("message");
            if (not (code and message)) throw std::exception();

            Element specific_reply = reply->getChildElement("activate_epoch_reply");
            if (not specific_reply) throw std::exception();

            return reply_builder.buildActivateEpochReply(
                       boost::lexical_cast<unsigned short int>(code->innerText()),
                       message->innerText()
                   );
        }

        case TUSLanguage::ID_COMMAND_DEACTIVATE_EPOCH_REPLY:
        {
            Element reply = message->getChildElement("reply");
            if (not reply) throw std::exception();

            Element code = reply->getChildElement("code");
            Element message = reply->getChildElement("message");
            if (not (code and message)) throw std::exception();

            Element specific_reply = reply->getChildElement("deactivate_epoch_reply");
            if (not specific_reply) throw std::exception();

            return reply_builder.buildDeactivateEpochReply(
                       boost::lexical_cast<unsigned short int>(code->innerText()),
                       message->innerText()
                   );
        }

        case TUSLanguage::ID_COMMAND_FINISH_EPOCH_REPLY:
        {
            Element reply = message->getChildElement("reply");
            if (not reply) throw std::exception();

            Element code = reply->getChildElement("code");
            Element message = reply->getChildElement("message");
            if (not (code and message)) throw std::exception();

            Element specific_reply = reply->getChildElement("finish_epoch_reply");
            if (not specific_reply) throw std::exception();

            return reply_builder.buildFinishEpochReply(
                       boost::lexical_cast<unsigned short int>(code->innerText()),
                       message->innerText()
                   );
        }

        case TUSLanguage::ID_COMMAND_TICK_EPOCH_REPLY:
        {
            Element reply = message->getChildElement("reply");
            if (not reply) throw std::exception();

            Element code = reply->getChildElement("code");
            Element message = reply->getChildElement("message");
            if (not (code and message)) throw std::exception();

            Element specific_reply = reply->getChildElement("tick_epoch_reply");
            if (not specific_reply) throw std::exception();

            return reply_builder.buildTickEpochReply(
                       boost::lexical_cast<unsigned short int>(code->innerText()),
                       message->innerText()
                   );
        }

        case TUSLanguage::ID_COMMAND_GET_EPOCH_REPLY:
        {
            Element reply = message->getChildElement("reply");
            if (not reply) throw std::exception();

            Element code = reply->getChildElement("code");
            Element message = reply->getChildElement("message");
            if (not (code and message)) throw std::exception();

            Element specific_reply = reply->getChildElement("get_epoch_reply");
            if (not specific_reply) throw std::exception();

            Element get_epoch_reply = specific_reply->getChildElement("get_epoch_reply");
            if (not get_epoch_reply) throw std::exception();

            Element epoch = get_epoch_reply->getChildElement("epoch");
            if (not epoch) throw std::exception();

            Element epoch_name = epoch->getChildElement("epoch_name");
            Element world_name = epoch->getChildElement("world_name");
            Element active = epoch->getChildElement("active");
            Element finish = epoch->getChildElement("finish");
            Element ticks = epoch->getChildElement("ticks");
            if (not (epoch_name and world_name and active and finish and ticks)) throw std::exception();

            TUSLanguage::ICommand::Object object;
            object.insert(std::make_pair("epoch_name", epoch_name->innerText()));
            object.insert(std::make_pair("world_name", world_name->innerText()));
            object.insert(std::make_pair("active", active->innerText()));
            object.insert(std::make_pair("finish", finish->innerText()));
            object.insert(std::make_pair("ticks", ticks->innerText()));

            return reply_builder.buildGetEpochReply(
                       boost::lexical_cast<unsigned short int>(code->innerText()),
                       message->innerText(),
                       object
                   );
        }

        case TUSLanguage::ID_COMMAND_TRANSPORT_HUMAN_REPLY:
        {
            Element reply = message->getChildElement("reply");
            if (not reply) throw std::exception();

            Element code = reply->getChildElement("code");
            Element message = reply->getChildElement("message");
            if (not (code and message)) throw std::exception();

            Element specific_reply = reply->getChildElement("transport_human_reply");
            if (not specific_reply) throw std::exception();

            return reply_builder.buildTransportHumanReply(
                       boost::lexical_cast<unsigned short int>(code->innerText()),
                       message->innerText()
                   );
        }

        case TUSLanguage::ID_COMMAND_TRANSPORT_RESOURCE_REPLY:
        {
            Element reply = message->getChildElement("reply");
            if (not reply) throw std::exception();

            Element code = reply->getChildElement("code");
            Element message = reply->getChildElement("message");
            if (not (code and message)) throw std::exception();

            Element specific_reply = reply->getChildElement("transport_resource_reply");
            if (not specific_reply) throw std::exception();

            return reply_builder.buildTransportResourceReply(
                       boost::lexical_cast<unsigned short int>(code->innerText()),
                       message->innerText()
                   );
        }

        default:
            BOOST_ASSERT_MSG(false, "Invalid command ID.");
    }
}

} // namespace TUSProtocol

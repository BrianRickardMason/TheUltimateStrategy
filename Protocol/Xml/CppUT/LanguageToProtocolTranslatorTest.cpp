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

#include <Language/Interface/ReplyBuilder.hpp>
#include <Language/Interface/RequestBuilder.hpp>
#include <Poco/AutoPtr.h>
#include <Poco/DOM/Element.h>
#include <Protocol/Xml/Cpp/LanguageToProtocolTranslator.hpp>
#include <gtest/gtest.h>

class LanguageToProtocolTranslatorEchoRequestTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorEchoRequestTranslation()
        : m_command(m_builder.buildEchoRequest())
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::RequestBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorEchoRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorEchoRequestTranslation, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("1", element->innerText().c_str());
}

class LanguageToProtocolTranslatorErrorRequestTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorErrorRequestTranslation()
        : m_command(m_builder.buildErrorRequest())
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::RequestBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorErrorRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorErrorRequestTranslation, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("2", element->innerText().c_str());
}

class LanguageToProtocolTranslatorCreateLandRequestTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorCreateLandRequestTranslation()
        : m_command(m_builder.buildCreateLandRequest("Login", "Password", "World", "Land"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::RequestBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorCreateLandRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorCreateLandRequestTranslation, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("3", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorCreateLandRequestTranslation, SetsProperLogin)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorCreateLandRequestTranslation, SetsProperPassword)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorCreateLandRequestTranslation, SetsProperWorldName)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("create_land_request")->getChildElement("world_name");
    ASSERT_STREQ("World", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorCreateLandRequestTranslation, SetsProperLandName)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("create_land_request")->getChildElement("land_name");
    ASSERT_STREQ("Land", element->innerText().c_str());
}

class LanguageToProtocolTranslatorDeleteLandRequestTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorDeleteLandRequestTranslation()
        : m_command(m_builder.buildDeleteLandRequest("Login", "Password", "Land"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::RequestBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorDeleteLandRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorDeleteLandRequestTranslation, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("4", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorDeleteLandRequestTranslation, SetsProperLogin)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorDeleteLandRequestTranslation, SetsProperPassword)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorDeleteLandRequestTranslation, SetsProperLandName)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("delete_land_request")->getChildElement("land_name");
    ASSERT_STREQ("Land", element->innerText().c_str());
}

class LanguageToProtocolTranslatorGetLandRequestTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorGetLandRequestTranslation()
        : m_command(m_builder.buildGetLandRequest("Login", "Password", "Land"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::RequestBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorGetLandRequestTranslation, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("5", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetLandRequestTranslation, SetsProperLogin)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetLandRequestTranslation, SetsProperPassword)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetLandRequestTranslation, SetsProperLandName)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("get_land_request")->getChildElement("land_name");
    ASSERT_STREQ("Land", element->innerText().c_str());
}

class LanguageToProtocolTranslatorGetLandsRequestTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorGetLandsRequestTranslation()
        : m_command(m_builder.buildGetLandsRequest("Login", "Password"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::RequestBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorGetLandsRequestTranslation, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("6", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetLandsRequestTranslation, SetsProperLogin)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetLandsRequestTranslation, SetsProperPassword)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

class LanguageToProtocolTranslatorCreateSettlementRequestTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorCreateSettlementRequestTranslation()
        : m_command(m_builder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::RequestBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorCreateSettlementRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorCreateSettlementRequestTranslation, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("7", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorCreateSettlementRequestTranslation, SetsProperLogin)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorCreateSettlementRequestTranslation, SetsProperPassword)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorCreateSettlementRequestTranslation, SetsProperLandName)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("create_settlement_request")->getChildElement("land_name");
    ASSERT_STREQ("Land", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorCreateSettlementRequestTranslation, SetsProperSettlementName)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("create_settlement_request")->getChildElement("settlement_name");
    ASSERT_STREQ("Settlement", element->innerText().c_str());
}

class LanguageToProtocolTranslatorDeleteSettlementRequestTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorDeleteSettlementRequestTranslation()
        : m_command(m_builder.buildDeleteSettlementRequest("Login", "Password", "Settlement"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::RequestBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorDeleteSettlementRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorDeleteSettlementRequestTranslation, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("8", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorDeleteSettlementRequestTranslation, SetsProperLogin)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorDeleteSettlementRequestTranslation, SetsProperPassword)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorDeleteSettlementRequestTranslation, SetsProperSettlementName)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("delete_settlement_request")->getChildElement("settlement_name");
    ASSERT_STREQ("Settlement", element->innerText().c_str());
}

class LanguageToProtocolTranslatorGetSettlementRequestTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorGetSettlementRequestTranslation()
        : m_command(m_builder.buildGetSettlementRequest("Login", "Password", "Settlement"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::RequestBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorGetSettlementRequestTranslation, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("9", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetSettlementRequestTranslation, SetsProperLogin)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetSettlementRequestTranslation, SetsProperPassword)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetSettlementRequestTranslation, SetsProperSettlementName)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("get_settlement_request")->getChildElement("settlement_name");
    ASSERT_STREQ("Settlement", element->innerText().c_str());
}

class LanguageToProtocolTranslatorGetSettlementsRequestTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorGetSettlementsRequestTranslation()
        : m_command(m_builder.buildGetSettlementsRequest("Login", "Password", "Land"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::RequestBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorGetSettlementsRequestTranslation, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("10", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetSettlementsRequestTranslation, SetsProperLogin)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetSettlementsRequestTranslation, SetsProperPassword)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetSettlementsRequestTranslation, SetsProperLandName)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("get_settlements_request")->getChildElement("land_name");
    ASSERT_STREQ("Land", element->innerText().c_str());
}

class LanguageToProtocolTranslatorBuildBuildingRequestTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorBuildBuildingRequestTranslation()
        : m_command(m_builder.buildBuildBuildingRequest(
              "Login", "Password", "HolderClassSettlement", "Settlement", "RegularForge", "100"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::RequestBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorBuildBuildingRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorBuildBuildingRequestTranslation, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("11", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorBuildBuildingRequestTranslation, SetsProperLogin)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorBuildBuildingRequestTranslation, SetsProperPassword)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorBuildBuildingRequestTranslation, SetsProperIDHolderClass)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("build_building_request")->getChildElement("idholderclass");
    ASSERT_STREQ("HolderClassSettlement", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorBuildBuildingRequestTranslation, SetsProperHolderName)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("build_building_request")->getChildElement("holder_name");
    ASSERT_STREQ("Settlement", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorBuildBuildingRequestTranslation, SetsProperBuildingKey)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("build_building_request")->getChildElement("buildingkey");
    ASSERT_STREQ("RegularForge", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorBuildBuildingRequestTranslation, SetsProperVolume)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("build_building_request")->getChildElement("volume");
    ASSERT_STREQ("100", element->innerText().c_str());
}

class LanguageToProtocolTranslatorDestroyBuildingRequestTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorDestroyBuildingRequestTranslation()
        : m_command(m_builder.buildDestroyBuildingRequest(
              "Login", "Password", "HolderClassSettlement", "Settlement", "RegularForge", "100"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::RequestBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorDestroyBuildingRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorDestroyBuildingRequestTranslation, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("12", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorDestroyBuildingRequestTranslation, SetsProperLogin)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorDestroyBuildingRequestTranslation, SetsProperPassword)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorDestroyBuildingRequestTranslation, SetsProperIDHolderClass)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("destroy_building_request")->getChildElement("idholderclass");
    ASSERT_STREQ("HolderClassSettlement", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorDestroyBuildingRequestTranslation, SetsProperHolderName)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("destroy_building_request")->getChildElement("holder_name");
    ASSERT_STREQ("Settlement", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorDestroyBuildingRequestTranslation, SetsProperBuildingKey)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("destroy_building_request")->getChildElement("buildingkey");
    ASSERT_STREQ("RegularForge", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorDestroyBuildingRequestTranslation, SetsProperVolume)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("destroy_building_request")->getChildElement("volume");
    ASSERT_STREQ("100", element->innerText().c_str());
}

class LanguageToProtocolTranslatorGetBuildingRequestTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorGetBuildingRequestTranslation()
        : m_command(m_builder.buildGetBuildingRequest(
              "Login", "Password", "HolderClassSettlement", "Settlement", "RegularForge"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::RequestBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorGetBuildingRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorGetBuildingRequestTranslation, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("13", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetBuildingRequestTranslation, SetsProperLogin)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetBuildingRequestTranslation, SetsProperPassword)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetBuildingRequestTranslation, SetsProperIDHolderClass)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("get_building_request")->getChildElement("idholderclass");
    ASSERT_STREQ("HolderClassSettlement", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetBuildingRequestTranslation, SetsProperHolderName)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("get_building_request")->getChildElement("holder_name");
    ASSERT_STREQ("Settlement", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetBuildingRequestTranslation, SetsProperBuildingKey)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("get_building_request")->getChildElement("buildingkey");
    ASSERT_STREQ("RegularForge", element->innerText().c_str());
}

class LanguageToProtocolTranslatorGetBuildingsRequestTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorGetBuildingsRequestTranslation()
        : m_command(m_builder.buildGetBuildingsRequest(
              "Login", "Password", "HolderClassSettlement", "Settlement"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::RequestBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorGetBuildingsRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorGetBuildingsRequestTranslation, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("14", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetBuildingsRequestTranslation, SetsProperLogin)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetBuildingsRequestTranslation, SetsProperPassword)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetBuildingsRequestTranslation, SetsProperIDHolderClass)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("get_buildings_request")->getChildElement("idholderclass");
    ASSERT_STREQ("HolderClassSettlement", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetBuildingsRequestTranslation, SetsProperHolderName)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("get_buildings_request")->getChildElement("holder_name");
    ASSERT_STREQ("Settlement", element->innerText().c_str());
}

class LanguageToProtocolTranslatorDismissHumanRequestTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorDismissHumanRequestTranslation()
        : m_command(m_builder.buildDismissHumanRequest(
              "Login", "Password", "HolderClassSettlement", "Settlement", "WorkerBlacksmithNovice", "100"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::RequestBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorDismissHumanRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorDismissHumanRequestTranslation, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("15", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorDismissHumanRequestTranslation, SetsProperLogin)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorDismissHumanRequestTranslation, SetsProperPassword)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorDismissHumanRequestTranslation, SetsProperIDHolderClass)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("dismiss_human_request")->getChildElement("idholderclass");
    ASSERT_STREQ("HolderClassSettlement", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorDismissHumanRequestTranslation, SetsProperHolderName)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("dismiss_human_request")->getChildElement("holder_name");
    ASSERT_STREQ("Settlement", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorDismissHumanRequestTranslation, SetsProperHumanKey)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("dismiss_human_request")->getChildElement("humankey");
    ASSERT_STREQ("WorkerBlacksmithNovice", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorDismissHumanRequestTranslation, SetsProperVolume)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("dismiss_human_request")->getChildElement("volume");
    ASSERT_STREQ("100", element->innerText().c_str());
}

class LanguageToProtocolTranslatorEngageHumanRequestTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorEngageHumanRequestTranslation()
        : m_command(m_builder.buildEngageHumanRequest(
              "Login", "Password", "HolderClassSettlement", "Settlement", "WorkerBlacksmithNovice", "100"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::RequestBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorEngageHumanRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorEngageHumanRequestTranslation, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("16", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorEngageHumanRequestTranslation, SetsProperLogin)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorEngageHumanRequestTranslation, SetsProperPassword)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorEngageHumanRequestTranslation, SetsProperIDHolderClass)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("engage_human_request")->getChildElement("idholderclass");
    ASSERT_STREQ("HolderClassSettlement", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorEngageHumanRequestTranslation, SetsProperHolderName)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("engage_human_request")->getChildElement("holder_name");
    ASSERT_STREQ("Settlement", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorEngageHumanRequestTranslation, SetsProperHumanKey)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("engage_human_request")->getChildElement("humankey");
    ASSERT_STREQ("WorkerBlacksmithNovice", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorEngageHumanRequestTranslation, SetsProperVolume)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("engage_human_request")->getChildElement("volume");
    ASSERT_STREQ("100", element->innerText().c_str());
}

class LanguageToProtocolTranslatorGetHumanRequestTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorGetHumanRequestTranslation()
        : m_command(m_builder.buildGetHumanRequest(
              "Login", "Password", "HolderClassSettlement", "Settlement", "WorkerBlacksmithNovice"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::RequestBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorGetHumanRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorGetHumanRequestTranslation, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("17", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetHumanRequestTranslation, SetsProperLogin)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetHumanRequestTranslation, SetsProperPassword)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetHumanRequestTranslation, SetsProperIDHolderClass)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("get_human_request")->getChildElement("idholderclass");
    ASSERT_STREQ("HolderClassSettlement", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetHumanRequestTranslation, SetsProperHolderName)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("get_human_request")->getChildElement("holder_name");
    ASSERT_STREQ("Settlement", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetHumanRequestTranslation, SetsProperHumanKey)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("get_human_request")->getChildElement("humankey");
    ASSERT_STREQ("WorkerBlacksmithNovice", element->innerText().c_str());
}

class LanguageToProtocolTranslatorGetHumansRequestTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorGetHumansRequestTranslation()
        : m_command(m_builder.buildGetHumansRequest(
              "Login", "Password", "HolderClassSettlement", "Settlement"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::RequestBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorGetHumansRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorGetHumansRequestTranslation, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("18", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetHumansRequestTranslation, SetsProperLogin)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetHumansRequestTranslation, SetsProperPassword)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetHumansRequestTranslation, SetsProperIDHolderClass)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("get_humans_request")->getChildElement("idholderclass");
    ASSERT_STREQ("HolderClassSettlement", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetHumansRequestTranslation, SetsProperHolderName)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("get_humans_request")->getChildElement("holder_name");
    ASSERT_STREQ("Settlement", element->innerText().c_str());
}

class LanguageToProtocolTranslatorGetResourceRequestTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorGetResourceRequestTranslation()
        : m_command(m_builder.buildGetResourceRequest(
              "Login", "Password", "HolderClassSettlement", "Settlement", "Coal"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::RequestBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorGetResourceRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorGetResourceRequestTranslation, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("19", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetResourceRequestTranslation, SetsProperLogin)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetResourceRequestTranslation, SetsProperPassword)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetResourceRequestTranslation, SetsProperIDHolderClass)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("get_resource_request")->getChildElement("idholderclass");
    ASSERT_STREQ("HolderClassSettlement", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetResourceRequestTranslation, SetsProperHolderName)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("get_resource_request")->getChildElement("holder_name");
    ASSERT_STREQ("Settlement", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetResourceRequestTranslation, SetsProperResourceKey)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("get_resource_request")->getChildElement("resourcekey");
    ASSERT_STREQ("Coal", element->innerText().c_str());
}

class LanguageToProtocolTranslatorGetResourcesRequestTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorGetResourcesRequestTranslation()
        : m_command(m_builder.buildGetResourcesRequest(
              "Login", "Password", "HolderClassSettlement", "Settlement"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::RequestBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorGetResourcesRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorGetResourcesRequestTranslation, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("20", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetResourcesRequestTranslation, SetsProperLogin)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetResourcesRequestTranslation, SetsProperPassword)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetResourcesRequestTranslation, SetsProperIDHolderClass)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("get_resources_request")->getChildElement("idholderclass");
    ASSERT_STREQ("HolderClassSettlement", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetResourcesRequestTranslation, SetsProperHolderName)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("get_resources_request")->getChildElement("holder_name");
    ASSERT_STREQ("Settlement", element->innerText().c_str());
}

class LanguageToProtocolTranslatorCreateUserRequestTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorCreateUserRequestTranslation()
        : m_command(m_builder.buildCreateUserRequest("Login", "Password"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::RequestBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorCreateUserRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorCreateUserRequestTranslation, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("21", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorCreateUserRequestTranslation, SetsProperLogin)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("create_user_request")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorCreateUserRequestTranslation, SetsProperPassword)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("create_user_request")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

class LanguageToProtocolTranslatorCreateWorldRequestTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorCreateWorldRequestTranslation()
        : m_command(m_builder.buildCreateWorldRequest("Login", "Password", "World"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::RequestBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorCreateWorldRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorCreateWorldRequestTranslation, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("22", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorCreateWorldRequestTranslation, SetsProperLogin)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorCreateWorldRequestTranslation, SetsProperPassword)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorCreateWorldRequestTranslation, SetsProperWorldName)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("create_world_request")->getChildElement("world_name");
    ASSERT_STREQ("World", element->innerText().c_str());
}

class LanguageToProtocolTranslatorCreateEpochRequestTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorCreateEpochRequestTranslation()
        : m_command(m_builder.buildCreateEpochRequest("Login", "Password", "World", "Epoch"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::RequestBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorCreateEpochRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorCreateEpochRequestTranslation, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("23", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorCreateEpochRequestTranslation, SetsProperLogin)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorCreateEpochRequestTranslation, SetsProperPassword)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorCreateEpochRequestTranslation, SetsProperWorldName)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("create_epoch_request")->getChildElement("world_name");
    ASSERT_STREQ("World", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorCreateEpochRequestTranslation, SetsProperEpochName)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("create_epoch_request")->getChildElement("epoch_name");
    ASSERT_STREQ("Epoch", element->innerText().c_str());
}

class LanguageToProtocolTranslatorDeleteEpochRequestTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorDeleteEpochRequestTranslation()
        : m_command(m_builder.buildDeleteEpochRequest("Login", "Password", "World"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::RequestBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorDeleteEpochRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorDeleteEpochRequestTranslation, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("24", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorDeleteEpochRequestTranslation, SetsProperLogin)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorDeleteEpochRequestTranslation, SetsProperPassword)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorDeleteEpochRequestTranslation, SetsProperWorldName)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("delete_epoch_request")->getChildElement("world_name");
    ASSERT_STREQ("World", element->innerText().c_str());
}

class LanguageToProtocolTranslatorActivateEpochRequestTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorActivateEpochRequestTranslation()
        : m_command(m_builder.buildActivateEpochRequest("Login", "Password", "World"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::RequestBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorActivateEpochRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorActivateEpochRequestTranslation, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("25", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorActivateEpochRequestTranslation, SetsProperLogin)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorActivateEpochRequestTranslation, SetsProperPassword)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorActivateEpochRequestTranslation, SetsProperWorldName)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("activate_epoch_request")->getChildElement("world_name");
    ASSERT_STREQ("World", element->innerText().c_str());
}

class LanguageToProtocolTranslatorDeactivateEpochRequestTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorDeactivateEpochRequestTranslation()
        : m_command(m_builder.buildDeactivateEpochRequest("Login", "Password", "World"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::RequestBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorDeactivateEpochRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorDeactivateEpochRequestTranslation, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("26", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorDeactivateEpochRequestTranslation, SetsProperLogin)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorDeactivateEpochRequestTranslation, SetsProperPassword)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorDeactivateEpochRequestTranslation, SetsProperWorldName)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("deactivate_epoch_request")->getChildElement("world_name");
    ASSERT_STREQ("World", element->innerText().c_str());
}

class LanguageToProtocolTranslatorFinishEpochRequestTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorFinishEpochRequestTranslation()
        : m_command(m_builder.buildFinishEpochRequest("Login", "Password", "World"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::RequestBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorFinishEpochRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorFinishEpochRequestTranslation, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("27", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorFinishEpochRequestTranslation, SetsProperLogin)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorFinishEpochRequestTranslation, SetsProperPassword)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorFinishEpochRequestTranslation, SetsProperWorldName)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("finish_epoch_request")->getChildElement("world_name");
    ASSERT_STREQ("World", element->innerText().c_str());
}

class LanguageToProtocolTranslatorTickEpochRequestTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorTickEpochRequestTranslation()
        : m_command(m_builder.buildTickEpochRequest("Login", "Password", "World"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::RequestBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorTickEpochRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorTickEpochRequestTranslation, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("28", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorTickEpochRequestTranslation, SetsProperLogin)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorTickEpochRequestTranslation, SetsProperPassword)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorTickEpochRequestTranslation, SetsProperWorldName)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("tick_epoch_request")->getChildElement("world_name");
    ASSERT_STREQ("World", element->innerText().c_str());
}

class LanguageToProtocolTranslatorGetEpochRequestTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorGetEpochRequestTranslation()
        : m_command(m_builder.buildGetEpochRequest("Login", "Password", "World"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::RequestBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorGetEpochRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorGetEpochRequestTranslation, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("29", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetEpochRequestTranslation, SetsProperLogin)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetEpochRequestTranslation, SetsProperPassword)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetEpochRequestTranslation, SetsProperWorldName)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("get_epoch_request")->getChildElement("world_name");
    ASSERT_STREQ("World", element->innerText().c_str());
}

class LanguageToProtocolTranslatorTransportHumanRequestTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorTransportHumanRequestTranslation()
        : m_command(m_builder.buildTransportHumanRequest(
              "Login", "Password", "SettlementSource", "SettlementDestination", "WorkerBlacksmithNovice", "100"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::RequestBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorTransportHumanRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorTransportHumanRequestTranslation, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("30", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorTransportHumanRequestTranslation, SetsProperLogin)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorTransportHumanRequestTranslation, SetsProperPassword)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorTransportHumanRequestTranslation, SetsProperSettlementNameSource)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("transport_human_request")->
        getChildElement("settlement_name_source");
    ASSERT_STREQ("SettlementSource", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorTransportHumanRequestTranslation, SetsProperSettlementNameDestination)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("transport_human_request")->
        getChildElement("settlement_name_destination");
    ASSERT_STREQ("SettlementDestination", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorTransportHumanRequestTranslation, SetsProperHumanKey)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("transport_human_request")->getChildElement("humankey");
    ASSERT_STREQ("WorkerBlacksmithNovice", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorTransportHumanRequestTranslation, SetsProperVolume)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("transport_human_request")->getChildElement("volume");
    ASSERT_STREQ("100", element->innerText().c_str());
}

class LanguageToProtocolTranslatorTransportResourceRequestTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorTransportResourceRequestTranslation()
        : m_command(m_builder.buildTransportResourceRequest(
              "Login", "Password", "SettlementSource", "SettlementDestination", "Coal", "100"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::RequestBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorTransportResourceRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorTransportResourceRequestTranslation, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("31", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorTransportResourceRequestTranslation, SetsProperLogin)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorTransportResourceRequestTranslation, SetsProperPassword)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorTransportResourceRequestTranslation, SetsProperSettlementNameSource)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("transport_resource_request")->
        getChildElement("settlement_name_source");
    ASSERT_STREQ("SettlementSource", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorTransportResourceRequestTranslation, SetsProperSettlementNameDestination)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("transport_resource_request")->
        getChildElement("settlement_name_destination");
    ASSERT_STREQ("SettlementDestination", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorTransportResourceRequestTranslation, SetsProperResourceKey)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("transport_resource_request")->getChildElement("resourcekey");
    ASSERT_STREQ("Coal", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorTransportResourceRequestTranslation, SetsProperVolume)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("request")->getChildElement("transport_resource_request")->getChildElement("volume");
    ASSERT_STREQ("100", element->innerText().c_str());
}

class LanguageToProtocolTranslatorEchoReplyTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorEchoReplyTranslation()
        : m_command(m_builder.buildEchoReply(1))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::ReplyBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorEchoReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorEchoReplyTranslation, SetsProperReplyID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("32", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorEchoReplyTranslation, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorEchoReplyTranslation, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("echo_reply");
    ASSERT_TRUE(element != NULL);
}

class LanguageToProtocolTranslatorErrorReplyTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorErrorReplyTranslation()
        : m_command(m_builder.buildErrorReply(1))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::ReplyBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorErrorReplyTranslation, CreateErrorReplyReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorErrorReplyTranslation, CreateErrorReplySetsProperReplyID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("33", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorErrorReplyTranslation, CreateErrorReplySetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorErrorReplyTranslation, CreateErrorReplySetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("error_reply");
    ASSERT_TRUE(element != NULL);
}

class LanguageToProtocolTranslatorCreateLandReplyTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorCreateLandReplyTranslation()
        : m_command(m_builder.buildCreateLandReply(1, "Message"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::ReplyBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorCreateLandReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorCreateLandReplyTranslation, SetsProperReplyID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("34", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorCreateLandReplyTranslation, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorCreateLandReplyTranslation, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorCreateLandReplyTranslation, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("create_land_reply");
    ASSERT_TRUE(element != NULL);
}

class LanguageToProtocolTranslatorDeleteLandReplyTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorDeleteLandReplyTranslation()
        : m_command(m_builder.buildDeleteLandReply(1, "Message"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::ReplyBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorDeleteLandReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorDeleteLandReplyTranslation, SetsProperReplyID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("35", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorDeleteLandReplyTranslation, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorDeleteLandReplyTranslation, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorDeleteLandReplyTranslation, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("delete_land_reply");
    ASSERT_TRUE(element != NULL);
}

class LanguageToProtocolTranslatorGetLandWithoutObjectReplyTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorGetLandWithoutObjectReplyTranslation()
    {
        TUSLanguage::ReplyBuilder builder;
        TUSProtocol::LanguageToProtocolTranslator translator;
        TUSLanguage::ICommand::Handle command = builder.buildGetLandReply(1, "Message");
        m_message = translator.translate(command);
    }

    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorGetLandWithoutObjectReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorGetLandWithoutObjectReplyTranslation, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("36", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetLandWithoutObjectReplyTranslation, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetLandWithoutObjectReplyTranslation, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetLandWithoutObjectReplyTranslation, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_land_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(LanguageToProtocolTranslatorGetLandWithoutObjectReplyTranslation, DoesNotSetObject)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_land_reply")->getChildElement("land");
    ASSERT_TRUE(element == NULL);
}

class LanguageToProtocolTranslatorGetLandWithObjectReplyTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorGetLandWithObjectReplyTranslation()
    {
        TUSLanguage::ReplyBuilder builder;
        TUSProtocol::LanguageToProtocolTranslator translator;
        TUSLanguage::ICommand::Object land;
        land.insert(std::make_pair("login", "Login1"));
        land.insert(std::make_pair("world_name", "World1"));
        land.insert(std::make_pair("land_name", "Land1"));
        land.insert(std::make_pair("granted", "false"));
        TUSLanguage::ICommand::Handle command = builder.buildGetLandReply(1, "Message", land);
        m_message = translator.translate(command);
    }

    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorGetLandWithObjectReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorGetLandWithObjectReplyTranslation, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("36", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetLandWithObjectReplyTranslation, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetLandWithObjectReplyTranslation, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetLandWithObjectReplyTranslation, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_land_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(LanguageToProtocolTranslatorGetLandWithObjectReplyTranslation, SetsObject)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_land_reply")->getChildElement("land");
    ASSERT_TRUE(element != NULL);
}

TEST_F(LanguageToProtocolTranslatorGetLandWithObjectReplyTranslation, SetsProperObject)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_land_reply")->getChildElement("land");
    ASSERT_STREQ("Login1", element->getChildElement("login")->innerText().c_str());
    ASSERT_STREQ("World1", element->getChildElement("world_name")->innerText().c_str());
    ASSERT_STREQ("Land1", element->getChildElement("land_name")->innerText().c_str());
    ASSERT_STREQ("false", element->getChildElement("granted")->innerText().c_str());
}

class LanguageToProtocolTranslatorGetLandsReplyTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorGetLandsReplyTranslation()
    {
        TUSLanguage::ICommand::Object land_1, land_2;
        TUSLanguage::ICommand::Objects lands;
        land_1.insert(std::make_pair("login", "Login1"));
        land_1.insert(std::make_pair("world_name", "World1"));
        land_1.insert(std::make_pair("land_name", "Land1"));
        land_1.insert(std::make_pair("granted", "false"));
        land_2.insert(std::make_pair("login", "Login2"));
        land_2.insert(std::make_pair("world_name", "World2"));
        land_2.insert(std::make_pair("land_name", "Land2"));
        land_2.insert(std::make_pair("granted", "false"));
        lands.push_back(land_1);
        lands.push_back(land_2);
        m_command = m_builder.buildGetLandsReply(1, "Message", lands);
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::ReplyBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorGetLandsReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorGetLandsReplyTranslation, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("37", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetLandsReplyTranslation, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetLandsReplyTranslation, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetLandsReplyTranslation, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_lands_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(LanguageToProtocolTranslatorGetLandsReplyTranslation, SetsProperObjects)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_lands_reply")->getChildElement("lands");

    // TODO: Extend testing.
}

class LanguageToProtocolTranslatorCreateSettlementReplyTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorCreateSettlementReplyTranslation()
        : m_command(m_builder.buildCreateSettlementReply(1, "Message"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::ReplyBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorCreateSettlementReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorCreateSettlementReplyTranslation, SetsProperReplyID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("38", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorCreateSettlementReplyTranslation, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorCreateSettlementReplyTranslation, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorCreateSettlementReplyTranslation, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("create_settlement_reply");
    ASSERT_TRUE(element != NULL);
}

class LanguageToProtocolTranslatorDeleteSettlementReplyTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorDeleteSettlementReplyTranslation()
        : m_command(m_builder.buildDeleteSettlementReply(1, "Message"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::ReplyBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorDeleteSettlementReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorDeleteSettlementReplyTranslation, SetsProperReplyID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("39", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorDeleteSettlementReplyTranslation, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorDeleteSettlementReplyTranslation, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorDeleteSettlementReplyTranslation, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("delete_settlement_reply");
    ASSERT_TRUE(element != NULL);
}

class LanguageToProtocolTranslatorGetSettlementReplyTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorGetSettlementReplyTranslation()
    {
        TUSLanguage::ICommand::Object settlement;
        settlement.insert(std::make_pair("land_name", "Land1"));
        settlement.insert(std::make_pair("settlement_name", "Settlement1"));
        m_command = m_builder.buildGetSettlementReply(1, "Message", settlement);
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::ReplyBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorGetSettlementReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorGetSettlementReplyTranslation, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("40", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetSettlementReplyTranslation, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetSettlementReplyTranslation, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetSettlementReplyTranslation, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_settlement_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(LanguageToProtocolTranslatorGetSettlementReplyTranslation, SetsProperObject)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_settlement_reply")->getChildElement("settlement");
    ASSERT_STREQ("Land1", element->getChildElement("land_name")->innerText().c_str());
    ASSERT_STREQ("Settlement1", element->getChildElement("settlement_name")->innerText().c_str());
}

class LanguageToProtocolTranslatorGetSettlementsReplyTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorGetSettlementsReplyTranslation()
    {
        TUSLanguage::ICommand::Object settlement_1, settlement_2;
        TUSLanguage::ICommand::Objects settlements;
        settlement_1.insert(std::make_pair("land_name", "Land1"));
        settlement_1.insert(std::make_pair("settlement_name", "Settlement1"));
        settlement_2.insert(std::make_pair("land_name", "Land2"));
        settlement_2.insert(std::make_pair("settlement_name", "Settlement2"));
        settlements.push_back(settlement_1);
        settlements.push_back(settlement_2);
        m_command = m_builder.buildGetSettlementsReply(1, "Message", settlements);
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::ReplyBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorGetSettlementsReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorGetSettlementsReplyTranslation, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("41", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetSettlementsReplyTranslation, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetSettlementsReplyTranslation, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetSettlementsReplyTranslation, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_settlements_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(LanguageToProtocolTranslatorGetSettlementsReplyTranslation, SetsProperObjects)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_settlements_reply")->getChildElement("settlements");

    // TODO: Extend testing.
}

class LanguageToProtocolTranslatorBuildBuildingReplyTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorBuildBuildingReplyTranslation()
        : m_command(m_builder.buildBuildBuildingReply(1, "Message"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::ReplyBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorBuildBuildingReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorBuildBuildingReplyTranslation, SetsProperReplyID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("42", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorBuildBuildingReplyTranslation, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorBuildBuildingReplyTranslation, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorBuildBuildingReplyTranslation, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("build_building_reply");
    ASSERT_TRUE(element != NULL);
}

class LanguageToProtocolTranslatorDestroyBuildingReplyTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorDestroyBuildingReplyTranslation()
        : m_command(m_builder.buildDestroyBuildingReply(1, "Message"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::ReplyBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorDestroyBuildingReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorDestroyBuildingReplyTranslation, SetsProperReplyID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("43", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorDestroyBuildingReplyTranslation, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorDestroyBuildingReplyTranslation, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorDestroyBuildingReplyTranslation, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("destroy_building_reply");
    ASSERT_TRUE(element != NULL);
}

class LanguageToProtocolTranslatorGetBuildingReplyTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorGetBuildingReplyTranslation()
    {
        TUSLanguage::ICommand::Object building;
        building.insert(std::make_pair("buildingclass", "Regular"));
        building.insert(std::make_pair("buildingname", "Farm"));
        building.insert(std::make_pair("volume", "10"));
        m_command = m_builder.buildGetBuildingReply(1, "Message", building);
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::ReplyBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorGetBuildingReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorGetBuildingReplyTranslation, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("44", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetBuildingReplyTranslation, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetBuildingReplyTranslation, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetBuildingReplyTranslation, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_building_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(LanguageToProtocolTranslatorGetBuildingReplyTranslation, SetsProperObject)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_building_reply")->getChildElement("building");
    ASSERT_STREQ("Regular", element->getChildElement("buildingclass")->innerText().c_str());
    ASSERT_STREQ("Farm", element->getChildElement("buildingname")->innerText().c_str());
    ASSERT_STREQ("10", element->getChildElement("volume")->innerText().c_str());
}

class LanguageToProtocolTranslatorGetBuildingsReplyTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorGetBuildingsReplyTranslation()
    {
        TUSLanguage::ICommand::Object building_1, building_2;
        TUSLanguage::ICommand::Objects buildings;
        building_1.insert(std::make_pair("buildingclass", "Regular"));
        building_1.insert(std::make_pair("buildingname", "Farm"));
        building_1.insert(std::make_pair("volume", "10"));
        building_2.insert(std::make_pair("buildingclass", "Regular"));
        building_2.insert(std::make_pair("buildingname", "Sawmill"));
        building_2.insert(std::make_pair("volume", "20"));
        buildings.push_back(building_1);
        buildings.push_back(building_2);
        m_command = m_builder.buildGetBuildingsReply(1, "Message", buildings);
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::ReplyBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorGetBuildingsReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorGetBuildingsReplyTranslation, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("45", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetBuildingsReplyTranslation, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetBuildingsReplyTranslation, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetBuildingsReplyTranslation, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_buildings_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(LanguageToProtocolTranslatorGetBuildingsReplyTranslation, SetsProperObjects)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_buildings_reply")->getChildElement("buildings");

    // TODO: Extend testing.
}

class LanguageToProtocolTranslatorDismissHumanReplyTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorDismissHumanReplyTranslation()
        : m_command(m_builder.buildDismissHumanReply(1, "Message"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::ReplyBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorDismissHumanReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorDismissHumanReplyTranslation, SetsProperReplyID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("46", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorDismissHumanReplyTranslation, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorDismissHumanReplyTranslation, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorDismissHumanReplyTranslation, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("dismiss_human_reply");
    ASSERT_TRUE(element != NULL);
}

class LanguageToProtocolTranslatorEngageHumanReplyTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorEngageHumanReplyTranslation()
        : m_command(m_builder.buildEngageHumanReply(1, "Message"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::ReplyBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorEngageHumanReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorEngageHumanReplyTranslation, SetsProperReplyID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("47", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorEngageHumanReplyTranslation, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorEngageHumanReplyTranslation, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorEngageHumanReplyTranslation, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("engage_human_reply");
    ASSERT_TRUE(element != NULL);
}

class LanguageToProtocolTranslatorGetHumanReplyTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorGetHumanReplyTranslation()
    {
        TUSLanguage::ICommand::Object human;
        human.insert(std::make_pair("humanclass", "Worker"));
        human.insert(std::make_pair("humanname", "Farmer"));
        human.insert(std::make_pair("experience", "Novice"));
        human.insert(std::make_pair("volume", "10"));
        m_command = m_builder.buildGetHumanReply(1, "Message", human);
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::ReplyBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorGetHumanReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorGetHumanReplyTranslation, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("48", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetHumanReplyTranslation, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetHumanReplyTranslation, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetHumanReplyTranslation, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_human_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(LanguageToProtocolTranslatorGetHumanReplyTranslation, CreateGetHumanReplySetsProperObject)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_human_reply")->getChildElement("human");
    ASSERT_STREQ("Worker", element->getChildElement("humanclass")->innerText().c_str());
    ASSERT_STREQ("Farmer", element->getChildElement("humanname")->innerText().c_str());
    ASSERT_STREQ("Novice", element->getChildElement("experience")->innerText().c_str());
    ASSERT_STREQ("10", element->getChildElement("volume")->innerText().c_str());
}

class LanguageToProtocolTranslatorGetHumansReplyTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorGetHumansReplyTranslation()
    {
        TUSLanguage::ICommand::Object human_1, human_2;
        TUSLanguage::ICommand::Objects humans;
        human_1.insert(std::make_pair("humanclass", "Worker"));
        human_1.insert(std::make_pair("humanname", "Farmer"));
        human_1.insert(std::make_pair("experience", "Novice"));
        human_1.insert(std::make_pair("volume", "10"));
        human_2.insert(std::make_pair("humanclass", "Worker"));
        human_2.insert(std::make_pair("humanname", "Steelworker"));
        human_2.insert(std::make_pair("experience", "Advanced"));
        human_2.insert(std::make_pair("volume", "20"));
        humans.push_back(human_1);
        humans.push_back(human_2);
        m_command = m_builder.buildGetHumansReply(1, "Message", humans);
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::ReplyBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorGetHumansReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorGetHumansReplyTranslation, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("49", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetHumansReplyTranslation, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetHumansReplyTranslation, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetHumansReplyTranslation, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_humans_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(LanguageToProtocolTranslatorGetHumansReplyTranslation, SetsProperObjects)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_humans_reply")->getChildElement("humans");

    // TODO: Extend testing.
}

class LanguageToProtocolTranslatorGetResourceReplyTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorGetResourceReplyTranslation()
    {
        TUSLanguage::ICommand::Object resource;
        resource.insert(std::make_pair("resourcename", "Coal"));
        resource.insert(std::make_pair("volume", "10"));
        m_command = m_builder.buildGetResourceReply(1, "Message", resource);
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::ReplyBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorGetResourceReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorGetResourceReplyTranslation, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("50", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetResourceReplyTranslation, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetResourceReplyTranslation, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetResourceReplyTranslation, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_resource_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(LanguageToProtocolTranslatorGetResourceReplyTranslation, SetsProperObject)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_resource_reply")->getChildElement("resource");
    ASSERT_STREQ("Coal", element->getChildElement("resourcename")->innerText().c_str());
    ASSERT_STREQ("10", element->getChildElement("volume")->innerText().c_str());
}

class LanguageToProtocolTranslatorGetResourcesReplyTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorGetResourcesReplyTranslation()
    {
        TUSLanguage::ICommand::Object resource_1, resource_2;
        TUSLanguage::ICommand::Objects resources;
        resource_1.insert(std::make_pair("resourcename", "Coal"));
        resource_1.insert(std::make_pair("volume", "10"));
        resource_2.insert(std::make_pair("resourcename", "Wood"));
        resource_2.insert(std::make_pair("volume", "20"));
        resources.push_back(resource_1);
        resources.push_back(resource_2);
        m_command = m_builder.buildGetResourcesReply(1, "Message", resources);
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::ReplyBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorGetResourcesReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorGetResourcesReplyTranslation, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("51", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetResourcesReplyTranslation, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetResourcesReplyTranslation, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetResourcesReplyTranslation, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_resources_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(LanguageToProtocolTranslatorGetResourcesReplyTranslation, SetsProperObjects)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_resources_reply")->getChildElement("resources");

    // TODO: Extend testing.
}

class LanguageToProtocolTranslatorCreateUserReplyTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorCreateUserReplyTranslation()
        : m_command(m_builder.buildCreateUserReply(1, "Message"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::ReplyBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorCreateUserReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorCreateUserReplyTranslation, SetsProperReplyID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("52", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorCreateUserReplyTranslation, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorCreateUserReplyTranslation, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorCreateUserReplyTranslation, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("create_user_reply");
    ASSERT_TRUE(element != NULL);
}

class LanguageToProtocolTranslatorCreateWorldReplyTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorCreateWorldReplyTranslation()
        : m_command(m_builder.buildCreateWorldReply(1, "Message"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::ReplyBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorCreateWorldReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorCreateWorldReplyTranslation, SetsProperReplyID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("53", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorCreateWorldReplyTranslation, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorCreateWorldReplyTranslation, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorCreateWorldReplyTranslation, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("create_world_reply");
    ASSERT_TRUE(element != NULL);
}

class LanguageToProtocolTranslatorCreateEpochReplyTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorCreateEpochReplyTranslation()
        : m_command(m_builder.buildCreateEpochReply(1, "Message"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::ReplyBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorCreateEpochReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorCreateEpochReplyTranslation, SetsProperReplyID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("54", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorCreateEpochReplyTranslation, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorCreateEpochReplyTranslation, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorCreateEpochReplyTranslation, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("create_epoch_reply");
    ASSERT_TRUE(element != NULL);
}

class LanguageToProtocolTranslatorDeleteEpochReplyTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorDeleteEpochReplyTranslation()
        : m_command(m_builder.buildDeleteEpochReply(1, "Message"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::ReplyBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorDeleteEpochReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorDeleteEpochReplyTranslation, SetsProperReplyID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("55", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorDeleteEpochReplyTranslation, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorDeleteEpochReplyTranslation, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorDeleteEpochReplyTranslation, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("delete_epoch_reply");
    ASSERT_TRUE(element != NULL);
}

class LanguageToProtocolTranslatorActivateEpochReplyTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorActivateEpochReplyTranslation()
        : m_command(m_builder.buildActivateEpochReply(1, "Message"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::ReplyBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorActivateEpochReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorActivateEpochReplyTranslation, SetsProperReplyID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("56", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorActivateEpochReplyTranslation, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorActivateEpochReplyTranslation, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorActivateEpochReplyTranslation, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("activate_epoch_reply");
    ASSERT_TRUE(element != NULL);
}

class LanguageToProtocolTranslatorDeactivateEpochReplyTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorDeactivateEpochReplyTranslation()
        : m_command(m_builder.buildDeactivateEpochReply(1, "Message"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::ReplyBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorDeactivateEpochReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorDeactivateEpochReplyTranslation, SetsProperReplyID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("57", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorDeactivateEpochReplyTranslation, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorDeactivateEpochReplyTranslation, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorDeactivateEpochReplyTranslation, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("deactivate_epoch_reply");
    ASSERT_TRUE(element != NULL);
}

class LanguageToProtocolTranslatorFinishEpochReplyTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorFinishEpochReplyTranslation()
        : m_command(m_builder.buildFinishEpochReply(1, "Message"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::ReplyBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorFinishEpochReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorFinishEpochReplyTranslation, SetsProperReplyID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("58", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorFinishEpochReplyTranslation, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorFinishEpochReplyTranslation, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorFinishEpochReplyTranslation, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("finish_epoch_reply");
    ASSERT_TRUE(element != NULL);
}

class LanguageToProtocolTranslatorTickEpochReplyTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorTickEpochReplyTranslation()
        : m_command(m_builder.buildTickEpochReply(1, "Message"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::ReplyBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorTickEpochReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorTickEpochReplyTranslation, SetsProperReplyID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("59", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorTickEpochReplyTranslation, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorTickEpochReplyTranslation, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorTickEpochReplyTranslation, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("tick_epoch_reply");
    ASSERT_TRUE(element != NULL);
}

class LanguageToProtocolTranslatorGetEpochReplyTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorGetEpochReplyTranslation()
    {
        TUSLanguage::ICommand::Object epoch;
        epoch.insert(std::make_pair("epoch_name", "Epoch"));
        epoch.insert(std::make_pair("world_name", "World"));
        epoch.insert(std::make_pair("active", "true"));
        epoch.insert(std::make_pair("finished", "false"));
        epoch.insert(std::make_pair("ticks", "22"));
        m_command = m_builder.buildGetEpochReply(1, "Message", epoch);
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::ReplyBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorGetEpochReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorGetEpochReplyTranslation, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("60", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetEpochReplyTranslation, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetEpochReplyTranslation, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorGetEpochReplyTranslation, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_epoch_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(LanguageToProtocolTranslatorGetEpochReplyTranslation, SetsProperObject)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_epoch_reply")->getChildElement("epoch");
    ASSERT_STREQ("Epoch", element->getChildElement("epoch_name")->innerText().c_str());
    ASSERT_STREQ("World", element->getChildElement("world_name")->innerText().c_str());
    ASSERT_STREQ("true", element->getChildElement("active")->innerText().c_str());
    ASSERT_STREQ("false", element->getChildElement("finished")->innerText().c_str());
    ASSERT_STREQ("22", element->getChildElement("ticks")->innerText().c_str());
}

class LanguageToProtocolTranslatorTransportHumanReplyTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorTransportHumanReplyTranslation()
        : m_command(m_builder.buildTransportHumanReply(1, "Message"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::ReplyBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorTransportHumanReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorTransportHumanReplyTranslation, SetsProperReplyID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("61", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorTransportHumanReplyTranslation, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorTransportHumanReplyTranslation, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorTransportHumanReplyTranslation, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("transport_human_reply");
    ASSERT_TRUE(element != NULL);
}

class LanguageToProtocolTranslatorTransportResourceReplyTranslation
    : public ::testing::Test
{
protected:
    LanguageToProtocolTranslatorTransportResourceReplyTranslation()
        : m_command(m_builder.buildTransportResourceReply(1, "Message"))
    {
        m_message = m_translator.translate(m_command);
    }

    TUSLanguage::ReplyBuilder m_builder;
    TUSProtocol::LanguageToProtocolTranslator m_translator;
    TUSLanguage::ICommand::Handle m_command;
    TUSProtocol::Message::Handle m_message;
};

TEST_F(LanguageToProtocolTranslatorTransportResourceReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(LanguageToProtocolTranslatorTransportResourceReplyTranslation, SetsProperReplyID)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("62", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorTransportResourceReplyTranslation, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorTransportResourceReplyTranslation, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(LanguageToProtocolTranslatorTransportResourceReplyTranslation, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("transport_resource_reply");
    ASSERT_TRUE(element != NULL);
}

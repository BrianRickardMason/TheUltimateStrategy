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

#include <Protocol/Xml/Cpp/MessageFactory.hpp>
#include <Protocol/Xml/Cpp/ProtocolToLanguageTranslator.hpp>
#include <gtest/gtest.h>

// TODO: Add UTs to verify thrown exceptions.

class ProtocolToLanguageTranslatorEchoRequestTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorEchoRequestTranslation()
        : m_message(m_factory.createEchoRequest())
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorEchoRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorEchoRequestTranslation, SetsProperID)
{
    ASSERT_EQ(1, m_command->getID());
}

class ProtocolToLanguageTranslatorErrorRequestTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorErrorRequestTranslation()
        : m_message(m_factory.createErrorRequest())
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorErrorRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorErrorRequestTranslation, SetsProperID)
{
    ASSERT_EQ(2, m_command->getID());
}

class ProtocolToLanguageTranslatorCreateLandRequestTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorCreateLandRequestTranslation()
        : m_message(m_factory.createCreateLandRequest("Login", "Password", "World", "Land"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorCreateLandRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorCreateLandRequestTranslation, SetsProperID)
{
    ASSERT_EQ(3, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorCreateLandRequestTranslation, SetsProperLogin)
{
    ASSERT_STREQ("Login", m_command->getLogin().c_str());
}

TEST_F(ProtocolToLanguageTranslatorCreateLandRequestTranslation, SetsProperPassword)
{
    ASSERT_STREQ("Password", m_command->getPassword().c_str());
}

TEST_F(ProtocolToLanguageTranslatorCreateLandRequestTranslation, SetsProperWorldName)
{
    ASSERT_STREQ("World", m_command->getParam("world_name").c_str());
}

TEST_F(ProtocolToLanguageTranslatorCreateLandRequestTranslation, SetsProperLandName)
{
    ASSERT_STREQ("Land", m_command->getParam("land_name").c_str());
}

class ProtocolToLanguageTranslatorDeleteLandRequestTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorDeleteLandRequestTranslation()
        : m_message(m_factory.createDeleteLandRequest("Login", "Password", "Land"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorDeleteLandRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorDeleteLandRequestTranslation, SetsProperID)
{
    ASSERT_EQ(4, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorDeleteLandRequestTranslation, SetsProperLogin)
{
    ASSERT_STREQ("Login", m_command->getLogin().c_str());
}

TEST_F(ProtocolToLanguageTranslatorDeleteLandRequestTranslation, SetsProperPassword)
{
    ASSERT_STREQ("Password", m_command->getPassword().c_str());
}

TEST_F(ProtocolToLanguageTranslatorDeleteLandRequestTranslation, SetsProperLandName)
{
    ASSERT_STREQ("Land", m_command->getParam("land_name").c_str());
}

class ProtocolToLanguageTranslatorGetLandRequestTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorGetLandRequestTranslation()
        : m_message(m_factory.createGetLandRequest("Login", "Password", "Land"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorGetLandRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorGetLandRequestTranslation, SetsProperID)
{
    ASSERT_EQ(5, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorGetLandRequestTranslation, SetsProperLogin)
{
    ASSERT_STREQ("Login", m_command->getLogin().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetLandRequestTranslation, SetsProperPassword)
{
    ASSERT_STREQ("Password", m_command->getPassword().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetLandRequestTranslation, SetsProperLandName)
{
    ASSERT_STREQ("Land", m_command->getParam("land_name").c_str());
}

class ProtocolToLanguageTranslatorGetLandsRequestTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorGetLandsRequestTranslation()
        : m_message(m_factory.createGetLandsRequest("Login", "Password"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorGetLandsRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorGetLandsRequestTranslation, SetsProperID)
{
    ASSERT_EQ(6, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorGetLandsRequestTranslation, SetsProperLogin)
{
    ASSERT_STREQ("Login", m_command->getLogin().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetLandsRequestTranslation, SetsProperPassword)
{
    ASSERT_STREQ("Password", m_command->getPassword().c_str());
}

class ProtocolToLanguageTranslatorCreateSettlementRequestTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorCreateSettlementRequestTranslation()
        : m_message(m_factory.createCreateSettlementRequest("Login", "Password", "Land", "Settlement"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorCreateSettlementRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorCreateSettlementRequestTranslation, SetsProperID)
{
    ASSERT_EQ(7, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorCreateSettlementRequestTranslation, SetsProperLogin)
{
    ASSERT_STREQ("Login", m_command->getLogin().c_str());
}

TEST_F(ProtocolToLanguageTranslatorCreateSettlementRequestTranslation, SetsProperPassword)
{
    ASSERT_STREQ("Password", m_command->getPassword().c_str());
}

TEST_F(ProtocolToLanguageTranslatorCreateSettlementRequestTranslation, SetsProperLandName)
{
    ASSERT_STREQ("Land", m_command->getParam("land_name").c_str());
}

TEST_F(ProtocolToLanguageTranslatorCreateSettlementRequestTranslation, SetsProperSettlementName)
{
    ASSERT_STREQ("Settlement", m_command->getParam("settlement_name").c_str());
}

class ProtocolToLanguageTranslatorDeleteSettlementRequestTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorDeleteSettlementRequestTranslation()
        : m_message(m_factory.createDeleteSettlementRequest("Login", "Password", "Settlement"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorDeleteSettlementRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorDeleteSettlementRequestTranslation, SetsProperID)
{
    ASSERT_EQ(8, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorDeleteSettlementRequestTranslation, SetsProperLogin)
{
    ASSERT_STREQ("Login", m_command->getLogin().c_str());
}

TEST_F(ProtocolToLanguageTranslatorDeleteSettlementRequestTranslation, SetsProperPassword)
{
    ASSERT_STREQ("Password", m_command->getPassword().c_str());
}

TEST_F(ProtocolToLanguageTranslatorDeleteSettlementRequestTranslation, SetsProperSettlementName)
{
    ASSERT_STREQ("Settlement", m_command->getParam("settlement_name").c_str());
}

class ProtocolToLanguageTranslatorGetSettlementRequestTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorGetSettlementRequestTranslation()
        : m_message(m_factory.createGetSettlementRequest("Login", "Password", "Settlement"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorGetSettlementRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorGetSettlementRequestTranslation, SetsProperID)
{
    ASSERT_EQ(9, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorGetSettlementRequestTranslation, SetsProperLogin)
{
    ASSERT_STREQ("Login", m_command->getLogin().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetSettlementRequestTranslation, SetsProperPassword)
{
    ASSERT_STREQ("Password", m_command->getPassword().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetSettlementRequestTranslation, SetsProperSettlementName)
{
    ASSERT_STREQ("Settlement", m_command->getParam("settlement_name").c_str());
}

class ProtocolToLanguageTranslatorGetSettlementsRequestTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorGetSettlementsRequestTranslation()
        : m_message(m_factory.createGetSettlementsRequest("Login", "Password", "Land"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorGetSettlementsRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorGetSettlementsRequestTranslation, SetsProperID)
{
    ASSERT_EQ(10, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorGetSettlementsRequestTranslation, SetsProperLogin)
{
    ASSERT_STREQ("Login", m_command->getLogin().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetSettlementsRequestTranslation, SetsProperPassword)
{
    ASSERT_STREQ("Password", m_command->getPassword().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetSettlementsRequestTranslation, SetsProperLandName)
{
    ASSERT_STREQ("Land", m_command->getParam("land_name").c_str());
}

class ProtocolToLanguageTranslatorBuildBuildingRequestTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorBuildBuildingRequestTranslation()
        : m_message(m_factory.createBuildBuildingRequest(
              "Login", "Password", "HolderClassSettlement", "Settlement", "RegularForge", "100"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorBuildBuildingRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorBuildBuildingRequestTranslation, SetsProperID)
{
    ASSERT_EQ(11, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorBuildBuildingRequestTranslation, SetsProperLogin)
{
    ASSERT_STREQ("Login", m_command->getLogin().c_str());
}

TEST_F(ProtocolToLanguageTranslatorBuildBuildingRequestTranslation, SetsProperPassword)
{
    ASSERT_STREQ("Password", m_command->getPassword().c_str());
}

TEST_F(ProtocolToLanguageTranslatorBuildBuildingRequestTranslation, SetsProperIDHolderClass)
{
    ASSERT_STREQ("HolderClassSettlement", m_command->getParam("idholderclass").c_str());
}

TEST_F(ProtocolToLanguageTranslatorBuildBuildingRequestTranslation, SetsProperHolderName)
{
    ASSERT_STREQ("Settlement", m_command->getParam("holder_name").c_str());
}

TEST_F(ProtocolToLanguageTranslatorBuildBuildingRequestTranslation, SetsProperBuildingKey)
{
    ASSERT_STREQ("RegularForge", m_command->getParam("buildingkey").c_str());
}

TEST_F(ProtocolToLanguageTranslatorBuildBuildingRequestTranslation, SetsProperVolume)
{
    ASSERT_STREQ("100", m_command->getParam("volume").c_str());
}

class ProtocolToLanguageTranslatorDestroyBuildingRequestTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorDestroyBuildingRequestTranslation()
        : m_message(m_factory.createDestroyBuildingRequest(
              "Login", "Password", "HolderClassSettlement", "Settlement", "RegularForge", "100"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorDestroyBuildingRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorDestroyBuildingRequestTranslation, SetsProperID)
{
    ASSERT_EQ(12, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorDestroyBuildingRequestTranslation, SetsProperLogin)
{
    ASSERT_STREQ("Login", m_command->getLogin().c_str());
}

TEST_F(ProtocolToLanguageTranslatorDestroyBuildingRequestTranslation, SetsProperPassword)
{
    ASSERT_STREQ("Password", m_command->getPassword().c_str());
}

TEST_F(ProtocolToLanguageTranslatorDestroyBuildingRequestTranslation, SetsProperIDHolderClass)
{
    ASSERT_STREQ("HolderClassSettlement", m_command->getParam("idholderclass").c_str());
}

TEST_F(ProtocolToLanguageTranslatorDestroyBuildingRequestTranslation, SetsProperHolderName)
{
    ASSERT_STREQ("Settlement", m_command->getParam("holder_name").c_str());
}

TEST_F(ProtocolToLanguageTranslatorDestroyBuildingRequestTranslation, SetsProperBuildingKey)
{
    ASSERT_STREQ("RegularForge", m_command->getParam("buildingkey").c_str());
}

TEST_F(ProtocolToLanguageTranslatorDestroyBuildingRequestTranslation, SetsProperVolume)
{
    ASSERT_STREQ("100", m_command->getParam("volume").c_str());
}

class ProtocolToLanguageTranslatorGetBuildingRequestTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorGetBuildingRequestTranslation()
        : m_message(m_factory.createGetBuildingRequest(
              "Login", "Password", "HolderClassSettlement", "Settlement", "RegularForge"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorGetBuildingRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorGetBuildingRequestTranslation, SetsProperID)
{
    ASSERT_EQ(13, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorGetBuildingRequestTranslation, SetsProperLogin)
{
    ASSERT_STREQ("Login", m_command->getLogin().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetBuildingRequestTranslation, SetsProperPassword)
{
    ASSERT_STREQ("Password", m_command->getPassword().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetBuildingRequestTranslation, SetsProperIDHolderClass)
{
    ASSERT_STREQ("HolderClassSettlement", m_command->getParam("idholderclass").c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetBuildingRequestTranslation, SetsProperHolderName)
{
    ASSERT_STREQ("Settlement", m_command->getParam("holder_name").c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetBuildingRequestTranslation, SetsProperBuildingKey)
{
    ASSERT_STREQ("RegularForge", m_command->getParam("buildingkey").c_str());
}

class ProtocolToLanguageTranslatorGetBuildingsRequestTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorGetBuildingsRequestTranslation()
        : m_message(m_factory.createGetBuildingsRequest("Login", "Password", "HolderClassSettlement", "Settlement"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorGetBuildingsRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorGetBuildingsRequestTranslation, SetsProperID)
{
    ASSERT_EQ(14, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorGetBuildingsRequestTranslation, SetsProperLogin)
{
    ASSERT_STREQ("Login", m_command->getLogin().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetBuildingsRequestTranslation, SetsProperPassword)
{
    ASSERT_STREQ("Password", m_command->getPassword().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetBuildingsRequestTranslation, SetsProperIDHolderClass)
{
    ASSERT_STREQ("HolderClassSettlement", m_command->getParam("idholderclass").c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetBuildingsRequestTranslation, SetsProperHolderName)
{
    ASSERT_STREQ("Settlement", m_command->getParam("holder_name").c_str());
}

class ProtocolToLanguageTranslatorDismissHumanRequestTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorDismissHumanRequestTranslation()
        : m_message(m_factory.createDismissHumanRequest(
                "Login", "Password", "HolderClassSettlement", "Settlement", "WorkerBlacksmithNovice", "100"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorDismissHumanRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorDismissHumanRequestTranslation, SetsProperID)
{
    ASSERT_EQ(15, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorDismissHumanRequestTranslation, SetsProperLogin)
{
    ASSERT_STREQ("Login", m_command->getLogin().c_str());
}

TEST_F(ProtocolToLanguageTranslatorDismissHumanRequestTranslation, SetsProperPassword)
{
    ASSERT_STREQ("Password", m_command->getPassword().c_str());
}

TEST_F(ProtocolToLanguageTranslatorDismissHumanRequestTranslation, SetsProperIDHolderClass)
{
    ASSERT_STREQ("HolderClassSettlement", m_command->getParam("idholderclass").c_str());
}

TEST_F(ProtocolToLanguageTranslatorDismissHumanRequestTranslation, SetsProperHolderName)
{
    ASSERT_STREQ("Settlement", m_command->getParam("holder_name").c_str());
}

TEST_F(ProtocolToLanguageTranslatorDismissHumanRequestTranslation, SetsProperHumanKey)
{
    ASSERT_STREQ("WorkerBlacksmithNovice", m_command->getParam("humankey").c_str());
}

TEST_F(ProtocolToLanguageTranslatorDismissHumanRequestTranslation, SetsProperVolume)
{
    ASSERT_STREQ("100", m_command->getParam("volume").c_str());
}

class ProtocolToLanguageTranslatorEngageHumanRequestTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorEngageHumanRequestTranslation()
        : m_message(m_factory.createEngageHumanRequest(
                "Login", "Password", "HolderClassSettlement", "Settlement", "WorkerBlacksmithNovice", "100"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorEngageHumanRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorEngageHumanRequestTranslation, SetsProperID)
{
    ASSERT_EQ(16, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorEngageHumanRequestTranslation, SetsProperLogin)
{
    ASSERT_STREQ("Login", m_command->getLogin().c_str());
}

TEST_F(ProtocolToLanguageTranslatorEngageHumanRequestTranslation, SetsProperPassword)
{
    ASSERT_STREQ("Password", m_command->getPassword().c_str());
}

TEST_F(ProtocolToLanguageTranslatorEngageHumanRequestTranslation, SetsProperIDHolderClass)
{
    ASSERT_STREQ("HolderClassSettlement", m_command->getParam("idholderclass").c_str());
}

TEST_F(ProtocolToLanguageTranslatorEngageHumanRequestTranslation, SetsProperHolderName)
{
    ASSERT_STREQ("Settlement", m_command->getParam("holder_name").c_str());
}

TEST_F(ProtocolToLanguageTranslatorEngageHumanRequestTranslation, SetsProperHumanKey)
{
    ASSERT_STREQ("WorkerBlacksmithNovice", m_command->getParam("humankey").c_str());
}

TEST_F(ProtocolToLanguageTranslatorEngageHumanRequestTranslation, SetsProperVolume)
{
    ASSERT_STREQ("100", m_command->getParam("volume").c_str());
}

class ProtocolToLanguageTranslatorGetHumanRequestTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorGetHumanRequestTranslation()
        : m_message(m_factory.createGetHumanRequest(
              "Login", "Password", "HolderClassSettlement", "Settlement", "WorkerBlacksmithNovice"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorGetHumanRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorGetHumanRequestTranslation, SetsProperID)
{
    ASSERT_EQ(17, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorGetHumanRequestTranslation, SetsProperLogin)
{
    ASSERT_STREQ("Login", m_command->getLogin().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetHumanRequestTranslation, SetsProperPassword)
{
    ASSERT_STREQ("Password", m_command->getPassword().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetHumanRequestTranslation, SetsProperIDHolderClass)
{
    ASSERT_STREQ("HolderClassSettlement", m_command->getParam("idholderclass").c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetHumanRequestTranslation, SetsProperHolderName)
{
    ASSERT_STREQ("Settlement", m_command->getParam("holder_name").c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetHumanRequestTranslation, SetsProperHumanKey)
{
    ASSERT_STREQ("WorkerBlacksmithNovice", m_command->getParam("humankey").c_str());
}

class ProtocolToLanguageTranslatorGetHumansRequestTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorGetHumansRequestTranslation()
        : m_message(m_factory.createGetHumansRequest("Login", "Password", "HolderClassSettlement", "Settlement"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorGetHumansRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorGetHumansRequestTranslation, SetsProperID)
{
    ASSERT_EQ(18, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorGetHumansRequestTranslation, SetsProperLogin)
{
    ASSERT_STREQ("Login", m_command->getLogin().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetHumansRequestTranslation, SetsProperPassword)
{
    ASSERT_STREQ("Password", m_command->getPassword().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetHumansRequestTranslation, SetsProperIDHolderClass)
{
    ASSERT_STREQ("HolderClassSettlement", m_command->getParam("idholderclass").c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetHumansRequestTranslation, SetsProperHolderName)
{
    ASSERT_STREQ("Settlement", m_command->getParam("holder_name").c_str());
}

class ProtocolToLanguageTranslatorGetResourceRequestTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorGetResourceRequestTranslation()
        : m_message(m_factory.createGetResourceRequest(
              "Login", "Password", "HolderClassSettlement", "Settlement", "Coal"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorGetResourceRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorGetResourceRequestTranslation, SetsProperID)
{
    ASSERT_EQ(19, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorGetResourceRequestTranslation, SetsProperLogin)
{
    ASSERT_STREQ("Login", m_command->getLogin().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetResourceRequestTranslation, SetsProperPassword)
{
    ASSERT_STREQ("Password", m_command->getPassword().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetResourceRequestTranslation, SetsProperIDHolderClass)
{
    ASSERT_STREQ("HolderClassSettlement", m_command->getParam("idholderclass").c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetResourceRequestTranslation, SetsProperHolderName)
{
    ASSERT_STREQ("Settlement", m_command->getParam("holder_name").c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetResourceRequestTranslation, SetsProperResourceKey)
{
    ASSERT_STREQ("Coal", m_command->getParam("resourcekey").c_str());
}

class ProtocolToLanguageTranslatorGetResourcesRequestTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorGetResourcesRequestTranslation()
        : m_message(m_factory.createGetResourcesRequest("Login", "Password", "HolderClassSettlement", "Settlement"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorGetResourcesRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorGetResourcesRequestTranslation, SetsProperID)
{
    ASSERT_EQ(20, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorGetResourcesRequestTranslation, SetsProperLogin)
{
    ASSERT_STREQ("Login", m_command->getLogin().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetResourcesRequestTranslation, SetsProperPassword)
{
    ASSERT_STREQ("Password", m_command->getPassword().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetResourcesRequestTranslation, SetsProperIDHolderClass)
{
    ASSERT_STREQ("HolderClassSettlement", m_command->getParam("idholderclass").c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetResourcesRequestTranslation, SetsProperHolderName)
{
    ASSERT_STREQ("Settlement", m_command->getParam("holder_name").c_str());
}

class ProtocolToLanguageTranslatorCreateUserRequestTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorCreateUserRequestTranslation()
        : m_message(m_factory.createCreateUserRequest("Login", "Password"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorCreateUserRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorCreateUserRequestTranslation, SetsProperID)
{
    ASSERT_EQ(21, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorCreateUserRequestTranslation, DoesNotSetLogin)
{
    ASSERT_STREQ("", m_command->getLogin().c_str());
}

TEST_F(ProtocolToLanguageTranslatorCreateUserRequestTranslation, DoesNotSetPassword)
{
    ASSERT_STREQ("", m_command->getPassword().c_str());
}

TEST_F(ProtocolToLanguageTranslatorCreateUserRequestTranslation, SetsProperLogin)
{
    ASSERT_STREQ("Login", m_command->getParam("login").c_str());
}

TEST_F(ProtocolToLanguageTranslatorCreateUserRequestTranslation, SetsProperPassword)
{
    ASSERT_STREQ("Password", m_command->getParam("password").c_str());
}

class ProtocolToLanguageTranslatorCreateWorldRequestTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorCreateWorldRequestTranslation()
        : m_message(m_factory.createCreateWorldRequest("Login", "Password", "World"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorCreateWorldRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorCreateWorldRequestTranslation, SetsProperID)
{
    ASSERT_EQ(22, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorCreateWorldRequestTranslation, SetsProperLogin)
{
    ASSERT_STREQ("Login", m_command->getLogin().c_str());
}

TEST_F(ProtocolToLanguageTranslatorCreateWorldRequestTranslation, SetsProperPassword)
{
    ASSERT_STREQ("Password", m_command->getPassword().c_str());
}

TEST_F(ProtocolToLanguageTranslatorCreateWorldRequestTranslation, SetsProperWorldName)
{
    ASSERT_STREQ("World", m_command->getParam("world_name").c_str());
}

class ProtocolToLanguageTranslatorCreateEpochRequestTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorCreateEpochRequestTranslation()
        : m_message(m_factory.createCreateEpochRequest("Login", "Password", "World", "Epoch"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorCreateEpochRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorCreateEpochRequestTranslation, SetsProperID)
{
    ASSERT_EQ(23, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorCreateEpochRequestTranslation, SetsProperLogin)
{
    ASSERT_STREQ("Login", m_command->getLogin().c_str());
}

TEST_F(ProtocolToLanguageTranslatorCreateEpochRequestTranslation, SetsProperPassword)
{
    ASSERT_STREQ("Password", m_command->getPassword().c_str());
}

TEST_F(ProtocolToLanguageTranslatorCreateEpochRequestTranslation, SetsProperWorldName)
{
    ASSERT_STREQ("World", m_command->getParam("world_name").c_str());
}

TEST_F(ProtocolToLanguageTranslatorCreateEpochRequestTranslation, SetsProperEpochName)
{
    ASSERT_STREQ("Epoch", m_command->getParam("epoch_name").c_str());
}

class ProtocolToLanguageTranslatorDeleteEpochRequestTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorDeleteEpochRequestTranslation()
        : m_message(m_factory.createDeleteEpochRequest("Login", "Password", "World"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorDeleteEpochRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorDeleteEpochRequestTranslation, SetsProperID)
{
    ASSERT_EQ(24, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorDeleteEpochRequestTranslation, SetsProperLogin)
{
    ASSERT_STREQ("Login", m_command->getLogin().c_str());
}

TEST_F(ProtocolToLanguageTranslatorDeleteEpochRequestTranslation, SetsProperPassword)
{
    ASSERT_STREQ("Password", m_command->getPassword().c_str());
}

TEST_F(ProtocolToLanguageTranslatorDeleteEpochRequestTranslation, SetsProperWorldName)
{
    ASSERT_STREQ("World", m_command->getParam("world_name").c_str());
}

class ProtocolToLanguageTranslatorActivateEpochRequestTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorActivateEpochRequestTranslation()
        : m_message(m_factory.createActivateEpochRequest("Login", "Password", "World"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorActivateEpochRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorActivateEpochRequestTranslation, SetsProperID)
{
    ASSERT_EQ(25, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorActivateEpochRequestTranslation, SetsProperLogin)
{
    ASSERT_STREQ("Login", m_command->getLogin().c_str());
}

TEST_F(ProtocolToLanguageTranslatorActivateEpochRequestTranslation, SetsProperPassword)
{
    ASSERT_STREQ("Password", m_command->getPassword().c_str());
}

TEST_F(ProtocolToLanguageTranslatorActivateEpochRequestTranslation, SetsProperWorldName)
{
    ASSERT_STREQ("World", m_command->getParam("world_name").c_str());
}

class ProtocolToLanguageTranslatorDeactivateEpochRequestTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorDeactivateEpochRequestTranslation()
        : m_message(m_factory.createDeactivateEpochRequest("Login", "Password", "World"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorDeactivateEpochRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorDeactivateEpochRequestTranslation, SetsProperID)
{
    ASSERT_EQ(26, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorDeactivateEpochRequestTranslation, SetsProperLogin)
{
    ASSERT_STREQ("Login", m_command->getLogin().c_str());
}

TEST_F(ProtocolToLanguageTranslatorDeactivateEpochRequestTranslation, SetsProperPassword)
{
    ASSERT_STREQ("Password", m_command->getPassword().c_str());
}

TEST_F(ProtocolToLanguageTranslatorDeactivateEpochRequestTranslation, SetsProperWorldName)
{
    ASSERT_STREQ("World", m_command->getParam("world_name").c_str());
}

class ProtocolToLanguageTranslatorFinishEpochRequestTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorFinishEpochRequestTranslation()
        : m_message(m_factory.createFinishEpochRequest("Login", "Password", "World"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorFinishEpochRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorFinishEpochRequestTranslation, SetsProperID)
{
    ASSERT_EQ(27, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorFinishEpochRequestTranslation, SetsProperLogin)
{
    ASSERT_STREQ("Login", m_command->getLogin().c_str());
}

TEST_F(ProtocolToLanguageTranslatorFinishEpochRequestTranslation, SetsProperPassword)
{
    ASSERT_STREQ("Password", m_command->getPassword().c_str());
}

TEST_F(ProtocolToLanguageTranslatorFinishEpochRequestTranslation, SetsProperWorldName)
{
    ASSERT_STREQ("World", m_command->getParam("world_name").c_str());
}

class ProtocolToLanguageTranslatorTickEpochRequestTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorTickEpochRequestTranslation()
        : m_message(m_factory.createTickEpochRequest("Login", "Password", "World"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorTickEpochRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorTickEpochRequestTranslation, SetsProperID)
{
    ASSERT_EQ(28, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorTickEpochRequestTranslation, SetsProperLogin)
{
    ASSERT_STREQ("Login", m_command->getLogin().c_str());
}

TEST_F(ProtocolToLanguageTranslatorTickEpochRequestTranslation, SetsProperPassword)
{
    ASSERT_STREQ("Password", m_command->getPassword().c_str());
}

TEST_F(ProtocolToLanguageTranslatorTickEpochRequestTranslation, SetsProperWorldName)
{
    ASSERT_STREQ("World", m_command->getParam("world_name").c_str());
}

class ProtocolToLanguageTranslatorGetEpochRequestTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorGetEpochRequestTranslation()
        : m_message(m_factory.createGetEpochRequest("Login", "Password", "World"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorGetEpochRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorGetEpochRequestTranslation, SetsProperID)
{
    ASSERT_EQ(29, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorGetEpochRequestTranslation, SetsProperLogin)
{
    ASSERT_STREQ("Login", m_command->getLogin().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetEpochRequestTranslation, SetsProperPassword)
{
    ASSERT_STREQ("Password", m_command->getPassword().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetEpochRequestTranslation, SetsProperWorldName)
{
    ASSERT_STREQ("World", m_command->getParam("world_name").c_str());
}

class ProtocolToLanguageTranslatorTransportHumanRequestTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorTransportHumanRequestTranslation()
        : m_message(m_factory.createTransportHumanRequest(
                "Login", "Password", "SettlementSource", "SettlementDestination", "WorkerBlacksmithNovice", "100"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorTransportHumanRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorTransportHumanRequestTranslation, SetsProperID)
{
    ASSERT_EQ(30, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorTransportHumanRequestTranslation, SetsProperLogin)
{
    ASSERT_STREQ("Login", m_command->getLogin().c_str());
}

TEST_F(ProtocolToLanguageTranslatorTransportHumanRequestTranslation, SetsProperPassword)
{
    ASSERT_STREQ("Password", m_command->getPassword().c_str());
}

TEST_F(ProtocolToLanguageTranslatorTransportHumanRequestTranslation, SetsProperSettlementNameSource)
{
    ASSERT_STREQ("SettlementSource", m_command->getParam("settlement_name_source").c_str());
}

TEST_F(ProtocolToLanguageTranslatorTransportHumanRequestTranslation, SetsProperSettlementNameDestination)
{
    ASSERT_STREQ("SettlementDestination", m_command->getParam("settlement_name_destination").c_str());
}

TEST_F(ProtocolToLanguageTranslatorTransportHumanRequestTranslation, SetsProperHumanKey)
{
    ASSERT_STREQ("WorkerBlacksmithNovice", m_command->getParam("humankey").c_str());
}

TEST_F(ProtocolToLanguageTranslatorTransportHumanRequestTranslation, SetsProperVolume)
{
    ASSERT_STREQ("100", m_command->getParam("volume").c_str());
}

class ProtocolToLanguageTranslatorTransportResourceRequestTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorTransportResourceRequestTranslation()
        : m_message(m_factory.createTransportResourceRequest(
                "Login", "Password", "SettlementSource", "SettlementDestination", "Coal", "100"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorTransportResourceRequestTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorTransportResourceRequestTranslation, SetsProperID)
{
    ASSERT_EQ(31, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorTransportResourceRequestTranslation, SetsProperLogin)
{
    ASSERT_STREQ("Login", m_command->getLogin().c_str());
}

TEST_F(ProtocolToLanguageTranslatorTransportResourceRequestTranslation, SetsProperPassword)
{
    ASSERT_STREQ("Password", m_command->getPassword().c_str());
}

TEST_F(ProtocolToLanguageTranslatorTransportResourceRequestTranslation, SetsProperSettlementNameSource)
{
    ASSERT_STREQ("SettlementSource", m_command->getParam("settlement_name_source").c_str());
}

TEST_F(ProtocolToLanguageTranslatorTransportResourceRequestTranslation, SetsProperSettlementNameDestination)
{
    ASSERT_STREQ("SettlementDestination", m_command->getParam("settlement_name_destination").c_str());
}

TEST_F(ProtocolToLanguageTranslatorTransportResourceRequestTranslation, SetsProperResourceKey)
{
    ASSERT_STREQ("Coal", m_command->getParam("resourcekey").c_str());
}

TEST_F(ProtocolToLanguageTranslatorTransportResourceRequestTranslation, SetsProperVolume)
{
    ASSERT_STREQ("100", m_command->getParam("volume").c_str());
}

class ProtocolToLanguageTranslatorEchoReplyTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorEchoReplyTranslation()
        : m_message(m_factory.createEchoReply("1"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorEchoReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorEchoReplyTranslation, SetsProperReplyID)
{
    ASSERT_EQ(32, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorEchoReplyTranslation, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

class ProtocolToLanguageTranslatorErrorReplyTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorErrorReplyTranslation()
        : m_message(m_factory.createErrorReply("1"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorErrorReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorErrorReplyTranslation, SetsProperReplyID)
{
    ASSERT_EQ(33, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorErrorReplyTranslation, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

class ProtocolToLanguageTranslatorCreateLandReplyTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorCreateLandReplyTranslation()
        : m_message(m_factory.createCreateLandReply("1", "Message"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorCreateLandReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorCreateLandReplyTranslation, SetsProperReplyID)
{
    ASSERT_EQ(34, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorCreateLandReplyTranslation, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ProtocolToLanguageTranslatorCreateLandReplyTranslation, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

class ProtocolToLanguageTranslatorDeleteLandReplyTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorDeleteLandReplyTranslation()
        : m_message(m_factory.createDeleteLandReply("1", "Message"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorDeleteLandReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorDeleteLandReplyTranslation, SetsProperReplyID)
{
    ASSERT_EQ(35, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorDeleteLandReplyTranslation, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ProtocolToLanguageTranslatorDeleteLandReplyTranslation, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

class ProtocolToLanguageTranslatorGetLandReplyWithoutObjectTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorGetLandReplyWithoutObjectTranslation()
    {
        TUSProtocol::MessageFactory factory;
        TUSProtocol::ProtocolToLanguageTranslator translator;
        TUSProtocol::Message::Handle message = factory.createGetLandReply("1", "Message");
        m_command = translator.translate(message);
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorGetLandReplyWithoutObjectTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorGetLandReplyWithoutObjectTranslation, SetsProperID)
{
    ASSERT_EQ(36, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorGetLandReplyWithoutObjectTranslation, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ProtocolToLanguageTranslatorGetLandReplyWithoutObjectTranslation, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetLandReplyWithoutObjectTranslation, SetsProperNumberOfObjects)
{
    ASSERT_EQ(0, m_command->getObjects().size());
}

class ProtocolToLanguageTranslatorGetLandReplyWithObjectTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorGetLandReplyWithObjectTranslation()
    {
        TUSProtocol::MessageFactory factory;
        TUSProtocol::ProtocolToLanguageTranslator translator;
        TUSProtocol::Message::Object land;
        land.insert(std::make_pair("login", "Login1"));
        land.insert(std::make_pair("world_name", "World1"));
        land.insert(std::make_pair("land_name", "Land1"));
        land.insert(std::make_pair("granted", "false"));
        TUSProtocol::Message::Handle message = factory.createGetLandReply("1", "Message", land);
        m_command = translator.translate(message);
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorGetLandReplyWithObjectTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorGetLandReplyWithObjectTranslation, SetsProperID)
{
    ASSERT_EQ(36, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorGetLandReplyWithObjectTranslation, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ProtocolToLanguageTranslatorGetLandReplyWithObjectTranslation, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetLandReplyWithObjectTranslation, SetsProperNumberOfObjects)
{
    ASSERT_EQ(1, m_command->getObjects().size());
}

TEST_F(ProtocolToLanguageTranslatorGetLandReplyWithObjectTranslation, SetsProperObject)
{
    TUSLanguage::ICommand::Objects objects = m_command->getObjects();
    TUSLanguage::ICommand::Object object = objects.front();
    ASSERT_STREQ("Login1", object.at("login").c_str());
    ASSERT_STREQ("World1", object.at("world_name").c_str());
    ASSERT_STREQ("Land1", object.at("land_name").c_str());
    ASSERT_STREQ("false", object.at("granted").c_str());
}

class ProtocolToLanguageTranslatorGetLandsReplyWithoutObjectsTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorGetLandsReplyWithoutObjectsTranslation()
    {
        TUSProtocol::MessageFactory factory;
        TUSProtocol::ProtocolToLanguageTranslator translator;
        TUSProtocol::Message::Handle message = factory.createGetLandsReply("1", "Message");
        m_command = translator.translate(message);
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorGetLandsReplyWithoutObjectsTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorGetLandsReplyWithoutObjectsTranslation, SetsProperID)
{
    ASSERT_EQ(37, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorGetLandsReplyWithoutObjectsTranslation, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ProtocolToLanguageTranslatorGetLandsReplyWithoutObjectsTranslation, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetLandsReplyWithoutObjectsTranslation, SetsProperNumberOfObjects)
{
    ASSERT_EQ(0, m_command->getObjects().size());
}

class ProtocolToLanguageTranslatorGetLandsReplyWithObjectsTranslation
    : public ::testing::Test
{
protected:
            ProtocolToLanguageTranslatorGetLandsReplyWithObjectsTranslation()
    {
                TUSProtocol::MessageFactory factory;
                TUSProtocol::ProtocolToLanguageTranslator translator;
        TUSProtocol::Message::Object land_1, land_2;
        TUSProtocol::Message::Objects lands;
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
                TUSProtocol::Message::Handle message = factory.createGetLandsReply("1", "Message", lands);
        m_command = translator.translate(message);
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorGetLandsReplyWithObjectsTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorGetLandsReplyWithObjectsTranslation, SetsProperID)
{
    ASSERT_EQ(37, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorGetLandsReplyWithObjectsTranslation, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ProtocolToLanguageTranslatorGetLandsReplyWithObjectsTranslation, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetLandsReplyWithObjectsTranslation, SetsProperNumberOfObjects)
{
    ASSERT_EQ(2, m_command->getObjects().size());
}

TEST_F(ProtocolToLanguageTranslatorGetLandsReplyWithObjectsTranslation, SetsProperObjects)
{
    TUSLanguage::ICommand::Objects objects = m_command->getObjects();
    TUSLanguage::ICommand::Object object = objects.front();
    ASSERT_STREQ("Login1", object.at("login").c_str());
    ASSERT_STREQ("World1", object.at("world_name").c_str());
    ASSERT_STREQ("Land1", object.at("land_name").c_str());
    ASSERT_STREQ("false", object.at("granted").c_str());
    object = objects.back();
    ASSERT_STREQ("Login2", object.at("login").c_str());
    ASSERT_STREQ("World2", object.at("world_name").c_str());
    ASSERT_STREQ("Land2", object.at("land_name").c_str());
    ASSERT_STREQ("false", object.at("granted").c_str());
}

class ProtocolToLanguageTranslatorCreateSettlementReplyTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorCreateSettlementReplyTranslation()
        : m_message(m_factory.createCreateSettlementReply("1", "Message"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorCreateSettlementReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorCreateSettlementReplyTranslation, SetsProperReplyID)
{
    ASSERT_EQ(38, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorCreateSettlementReplyTranslation, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ProtocolToLanguageTranslatorCreateSettlementReplyTranslation, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

class ProtocolToLanguageTranslatorDeleteSettlementReplyTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorDeleteSettlementReplyTranslation()
        : m_message(m_factory.createDeleteSettlementReply("1", "Message"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorDeleteSettlementReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorDeleteSettlementReplyTranslation, SetsProperReplyID)
{
    ASSERT_EQ(39, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorDeleteSettlementReplyTranslation, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ProtocolToLanguageTranslatorDeleteSettlementReplyTranslation, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

class ProtocolToLanguageTranslatorGetSettlementReplyWithoutObjectTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorGetSettlementReplyWithoutObjectTranslation()
    {
        TUSProtocol::MessageFactory factory;
        TUSProtocol::ProtocolToLanguageTranslator translator;
        TUSProtocol::Message::Handle message = factory.createGetSettlementReply("1", "Message");
        m_command = translator.translate(message);
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorGetSettlementReplyWithoutObjectTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorGetSettlementReplyWithoutObjectTranslation, SetsProperID)
{
    ASSERT_EQ(40, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorGetSettlementReplyWithoutObjectTranslation, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ProtocolToLanguageTranslatorGetSettlementReplyWithoutObjectTranslation, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetSettlementReplyWithoutObjectTranslation, SetsProperNumberOfObjects)
{
    ASSERT_EQ(0, m_command->getObjects().size());
}

class ProtocolToLanguageTranslatorGetSettlementReplyWithObjectTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorGetSettlementReplyWithObjectTranslation()
    {
        TUSProtocol::MessageFactory factory;
        TUSProtocol::ProtocolToLanguageTranslator translator;
        TUSProtocol::Message::Object settlement;
        settlement.insert(std::make_pair("land_name", "Land1"));
        settlement.insert(std::make_pair("settlement_name", "Settlement1"));
        TUSProtocol::Message::Handle message = factory.createGetSettlementReply("1", "Message", settlement);
        m_command = translator.translate(message);
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorGetSettlementReplyWithObjectTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorGetSettlementReplyWithObjectTranslation, SetsProperID)
{
    ASSERT_EQ(40, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorGetSettlementReplyWithObjectTranslation, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ProtocolToLanguageTranslatorGetSettlementReplyWithObjectTranslation, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetSettlementReplyWithObjectTranslation, SetsProperNumberOfObjects)
{
    ASSERT_EQ(1, m_command->getObjects().size());
}

TEST_F(ProtocolToLanguageTranslatorGetSettlementReplyWithObjectTranslation, SetsProperObject)
{
    TUSLanguage::ICommand::Objects objects = m_command->getObjects();
    TUSLanguage::ICommand::Object object = objects.front();
    ASSERT_STREQ("Land1", object.at("land_name").c_str());
    ASSERT_STREQ("Settlement1", object.at("settlement_name").c_str());
}

class ProtocolToLanguageTranslatorGetSettlementsReplyWithoutObjectsTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorGetSettlementsReplyWithoutObjectsTranslation()
    {
        TUSProtocol::MessageFactory factory;
        TUSProtocol::ProtocolToLanguageTranslator translator;
        TUSProtocol::Message::Handle message = factory.createGetSettlementsReply("1", "Message");
        m_command = translator.translate(message);
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorGetSettlementsReplyWithoutObjectsTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorGetSettlementsReplyWithoutObjectsTranslation, SetsProperID)
{
    ASSERT_EQ(41, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorGetSettlementsReplyWithoutObjectsTranslation, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ProtocolToLanguageTranslatorGetSettlementsReplyWithoutObjectsTranslation, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetSettlementsReplyWithoutObjectsTranslation, SetsProperNumberOfObjects)
{
    ASSERT_EQ(0, m_command->getObjects().size());
}

class ProtocolToLanguageTranslatorGetSettlementsReplyWithObjectsTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorGetSettlementsReplyWithObjectsTranslation()
    {
        TUSProtocol::MessageFactory factory;
        TUSProtocol::ProtocolToLanguageTranslator translator;
        TUSProtocol::Message::Object settlement_1, settlement_2;
        TUSProtocol::Message::Objects settlements;
        settlement_1.insert(std::make_pair("land_name", "Land1"));
        settlement_1.insert(std::make_pair("settlement_name", "Settlement1"));
        settlement_2.insert(std::make_pair("land_name", "Land2"));
        settlement_2.insert(std::make_pair("settlement_name", "Settlement2"));
        settlements.push_back(settlement_1);
        settlements.push_back(settlement_2);
        TUSProtocol::Message::Handle message = factory.createGetSettlementsReply("1", "Message", settlements);
        m_command = translator.translate(message);
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorGetSettlementsReplyWithObjectsTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorGetSettlementsReplyWithObjectsTranslation, SetsProperID)
{
    ASSERT_EQ(41, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorGetSettlementsReplyWithObjectsTranslation, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ProtocolToLanguageTranslatorGetSettlementsReplyWithObjectsTranslation, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetSettlementsReplyWithObjectsTranslation, SetsProperNumberOfObjects)
{
    ASSERT_EQ(2, m_command->getObjects().size());
}

TEST_F(ProtocolToLanguageTranslatorGetSettlementsReplyWithObjectsTranslation, SetsProperObjects)
{
    TUSLanguage::ICommand::Objects objects = m_command->getObjects();
    TUSLanguage::ICommand::Object object = objects.front();
    ASSERT_STREQ("Land1", object.at("land_name").c_str());
    ASSERT_STREQ("Settlement1", object.at("settlement_name").c_str());
    object = objects.back();
    ASSERT_STREQ("Land2", object.at("land_name").c_str());
    ASSERT_STREQ("Settlement2", object.at("settlement_name").c_str());
}

class ProtocolToLanguageTranslatorBuildBuildingReplyTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorBuildBuildingReplyTranslation()
        : m_message(m_factory.createBuildBuildingReply("1", "Message"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorBuildBuildingReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorBuildBuildingReplyTranslation, SetsProperReplyID)
{
    ASSERT_EQ(42, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorBuildBuildingReplyTranslation, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ProtocolToLanguageTranslatorBuildBuildingReplyTranslation, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

class ProtocolToLanguageTranslatorDestroyBuildingReplyTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorDestroyBuildingReplyTranslation()
        : m_message(m_factory.createDestroyBuildingReply("1", "Message"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorDestroyBuildingReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorDestroyBuildingReplyTranslation, SetsProperReplyID)
{
    ASSERT_EQ(43, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorDestroyBuildingReplyTranslation, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ProtocolToLanguageTranslatorDestroyBuildingReplyTranslation, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

class ProtocolToLanguageTranslatorGetBuildingReplyWithoutObjectTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorGetBuildingReplyWithoutObjectTranslation()
    {
        TUSProtocol::MessageFactory factory;
        TUSProtocol::ProtocolToLanguageTranslator translator;
        TUSProtocol::Message::Handle message = factory.createGetBuildingReply("1", "Message");
        m_command = translator.translate(message);
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorGetBuildingReplyWithoutObjectTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorGetBuildingReplyWithoutObjectTranslation, SetsProperID)
{
    ASSERT_EQ(44, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorGetBuildingReplyWithoutObjectTranslation, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ProtocolToLanguageTranslatorGetBuildingReplyWithoutObjectTranslation, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetBuildingReplyWithoutObjectTranslation, SetsProperNumberOfObjects)
{
    ASSERT_EQ(0, m_command->getObjects().size());
}

class ProtocolToLanguageTranslatorGetBuildingReplyWithObjectTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorGetBuildingReplyWithObjectTranslation()
    {
        TUSProtocol::MessageFactory factory;
        TUSProtocol::ProtocolToLanguageTranslator translator;
        TUSProtocol::Message::Object building;
        building.insert(std::make_pair("buildingclass", "Regular"));
        building.insert(std::make_pair("buildingname", "Farm"));
        building.insert(std::make_pair("volume", "10"));
        TUSProtocol::Message::Handle message = factory.createGetBuildingReply("1", "Message", building);
        m_command = translator.translate(message);
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorGetBuildingReplyWithObjectTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorGetBuildingReplyWithObjectTranslation, SetsProperID)
{
    ASSERT_EQ(44, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorGetBuildingReplyWithObjectTranslation, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ProtocolToLanguageTranslatorGetBuildingReplyWithObjectTranslation, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetBuildingReplyWithObjectTranslation, SetsProperNumberOfObjects)
{
    ASSERT_EQ(1, m_command->getObjects().size());
}

TEST_F(ProtocolToLanguageTranslatorGetBuildingReplyWithObjectTranslation, SetsProperObject)
{
    TUSLanguage::ICommand::Objects objects = m_command->getObjects();
    TUSLanguage::ICommand::Object object = objects.front();
    ASSERT_STREQ("Regular", object.at("buildingclass").c_str());
    ASSERT_STREQ("Farm", object.at("buildingname").c_str());
    ASSERT_STREQ("10", object.at("volume").c_str());
}

class ProtocolToLanguageTranslatorGetBuildingsReplyWithoutObjectsTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorGetBuildingsReplyWithoutObjectsTranslation()
    {
        TUSProtocol::MessageFactory factory;
        TUSProtocol::ProtocolToLanguageTranslator translator;
        TUSProtocol::Message::Handle message = factory.createGetBuildingsReply("1", "Message");
        m_command = translator.translate(message);
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorGetBuildingsReplyWithoutObjectsTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorGetBuildingsReplyWithoutObjectsTranslation, SetsProperID)
{
    ASSERT_EQ(45, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorGetBuildingsReplyWithoutObjectsTranslation, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ProtocolToLanguageTranslatorGetBuildingsReplyWithoutObjectsTranslation, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetBuildingsReplyWithoutObjectsTranslation, SetsProperNumberOfObjects)
{
    ASSERT_EQ(0, m_command->getObjects().size());
}

class ProtocolToLanguageTranslatorGetBuildingsReplyWithObjectsTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorGetBuildingsReplyWithObjectsTranslation()
    {
        TUSProtocol::MessageFactory factory;
        TUSProtocol::ProtocolToLanguageTranslator translator;
        TUSProtocol::Message::Object building_1, building_2;
        TUSProtocol::Message::Objects buildings;
        building_1.insert(std::make_pair("buildingclass", "Regular"));
        building_1.insert(std::make_pair("buildingname", "Farm"));
        building_1.insert(std::make_pair("volume", "10"));
        building_2.insert(std::make_pair("buildingclass", "Regular"));
        building_2.insert(std::make_pair("buildingname", "Sawmill"));
        building_2.insert(std::make_pair("volume", "20"));
        buildings.push_back(building_1);
        buildings.push_back(building_2);
        TUSProtocol::Message::Handle message = factory.createGetBuildingsReply("1", "Message", buildings);
        m_command = translator.translate(message);
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorGetBuildingsReplyWithObjectsTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorGetBuildingsReplyWithObjectsTranslation, SetsProperID)
{
    ASSERT_EQ(45, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorGetBuildingsReplyWithObjectsTranslation, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ProtocolToLanguageTranslatorGetBuildingsReplyWithObjectsTranslation, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetBuildingsReplyWithObjectsTranslation, SetsProperNumberOfObjects)
{
    ASSERT_EQ(2, m_command->getObjects().size());
}

TEST_F(ProtocolToLanguageTranslatorGetBuildingsReplyWithObjectsTranslation, SetsProperObjects)
{
    TUSLanguage::ICommand::Objects objects = m_command->getObjects();
    TUSLanguage::ICommand::Object object = objects.front();
    ASSERT_STREQ("Regular", object.at("buildingclass").c_str());
    ASSERT_STREQ("Farm", object.at("buildingname").c_str());
    ASSERT_STREQ("10", object.at("volume").c_str());
    object = objects.back();
    ASSERT_STREQ("Regular", object.at("buildingclass").c_str());
    ASSERT_STREQ("Sawmill", object.at("buildingname").c_str());
    ASSERT_STREQ("20", object.at("volume").c_str());
}

class ProtocolToLanguageTranslatorDismissHumanReplyTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorDismissHumanReplyTranslation()
        : m_message(m_factory.createDismissHumanReply("1", "Message"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorDismissHumanReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorDismissHumanReplyTranslation, SetsProperReplyID)
{
    ASSERT_EQ(46, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorDismissHumanReplyTranslation, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ProtocolToLanguageTranslatorDismissHumanReplyTranslation, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

class ProtocolToLanguageTranslatorGetHumanReplyWithoutObjectTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorGetHumanReplyWithoutObjectTranslation()
    {
        TUSProtocol::MessageFactory factory;
        TUSProtocol::ProtocolToLanguageTranslator translator;
        TUSProtocol::Message::Handle message = factory.createGetHumanReply("1", "Message");
        m_command = translator.translate(message);
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorGetHumanReplyWithoutObjectTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorGetHumanReplyWithoutObjectTranslation, SetsProperID)
{
    ASSERT_EQ(48, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorGetHumanReplyWithoutObjectTranslation, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ProtocolToLanguageTranslatorGetHumanReplyWithoutObjectTranslation, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetHumanReplyWithoutObjectTranslation, SetsProperNumberOfObjects)
{
    ASSERT_EQ(0, m_command->getObjects().size());
}

class ProtocolToLanguageTranslatorGetHumanReplyWithObjectTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorGetHumanReplyWithObjectTranslation()
    {
        TUSProtocol::MessageFactory factory;
        TUSProtocol::ProtocolToLanguageTranslator translator;
        TUSProtocol::Message::Object human;
        human.insert(std::make_pair("humanclass", "Worker"));
        human.insert(std::make_pair("humanname", "Farmer"));
        human.insert(std::make_pair("experience", "Novice"));
        human.insert(std::make_pair("volume", "10"));
        TUSProtocol::Message::Handle message = factory.createGetHumanReply("1", "Message", human);
        m_command = translator.translate(message);
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorGetHumanReplyWithObjectTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorGetHumanReplyWithObjectTranslation, SetsProperID)
{
    ASSERT_EQ(48, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorGetHumanReplyWithObjectTranslation, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ProtocolToLanguageTranslatorGetHumanReplyWithObjectTranslation, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetHumanReplyWithObjectTranslation, SetsProperNumberOfObjects)
{
    ASSERT_EQ(1, m_command->getObjects().size());
}

TEST_F(ProtocolToLanguageTranslatorGetHumanReplyWithObjectTranslation, SetsProperObject)
{
    TUSLanguage::ICommand::Objects objects = m_command->getObjects();
    TUSLanguage::ICommand::Object object = objects.front();
    ASSERT_STREQ("Worker", object.at("humanclass").c_str());
    ASSERT_STREQ("Farmer", object.at("humanname").c_str());
    ASSERT_STREQ("Novice", object.at("experience").c_str());
    ASSERT_STREQ("10", object.at("volume").c_str());
}

class ProtocolToLanguageTranslatorGetHumansReplyWithObjectsTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorGetHumansReplyWithObjectsTranslation()
    {
        TUSProtocol::MessageFactory factory;
        TUSProtocol::ProtocolToLanguageTranslator translator;
        TUSProtocol::Message::Object human_1, human_2;
        TUSProtocol::Message::Objects humans;
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
        TUSProtocol::Message::Handle message = factory.createGetHumansReply("1", "Message", humans);
        m_command = translator.translate(message);
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorGetHumansReplyWithObjectsTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorGetHumansReplyWithObjectsTranslation, SetsProperID)
{
    ASSERT_EQ(49, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorGetHumansReplyWithObjectsTranslation, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ProtocolToLanguageTranslatorGetHumansReplyWithObjectsTranslation, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetHumansReplyWithObjectsTranslation, SetsProperNumberOfObjects)
{
    ASSERT_EQ(2, m_command->getObjects().size());
}

TEST_F(ProtocolToLanguageTranslatorGetHumansReplyWithObjectsTranslation, SetsProperObjects)
{
    TUSLanguage::ICommand::Objects objects = m_command->getObjects();
    TUSLanguage::ICommand::Object object = objects.front();
    ASSERT_STREQ("Worker", object.at("humanclass").c_str());
    ASSERT_STREQ("Farmer", object.at("humanname").c_str());
    ASSERT_STREQ("Novice", object.at("experience").c_str());
    ASSERT_STREQ("10", object.at("volume").c_str());
    object = objects.back();
    ASSERT_STREQ("Worker", object.at("humanclass").c_str());
    ASSERT_STREQ("Steelworker", object.at("humanname").c_str());
    ASSERT_STREQ("Advanced", object.at("experience").c_str());
    ASSERT_STREQ("20", object.at("volume").c_str());
}

class ProtocolToLanguageTranslatorGetHumansReplyWithoutObjectsTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorGetHumansReplyWithoutObjectsTranslation()
    {
        TUSProtocol::MessageFactory factory;
        TUSProtocol::ProtocolToLanguageTranslator translator;
        TUSProtocol::Message::Handle message = factory.createGetHumansReply("1", "Message");
        m_command = translator.translate(message);
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorGetHumansReplyWithoutObjectsTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorGetHumansReplyWithoutObjectsTranslation, SetsProperID)
{
    ASSERT_EQ(49, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorGetHumansReplyWithoutObjectsTranslation, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ProtocolToLanguageTranslatorGetHumansReplyWithoutObjectsTranslation, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetHumansReplyWithoutObjectsTranslation, SetsProperNumberOfObjects)
{
    ASSERT_EQ(0, m_command->getObjects().size());
}

class ProtocolToLanguageTranslatorGetResourceReplyWithoutObjectTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorGetResourceReplyWithoutObjectTranslation()
    {
        TUSProtocol::MessageFactory factory;
        TUSProtocol::ProtocolToLanguageTranslator translator;
        TUSProtocol::Message::Handle message = factory.createGetResourceReply("1", "Message");
        m_command = translator.translate(message);
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorGetResourceReplyWithoutObjectTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorGetResourceReplyWithoutObjectTranslation, SetsProperID)
{
    ASSERT_EQ(50, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorGetResourceReplyWithoutObjectTranslation, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ProtocolToLanguageTranslatorGetResourceReplyWithoutObjectTranslation, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetResourceReplyWithoutObjectTranslation, SetsProperNumberOfObjects)
{
    ASSERT_EQ(0, m_command->getObjects().size());
}

class ProtocolToLanguageTranslatorGetResourceReplyWithObjectTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorGetResourceReplyWithObjectTranslation()
    {
        TUSProtocol::MessageFactory factory;
        TUSProtocol::ProtocolToLanguageTranslator translator;
        TUSProtocol::Message::Object resource;
        resource.insert(std::make_pair("resourcename", "Coal"));
        resource.insert(std::make_pair("volume", "10"));
        TUSProtocol::Message::Handle message = factory.createGetResourceReply("1", "Message", resource);
        m_command = translator.translate(message);
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorGetResourceReplyWithObjectTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorGetResourceReplyWithObjectTranslation, SetsProperID)
{
    ASSERT_EQ(50, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorGetResourceReplyWithObjectTranslation, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ProtocolToLanguageTranslatorGetResourceReplyWithObjectTranslation, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetResourceReplyWithObjectTranslation, SetsProperNumberOfObjects)
{
    ASSERT_EQ(1, m_command->getObjects().size());
}

TEST_F(ProtocolToLanguageTranslatorGetResourceReplyWithObjectTranslation, SetsProperObject)
{
    TUSLanguage::ICommand::Objects objects = m_command->getObjects();
    TUSLanguage::ICommand::Object object = objects.front();
    ASSERT_STREQ("Coal", object.at("resourcename").c_str());
    ASSERT_STREQ("10", object.at("volume").c_str());
}

class ProtocolToLanguageTranslatorGetResourcesReplyWithoutObjectsTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorGetResourcesReplyWithoutObjectsTranslation()
    {
        TUSProtocol::MessageFactory factory;
        TUSProtocol::ProtocolToLanguageTranslator translator;
        TUSProtocol::Message::Handle message = factory.createGetResourcesReply("1", "Message");
        m_command = translator.translate(message);
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorGetResourcesReplyWithoutObjectsTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorGetResourcesReplyWithoutObjectsTranslation, SetsProperID)
{
    ASSERT_EQ(51, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorGetResourcesReplyWithoutObjectsTranslation, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ProtocolToLanguageTranslatorGetResourcesReplyWithoutObjectsTranslation, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetResourcesReplyWithoutObjectsTranslation, SetsProperNumberOfObjects)
{
    ASSERT_EQ(0, m_command->getObjects().size());
}

class ProtocolToLanguageTranslatorGetResourcesReplyWithObjectsTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorGetResourcesReplyWithObjectsTranslation()
    {
        TUSProtocol::MessageFactory factory;
        TUSProtocol::ProtocolToLanguageTranslator translator;
        TUSProtocol::Message::Object resource_1, resource_2;
        TUSProtocol::Message::Objects resources;
        resource_1.insert(std::make_pair("resourcename", "Coal"));
        resource_1.insert(std::make_pair("volume", "10"));
        resource_2.insert(std::make_pair("resourcename", "Wood"));
        resource_2.insert(std::make_pair("volume", "20"));
        resources.push_back(resource_1);
        resources.push_back(resource_2);
        TUSProtocol::Message::Handle message = factory.createGetResourcesReply("1", "Message", resources);
        m_command = translator.translate(message);
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorGetResourcesReplyWithObjectsTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorGetResourcesReplyWithObjectsTranslation, SetsProperID)
{
    ASSERT_EQ(51, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorGetResourcesReplyWithObjectsTranslation, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ProtocolToLanguageTranslatorGetResourcesReplyWithObjectsTranslation, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetResourcesReplyWithObjectsTranslation, SetsProperNumberOfObjects)
{
    ASSERT_EQ(2, m_command->getObjects().size());
}

TEST_F(ProtocolToLanguageTranslatorGetResourcesReplyWithObjectsTranslation, SetsProperObjects)
{
    TUSLanguage::ICommand::Objects objects = m_command->getObjects();
    TUSLanguage::ICommand::Object object = objects.front();
    ASSERT_STREQ("Coal", object.at("resourcename").c_str());
    ASSERT_STREQ("10", object.at("volume").c_str());
    object = objects.back();
    ASSERT_STREQ("Wood", object.at("resourcename").c_str());
    ASSERT_STREQ("20", object.at("volume").c_str());
}

class ProtocolToLanguageTranslatorCreateUserReplyTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorCreateUserReplyTranslation()
        : m_message(m_factory.createCreateUserReply("1", "Message"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorCreateUserReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorCreateUserReplyTranslation, SetsProperReplyID)
{
    ASSERT_EQ(52, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorCreateUserReplyTranslation, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ProtocolToLanguageTranslatorCreateUserReplyTranslation, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

class ProtocolToLanguageTranslatorCreateWorldReplyTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorCreateWorldReplyTranslation()
        : m_message(m_factory.createCreateWorldReply("1", "Message"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorCreateWorldReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorCreateWorldReplyTranslation, SetsProperReplyID)
{
    ASSERT_EQ(53, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorCreateWorldReplyTranslation, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ProtocolToLanguageTranslatorCreateWorldReplyTranslation, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

class ProtocolToLanguageTranslatorCreateEpochReplyTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorCreateEpochReplyTranslation()
        : m_message(m_factory.createCreateEpochReply("1", "Message"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorCreateEpochReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorCreateEpochReplyTranslation, SetsProperReplyID)
{
    ASSERT_EQ(54, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorCreateEpochReplyTranslation, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ProtocolToLanguageTranslatorCreateEpochReplyTranslation, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

class ProtocolToLanguageTranslatorDeleteEpochReplyTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorDeleteEpochReplyTranslation()
        : m_message(m_factory.createDeleteEpochReply("1", "Message"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorDeleteEpochReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorDeleteEpochReplyTranslation, SetsProperReplyID)
{
    ASSERT_EQ(55, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorDeleteEpochReplyTranslation, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ProtocolToLanguageTranslatorDeleteEpochReplyTranslation, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

class ProtocolToLanguageTranslatorActivateEpochReplyTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorActivateEpochReplyTranslation()
        : m_message(m_factory.createActivateEpochReply("1", "Message"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorActivateEpochReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorActivateEpochReplyTranslation, SetsProperReplyID)
{
    ASSERT_EQ(56, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorActivateEpochReplyTranslation, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ProtocolToLanguageTranslatorActivateEpochReplyTranslation, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

class ProtocolToLanguageTranslatorDeactivateEpochReplyTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorDeactivateEpochReplyTranslation()
        : m_message(m_factory.createDeactivateEpochReply("1", "Message"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorDeactivateEpochReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorDeactivateEpochReplyTranslation, SetsProperReplyID)
{
    ASSERT_EQ(57, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorDeactivateEpochReplyTranslation, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ProtocolToLanguageTranslatorDeactivateEpochReplyTranslation, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

class ProtocolToLanguageTranslatorFinishEpochReplyTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorFinishEpochReplyTranslation()
        : m_message(m_factory.createFinishEpochReply("1", "Message"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorFinishEpochReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorFinishEpochReplyTranslation, SetsProperReplyID)
{
    ASSERT_EQ(58, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorFinishEpochReplyTranslation, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ProtocolToLanguageTranslatorFinishEpochReplyTranslation, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

class ProtocolToLanguageTranslatorTickEpochReplyTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorTickEpochReplyTranslation()
        : m_message(m_factory.createTickEpochReply("1", "Message"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorTickEpochReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorTickEpochReplyTranslation, SetsProperReplyID)
{
    ASSERT_EQ(59, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorTickEpochReplyTranslation, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ProtocolToLanguageTranslatorTickEpochReplyTranslation, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

class ProtocolToLanguageTranslatorGetEpochReplyWithoutObjectTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorGetEpochReplyWithoutObjectTranslation()
    {
        TUSProtocol::MessageFactory factory;
        TUSProtocol::ProtocolToLanguageTranslator translator;
        TUSProtocol::Message::Handle message = factory.createGetEpochReply("1", "Message");
        m_command = translator.translate(message);
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorGetEpochReplyWithoutObjectTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorGetEpochReplyWithoutObjectTranslation, SetsProperID)
{
    ASSERT_EQ(60, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorGetEpochReplyWithoutObjectTranslation, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ProtocolToLanguageTranslatorGetEpochReplyWithoutObjectTranslation, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetEpochReplyWithoutObjectTranslation, SetsProperNumberOfObjects)
{
    ASSERT_EQ(0, m_command->getObjects().size());
}

class ProtocolToLanguageTranslatorGetEpochReplyWithObjectTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorGetEpochReplyWithObjectTranslation()
    {
        TUSProtocol::MessageFactory factory;
        TUSProtocol::ProtocolToLanguageTranslator translator;
        TUSProtocol::Message::Object epoch;
        epoch.insert(std::make_pair("epoch_name", "Epoch"));
        epoch.insert(std::make_pair("world_name", "World"));
        epoch.insert(std::make_pair("active", "true"));
        epoch.insert(std::make_pair("finished", "false"));
        epoch.insert(std::make_pair("ticks", "22"));
        TUSProtocol::Message::Handle message = factory.createGetEpochReply("1", "Message", epoch);
        m_command = translator.translate(message);
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorGetEpochReplyWithObjectTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorGetEpochReplyWithObjectTranslation, SetsProperID)
{
    ASSERT_EQ(60, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorGetEpochReplyWithObjectTranslation, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ProtocolToLanguageTranslatorGetEpochReplyWithObjectTranslation, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetEpochReplyWithObjectTranslation, SetsProperNumberOfObjects)
{
    ASSERT_EQ(1, m_command->getObjects().size());
}

TEST_F(ProtocolToLanguageTranslatorGetEpochReplyWithObjectTranslation, SetsProperObject)
{
    TUSLanguage::ICommand::Objects objects = m_command->getObjects();
    TUSLanguage::ICommand::Object object = objects.front();
    ASSERT_STREQ("Epoch", object.at("epoch_name").c_str());
    ASSERT_STREQ("World", object.at("world_name").c_str());
    ASSERT_STREQ("true", object.at("active").c_str());
    ASSERT_STREQ("false", object.at("finished").c_str());
    ASSERT_STREQ("22", object.at("ticks").c_str());
}

class ProtocolToLanguageTranslatorTransportHumanReplyTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorTransportHumanReplyTranslation()
        : m_message(m_factory.createTransportHumanReply("1", "Message"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorTransportHumanReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorTransportHumanReplyTranslation, SetsProperReplyID)
{
    ASSERT_EQ(61, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorTransportHumanReplyTranslation, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ProtocolToLanguageTranslatorTransportHumanReplyTranslation, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

class ProtocolToLanguageTranslatorTransportResourceReplyTranslation
    : public ::testing::Test
{
protected:
    ProtocolToLanguageTranslatorTransportResourceReplyTranslation()
        : m_message(m_factory.createTransportResourceReply("1", "Message"))
    {
        m_command = m_translator.translate(m_message);
    }

    TUSProtocol::MessageFactory m_factory;
    TUSProtocol::ProtocolToLanguageTranslator m_translator;
    TUSProtocol::Message::Handle m_message;
    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ProtocolToLanguageTranslatorTransportResourceReplyTranslation, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ProtocolToLanguageTranslatorTransportResourceReplyTranslation, SetsProperReplyID)
{
    ASSERT_EQ(62, m_command->getID());
}

TEST_F(ProtocolToLanguageTranslatorTransportResourceReplyTranslation, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ProtocolToLanguageTranslatorTransportResourceReplyTranslation, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

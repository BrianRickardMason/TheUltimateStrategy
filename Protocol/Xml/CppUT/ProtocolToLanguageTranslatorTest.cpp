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
    TUSProtocol::Message::SingleHandle m_message;
    TUSLanguage::ICommand::SingleHandle m_command;
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
    TUSProtocol::Message::SingleHandle m_message;
    TUSLanguage::ICommand::SingleHandle m_command;
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
    TUSProtocol::Message::SingleHandle m_message;
    TUSLanguage::ICommand::SingleHandle m_command;
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
    TUSProtocol::Message::SingleHandle m_message;
    TUSLanguage::ICommand::SingleHandle m_command;
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
    TUSProtocol::Message::SingleHandle m_message;
    TUSLanguage::ICommand::SingleHandle m_command;
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

TEST_F(ProtocolToLanguageTranslatorGetLandRequestTranslation, BuildProperPassword)
{
    ASSERT_STREQ("Password", m_command->getPassword().c_str());
}

TEST_F(ProtocolToLanguageTranslatorGetLandRequestTranslation, ProperLandName)
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
    TUSProtocol::Message::SingleHandle m_message;
    TUSLanguage::ICommand::SingleHandle m_command;
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
    TUSProtocol::Message::SingleHandle m_message;
    TUSLanguage::ICommand::SingleHandle m_command;
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
    TUSProtocol::Message::SingleHandle m_message;
    TUSLanguage::ICommand::SingleHandle m_command;
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
    TUSProtocol::Message::SingleHandle m_message;
    TUSLanguage::ICommand::SingleHandle m_command;
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
    TUSProtocol::Message::SingleHandle m_message;
    TUSLanguage::ICommand::SingleHandle m_command;
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
    TUSProtocol::Message::SingleHandle m_message;
    TUSLanguage::ICommand::SingleHandle m_command;
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
    TUSProtocol::Message::SingleHandle m_message;
    TUSLanguage::ICommand::SingleHandle m_command;
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
    TUSProtocol::Message::SingleHandle m_message;
    TUSLanguage::ICommand::SingleHandle m_command;
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
    TUSProtocol::Message::SingleHandle m_message;
    TUSLanguage::ICommand::SingleHandle m_command;
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
    TUSProtocol::Message::SingleHandle m_message;
    TUSLanguage::ICommand::SingleHandle m_command;
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
    TUSProtocol::Message::SingleHandle m_message;
    TUSLanguage::ICommand::SingleHandle m_command;
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
    TUSProtocol::Message::SingleHandle m_message;
    TUSLanguage::ICommand::SingleHandle m_command;
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
    TUSProtocol::Message::SingleHandle m_message;
    TUSLanguage::ICommand::SingleHandle m_command;
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
    TUSProtocol::Message::SingleHandle m_message;
    TUSLanguage::ICommand::SingleHandle m_command;
};

TEST_F(ProtocolToLanguageTranslatorGetResourceRequestTranslation, RequestReturnsNotNull)
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
    TUSProtocol::Message::SingleHandle m_message;
    TUSLanguage::ICommand::SingleHandle m_command;
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
    TUSProtocol::Message::SingleHandle m_message;
    TUSLanguage::ICommand::SingleHandle m_command;
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
    TUSProtocol::Message::SingleHandle m_message;
    TUSLanguage::ICommand::SingleHandle m_command;
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
    TUSProtocol::Message::SingleHandle m_message;
    TUSLanguage::ICommand::SingleHandle m_command;
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
    TUSProtocol::Message::SingleHandle m_message;
    TUSLanguage::ICommand::SingleHandle m_command;
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
    TUSProtocol::Message::SingleHandle m_message;
    TUSLanguage::ICommand::SingleHandle m_command;
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
    TUSProtocol::Message::SingleHandle m_message;
    TUSLanguage::ICommand::SingleHandle m_command;
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
    TUSProtocol::Message::SingleHandle m_message;
    TUSLanguage::ICommand::SingleHandle m_command;
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
    TUSProtocol::Message::SingleHandle m_message;
    TUSLanguage::ICommand::SingleHandle m_command;
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
    TUSProtocol::Message::SingleHandle m_message;
    TUSLanguage::ICommand::SingleHandle m_command;
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

TEST_F(ProtocolToLanguageTranslatorGetEpochRequestTranslation, RequestSetsProperWorldName)
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
    TUSProtocol::Message::SingleHandle m_message;
    TUSLanguage::ICommand::SingleHandle m_command;
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
    TUSProtocol::Message::SingleHandle m_message;
    TUSLanguage::ICommand::SingleHandle m_command;
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

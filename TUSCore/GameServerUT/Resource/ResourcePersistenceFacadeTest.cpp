// Copyright (C) 2010 and 2011 Marcin Arkadiusz Skrobiranda.
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

#include "../../GameServer/Resource/ResourcePersistenceFacade.hpp"
#include "../Persistence/TransactionDummy.hpp"
#include "ResourceManagerAccessorMock.hpp"

using namespace GameServer::Common;
using namespace GameServer::Persistence;
using namespace GameServer::Resource;
using namespace boost;
using namespace std;

using testing::Return;
using testing::Throw;
using testing::_;

/**
 * @brief A test class.
 *
 * TODO: Refactoring needed.
 */
class ResourcePersistenceFacadeTest
    : public testing::Test
{
protected:
    /**
     * @brief Creates a test class.
     */
    ResourcePersistenceFacadeTest()
    {
    }

    /**
     * @brief Compares the resource with expected values.
     *
     * @param a_resource The resource to be compared.
     * @param a_key      An expected key of the resource.
     * @param a_volume   An expected volume of the resource.
     */
    void compareResource(
        ResourceWithVolumeShrPtr         a_resource,
        Key                      const & a_key,
        Volume                   const & a_volume
    )
    {
        ASSERT_TRUE(a_key == a_resource->getKey());
        ASSERT_EQ(a_volume, a_resource->getVolume());
    }

    /**
     * @brief Gets a prepared resource set.
     *
     * @return The prepared resource set.
     */
    ResourceSet getResourceSet()
    {
        ResourceWithVolumeMap map;

        map.insert(make_pair(ID_RESOURCE_COAL, make_shared<ResourceWithVolume>(KEY_RESOURCE_COAL, 100)));
        map.insert(make_pair(ID_RESOURCE_FOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_FOOD, 200)));
        map.insert(make_pair(ID_RESOURCE_GOLD, make_shared<ResourceWithVolume>(KEY_RESOURCE_GOLD, 300)));
        map.insert(make_pair(ID_RESOURCE_IRON, make_shared<ResourceWithVolume>(KEY_RESOURCE_IRON, 400)));
        map.insert(make_pair(ID_RESOURCE_MANA, make_shared<ResourceWithVolume>(KEY_RESOURCE_MANA, 500)));
        map.insert(make_pair(ID_RESOURCE_ROCK, make_shared<ResourceWithVolume>(KEY_RESOURCE_ROCK, 600)));
        map.insert(make_pair(ID_RESOURCE_WOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_WOOD, 700)));

        ResourceSet resource_set(map);

        return resource_set;
    }

    /**
     * @brief An exemplary id holder.
     */
    IDHolder m_id_holder;
};

TEST_F(ResourcePersistenceFacadeTest, CtorDoesNotThrow)
{
    IResourceManagerAccessorAutPtr accessor(new ResourceManagerAccessorMock);

    ASSERT_NO_THROW(ResourcePersistenceFacade persistence_facade(accessor));
}

/**
 * Unit tests of: ResourcePersistenceFacade::addResource.
 */
TEST_F(ResourcePersistenceFacadeTest, addResource_ResourceIsNotPresent)
{
    // Preconditions.
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: ResourcePersistenceFacadeMock.
    ResourceManagerAccessorMock * mock = new ResourceManagerAccessorMock;

    EXPECT_CALL(*mock, insertRecord(transaction, m_id_holder, KEY_RESOURCE_COAL, 3));

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_COAL))
    .WillOnce(Return(ResourceWithVolumeRecordShrPtr()));

    IResourceManagerAccessorAutPtr accessor(mock);

    ResourcePersistenceFacade persistence_facade(accessor);

    // Test commands and assertions.
    ASSERT_NO_THROW(persistence_facade.addResource(transaction, m_id_holder, KEY_RESOURCE_COAL, 3));
}

TEST_F(ResourcePersistenceFacadeTest, addResource_ResourceIsNotPresent_Throw)
{
    // Preconditions.
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: ResourcePersistenceFacadeMock.
    ResourceManagerAccessorMock * mock = new ResourceManagerAccessorMock;

    std::exception e;

    EXPECT_CALL(*mock, insertRecord(transaction, m_id_holder, KEY_RESOURCE_COAL, 3))
    .WillOnce(Throw(e));

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_COAL))
    .WillOnce(Return(ResourceWithVolumeRecordShrPtr()));

    IResourceManagerAccessorAutPtr accessor(mock);

    ResourcePersistenceFacade persistence_facade(accessor);

    // Test commands and assertions.
    ASSERT_THROW(persistence_facade.addResource(transaction, m_id_holder, KEY_RESOURCE_COAL, 3), std::exception);
}

TEST_F(ResourcePersistenceFacadeTest, addResource_ResourceIsPresent)
{
    // Preconditions.
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: ResourcePersistenceFacadeMock.
    ResourceManagerAccessorMock * mock = new ResourceManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_COAL))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_COAL, 3)));

    EXPECT_CALL(*mock, increaseVolume(transaction, m_id_holder, KEY_RESOURCE_COAL, 3));

    IResourceManagerAccessorAutPtr accessor(mock);

    ResourcePersistenceFacade persistence_facade(accessor);

    // Test commands and assertions.
    ASSERT_NO_THROW(persistence_facade.addResource(transaction, m_id_holder, KEY_RESOURCE_COAL, 3));
}

TEST_F(ResourcePersistenceFacadeTest, addResource_ResourceIsPresent_Throw)
{
    // Preconditions.
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: ResourcePersistenceFacadeMock.
    ResourceManagerAccessorMock * mock = new ResourceManagerAccessorMock;

    std::exception e;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_COAL))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_COAL, 3)));

    EXPECT_CALL(*mock, increaseVolume(transaction, m_id_holder, KEY_RESOURCE_COAL, 3))
    .WillOnce(Throw(e));

    IResourceManagerAccessorAutPtr accessor(mock);

    ResourcePersistenceFacade persistence_facade(accessor);

    // Test commands and assertions.
    ASSERT_THROW(persistence_facade.addResource(transaction, m_id_holder, KEY_RESOURCE_COAL, 3), std::exception);
}

/**
 * Unit tests of: ResourcePersistenceFacade::subtractResource.
 */
TEST_F(ResourcePersistenceFacadeTest, subtractResource_ResourceIsNotPresent_TryToSubtract)
{
    // Preconditions.
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: ResourcePersistenceFacadeMock.
    ResourceManagerAccessorMock * mock = new ResourceManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_COAL))
    .WillOnce(Return(ResourceWithVolumeRecordShrPtr()));

    IResourceManagerAccessorAutPtr accessor(mock);

    ResourcePersistenceFacade persistence_facade(accessor);

    // Test commands and assertions.
    ASSERT_FALSE(persistence_facade.subtractResource(transaction, m_id_holder, KEY_RESOURCE_COAL, 3));
}

TEST_F(ResourcePersistenceFacadeTest, subtractResource_ResourceIsPresent_SubtractPart)
{
    // Preconditions.
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: ResourcePersistenceFacadeMock.
    ResourceManagerAccessorMock * mock = new ResourceManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_COAL))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_COAL, 3)));

    EXPECT_CALL(*mock, decreaseVolume(transaction, m_id_holder, KEY_RESOURCE_COAL, 2));

    IResourceManagerAccessorAutPtr accessor(mock);

    ResourcePersistenceFacade persistence_facade(accessor);

    // Test commands and assertions.
    ASSERT_TRUE(persistence_facade.subtractResource(transaction, m_id_holder, KEY_RESOURCE_COAL, 2));
}

TEST_F(ResourcePersistenceFacadeTest, subtractResource_ResourceIsPresent_SubtractPart_Throw)
{
    // Preconditions.
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: ResourcePersistenceFacadeMock.
    ResourceManagerAccessorMock * mock = new ResourceManagerAccessorMock;

    std::exception e;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_COAL))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_COAL, 3)));

    EXPECT_CALL(*mock, decreaseVolume(transaction, m_id_holder, KEY_RESOURCE_COAL, 2))
    .WillOnce(Throw(e));

    IResourceManagerAccessorAutPtr accessor(mock);

    ResourcePersistenceFacade persistence_facade(accessor);

    // Test commands and assertions.
    ASSERT_THROW(persistence_facade.subtractResource(transaction, m_id_holder, KEY_RESOURCE_COAL, 2), std::exception);
}

TEST_F(ResourcePersistenceFacadeTest, subtractResource_ResourceIsPresent_SubtractAll)
{
    // Preconditions.
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: ResourcePersistenceFacadeMock.
    ResourceManagerAccessorMock * mock = new ResourceManagerAccessorMock;

    EXPECT_CALL(*mock, deleteRecord(transaction, m_id_holder, KEY_RESOURCE_COAL));

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_COAL))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_COAL, 3)));

    IResourceManagerAccessorAutPtr accessor(mock);

    ResourcePersistenceFacade persistence_facade(accessor);

    // Test commands and assertions.
    ASSERT_TRUE(persistence_facade.subtractResource(transaction, m_id_holder, KEY_RESOURCE_COAL, 3));
}

TEST_F(ResourcePersistenceFacadeTest, subtractResource_ResourceIsPresent_SubtractAll_Throw)
{
    // Preconditions.
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: ResourcePersistenceFacadeMock.
    ResourceManagerAccessorMock * mock = new ResourceManagerAccessorMock;

    std::exception e;

    EXPECT_CALL(*mock, deleteRecord(transaction, m_id_holder, KEY_RESOURCE_COAL))
    .WillOnce(Throw(e));

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_COAL))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_COAL, 3)));

    IResourceManagerAccessorAutPtr accessor(mock);

    ResourcePersistenceFacade persistence_facade(accessor);

    // Test commands and assertions.
    ASSERT_THROW(persistence_facade.subtractResource(transaction, m_id_holder, KEY_RESOURCE_COAL, 3), std::exception);
}

TEST_F(ResourcePersistenceFacadeTest, subtractResource_ResourceIsPresent_TryToSubtractTooMuch)
{
    // Preconditions.
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: ResourcePersistenceFacadeMock.
    ResourceManagerAccessorMock * mock = new ResourceManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_COAL))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_COAL, 3)));

    IResourceManagerAccessorAutPtr accessor(mock);

    ResourcePersistenceFacade persistence_facade(accessor);

    // Test commands and assertions.
    ASSERT_FALSE(persistence_facade.subtractResource(transaction, m_id_holder, KEY_RESOURCE_COAL, 6));
}

/**
 * Unit tests of: ResourcePersistenceFacade::subtractResourceSafely.
 */
TEST_F(ResourcePersistenceFacadeTest, subtractResourceSafely_ResourceIsNotPresent_TryToSubtract)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    ResourceManagerAccessorMock * mock = new ResourceManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_COAL))
    .WillOnce(Return(ResourceWithVolumeRecordShrPtr()));

    IResourceManagerAccessorAutPtr accessor(mock);

    ResourcePersistenceFacade persistence_facade(accessor);

    ASSERT_NO_THROW(persistence_facade.subtractResourceSafely(transaction, m_id_holder, KEY_RESOURCE_COAL, 3));
}

TEST_F(ResourcePersistenceFacadeTest, subtractResourceSafely_ResourceIsPresent_SubtractZero)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    IResourceManagerAccessorAutPtr accessor(new ResourceManagerAccessorMock);

    ResourcePersistenceFacade persistence_facade(accessor);

    ASSERT_NO_THROW(persistence_facade.subtractResourceSafely(transaction, m_id_holder, KEY_RESOURCE_COAL, 0));
}

TEST_F(ResourcePersistenceFacadeTest, subtractResourceSafely_ResourceIsPresent_SubtractPart)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    ResourceManagerAccessorMock * mock = new ResourceManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_COAL))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_COAL, 3)));

    EXPECT_CALL(*mock, decreaseVolume(transaction, m_id_holder, KEY_RESOURCE_COAL, 2));

    IResourceManagerAccessorAutPtr accessor(mock);

    ResourcePersistenceFacade persistence_facade(accessor);

    ASSERT_NO_THROW(persistence_facade.subtractResourceSafely(transaction, m_id_holder, KEY_RESOURCE_COAL, 2));
}

TEST_F(ResourcePersistenceFacadeTest, subtractResourceSafely_ResourceIsPresent_SubtractPart_Throw)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    ResourceManagerAccessorMock * mock = new ResourceManagerAccessorMock;

    std::exception e;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_COAL))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_COAL, 3)));

    EXPECT_CALL(*mock, decreaseVolume(transaction, m_id_holder, KEY_RESOURCE_COAL, 2))
    .WillOnce(Throw(e));

    IResourceManagerAccessorAutPtr accessor(mock);

    ResourcePersistenceFacade persistence_facade(accessor);

    ASSERT_THROW(persistence_facade.subtractResourceSafely(transaction, m_id_holder, KEY_RESOURCE_COAL, 2), std::exception);
}

TEST_F(ResourcePersistenceFacadeTest, subtractResourceSafely_ResourceIsPresent_SubtractAll)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    ResourceManagerAccessorMock * mock = new ResourceManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_COAL))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_COAL, 3)));

    EXPECT_CALL(*mock, deleteRecord(transaction, m_id_holder, KEY_RESOURCE_COAL));

    IResourceManagerAccessorAutPtr accessor(mock);

    ResourcePersistenceFacade persistence_facade(accessor);

    ASSERT_NO_THROW(persistence_facade.subtractResourceSafely(transaction, m_id_holder, KEY_RESOURCE_COAL, 3));
}

TEST_F(ResourcePersistenceFacadeTest, subtractResourceSafely_ResourceIsPresent_SubtractAll_Throw)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    ResourceManagerAccessorMock * mock = new ResourceManagerAccessorMock;

    std::exception e;

    EXPECT_CALL(*mock, deleteRecord(transaction, m_id_holder, KEY_RESOURCE_COAL))
    .WillOnce(Throw(e));

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_COAL))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_COAL, 3)));

    IResourceManagerAccessorAutPtr accessor(mock);

    ResourcePersistenceFacade persistence_facade(accessor);

    ASSERT_THROW(persistence_facade.subtractResourceSafely(transaction, m_id_holder, KEY_RESOURCE_COAL, 3), std::exception);
}

TEST_F(ResourcePersistenceFacadeTest, subtractResourceSafely_ResourceIsPresent_SubtractTooMuch)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    ResourceManagerAccessorMock * mock = new ResourceManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_COAL))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_COAL, 3)));

    EXPECT_CALL(*mock, deleteRecord(transaction, m_id_holder, KEY_RESOURCE_COAL));

    IResourceManagerAccessorAutPtr accessor(mock);

    ResourcePersistenceFacade persistence_facade(accessor);

    ASSERT_NO_THROW(persistence_facade.subtractResourceSafely(transaction, m_id_holder, KEY_RESOURCE_COAL, 6));
}

/**
 * Unit tests of: ResourcePersistenceFacade::subtractResourceSet.
 */
TEST_F(ResourcePersistenceFacadeTest, subtractResourceSet_EmptySet)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    ResourceSet resource_set;

    ResourceManagerAccessorMock * mock = new ResourceManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, _))
    .WillRepeatedly(Return(ResourceWithVolumeRecordShrPtr()));

    IResourceManagerAccessorAutPtr accessor(mock);

    ResourcePersistenceFacade persistence_facade(accessor);

    ASSERT_TRUE(persistence_facade.subtractResourceSet(transaction, m_id_holder, resource_set));
}

TEST_F(ResourcePersistenceFacadeTest, subtractResourceSet_ResourcesAreNotPresent_TryToSubtract)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    ResourceSet resource_set = getResourceSet();

    ResourceManagerAccessorMock * mock = new ResourceManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, _))
    .WillRepeatedly(Return(ResourceWithVolumeRecordShrPtr()));

    IResourceManagerAccessorAutPtr accessor(mock);

    ResourcePersistenceFacade persistence_facade(accessor);

    ASSERT_FALSE(persistence_facade.subtractResourceSet(transaction, m_id_holder, resource_set));
}

TEST_F(ResourcePersistenceFacadeTest, subtractResourceSet_ResourcesArePresent_SubtractPart)
{
    // Preconditions.
    ITransactionShrPtr transaction(new TransactionDummy);

    ResourceSet resource_set = getResourceSet();

    // Mocks setup: ResourcePersistenceFacadeMock.
    ResourceManagerAccessorMock * mock = new ResourceManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_COAL))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_COAL, 1000)));
    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_FOOD))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_FOOD, 1000)));
    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_GOLD))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_GOLD, 1000)));
    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_IRON))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_IRON, 1000)));
    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_MANA))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_MANA, 1000)));
    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_ROCK))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_ROCK, 1000)));
    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_WOOD))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_WOOD, 1000)));

    EXPECT_CALL(*mock, decreaseVolume(transaction, m_id_holder, KEY_RESOURCE_COAL, 100));
    EXPECT_CALL(*mock, decreaseVolume(transaction, m_id_holder, KEY_RESOURCE_FOOD, 200));
    EXPECT_CALL(*mock, decreaseVolume(transaction, m_id_holder, KEY_RESOURCE_GOLD, 300));
    EXPECT_CALL(*mock, decreaseVolume(transaction, m_id_holder, KEY_RESOURCE_IRON, 400));
    EXPECT_CALL(*mock, decreaseVolume(transaction, m_id_holder, KEY_RESOURCE_MANA, 500));
    EXPECT_CALL(*mock, decreaseVolume(transaction, m_id_holder, KEY_RESOURCE_ROCK, 600));
    EXPECT_CALL(*mock, decreaseVolume(transaction, m_id_holder, KEY_RESOURCE_WOOD, 700));

    IResourceManagerAccessorAutPtr accessor(mock);

    ResourcePersistenceFacade persistence_facade(accessor);

    // Test commands and assertions.
    ASSERT_TRUE(persistence_facade.subtractResourceSet(transaction, m_id_holder, resource_set));
}

TEST_F(ResourcePersistenceFacadeTest, subtractResourceSet_ResourcesArePresent_SubtractPart_Throw)
{
    // Preconditions.
    ITransactionShrPtr transaction(new TransactionDummy);

    ResourceSet resource_set = getResourceSet();

    // Mocks setup: ResourcePersistenceFacadeMock.
    ResourceManagerAccessorMock * mock = new ResourceManagerAccessorMock;

    std::exception e;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_COAL))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_COAL, 1000)));

    EXPECT_CALL(*mock, decreaseVolume(transaction, m_id_holder, KEY_RESOURCE_COAL, 100))
    .WillOnce(Throw(e));

    IResourceManagerAccessorAutPtr accessor(mock);

    ResourcePersistenceFacade persistence_facade(accessor);

    // Test commands and assertions.
    ASSERT_THROW(persistence_facade.subtractResourceSet(transaction, m_id_holder, resource_set), std::exception);
}

TEST_F(ResourcePersistenceFacadeTest, subtractResourceSet_ResourcesArePresent_SubtractAll)
{
    // Preconditions.
    ITransactionShrPtr transaction(new TransactionDummy);

    ResourceSet resource_set = getResourceSet();

    // Mocks setup: ResourcePersistenceFacadeMock.
    ResourceManagerAccessorMock * mock = new ResourceManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_COAL))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_COAL, 100)));
    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_FOOD))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_FOOD, 200)));
    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_GOLD))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_GOLD, 300)));
    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_IRON))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_IRON, 400)));
    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_MANA))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_MANA, 500)));
    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_ROCK))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_ROCK, 600)));
    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_WOOD))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_WOOD, 700)));

    EXPECT_CALL(*mock, deleteRecord(transaction, m_id_holder, KEY_RESOURCE_COAL));
    EXPECT_CALL(*mock, deleteRecord(transaction, m_id_holder, KEY_RESOURCE_FOOD));
    EXPECT_CALL(*mock, deleteRecord(transaction, m_id_holder, KEY_RESOURCE_GOLD));
    EXPECT_CALL(*mock, deleteRecord(transaction, m_id_holder, KEY_RESOURCE_IRON));
    EXPECT_CALL(*mock, deleteRecord(transaction, m_id_holder, KEY_RESOURCE_MANA));
    EXPECT_CALL(*mock, deleteRecord(transaction, m_id_holder, KEY_RESOURCE_ROCK));
    EXPECT_CALL(*mock, deleteRecord(transaction, m_id_holder, KEY_RESOURCE_WOOD));

    IResourceManagerAccessorAutPtr accessor(mock);

    ResourcePersistenceFacade persistence_facade(accessor);

    // Test commands and assertions.
    ASSERT_TRUE(persistence_facade.subtractResourceSet(transaction, m_id_holder, resource_set));
}

TEST_F(ResourcePersistenceFacadeTest, subtractResourceSet_ResourcesArePresent_SubtractAll_Throw)
{
    // Preconditions.
    ITransactionShrPtr transaction(new TransactionDummy);

    ResourceSet resource_set = getResourceSet();

    // Mocks setup: ResourcePersistenceFacadeMock.
    ResourceManagerAccessorMock * mock = new ResourceManagerAccessorMock;

    std::exception e;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_COAL))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_COAL, 100)));
    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_FOOD))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_FOOD, 200)));

    EXPECT_CALL(*mock, deleteRecord(transaction, m_id_holder, KEY_RESOURCE_COAL));
    EXPECT_CALL(*mock, deleteRecord(transaction, m_id_holder, KEY_RESOURCE_FOOD))
    .WillOnce(Throw(e));

    IResourceManagerAccessorAutPtr accessor(mock);

    ResourcePersistenceFacade persistence_facade(accessor);

    // Test commands and assertions.
    ASSERT_THROW(persistence_facade.subtractResourceSet(transaction, m_id_holder, resource_set), std::exception);
}

TEST_F(ResourcePersistenceFacadeTest, subtractResourceSet_ResourcesArePresent_TryToSubtractTooMuch)
{
    // Preconditions.
    ITransactionShrPtr transaction(new TransactionDummy);

    ResourceSet resource_set = getResourceSet();

    // Mocks setup: ResourcePersistenceFacadeMock.
    ResourceManagerAccessorMock * mock = new ResourceManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_COAL))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_COAL, 100)));
    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_FOOD))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_FOOD, 200)));
    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_GOLD))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_GOLD, 300)));
    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_IRON))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_IRON, 399)));

    EXPECT_CALL(*mock, deleteRecord(transaction, m_id_holder, KEY_RESOURCE_COAL));
    EXPECT_CALL(*mock, deleteRecord(transaction, m_id_holder, KEY_RESOURCE_FOOD));
    EXPECT_CALL(*mock, deleteRecord(transaction, m_id_holder, KEY_RESOURCE_GOLD));

    IResourceManagerAccessorAutPtr accessor(mock);

    ResourcePersistenceFacade persistence_facade(accessor);

    // Test commands and assertions.
    ASSERT_FALSE(persistence_facade.subtractResourceSet(transaction, m_id_holder, resource_set));
}

/**
 * Unit tests of: ResourcePersistenceFacade::subtractResourceSetSafely.
 */
TEST_F(ResourcePersistenceFacadeTest, subtractResourceSetSafely_EmptySet)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    ResourceSet resource_set;

    ResourceManagerAccessorMock * mock = new ResourceManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, _))
    .WillRepeatedly(Return(ResourceWithVolumeRecordShrPtr()));

    IResourceManagerAccessorAutPtr accessor(mock);

    ResourcePersistenceFacade persistence_facade(accessor);

    ASSERT_NO_THROW(persistence_facade.subtractResourceSetSafely(transaction, m_id_holder, resource_set));
}

TEST_F(ResourcePersistenceFacadeTest, subtractResourceSetSafely_ResourcesAreNotPresent_TryToSubtract)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    ResourceSet resource_set = getResourceSet();

    ResourceManagerAccessorMock * mock = new ResourceManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, _))
    .WillRepeatedly(Return(ResourceWithVolumeRecordShrPtr()));

    IResourceManagerAccessorAutPtr accessor(mock);

    ResourcePersistenceFacade persistence_facade(accessor);

    ASSERT_NO_THROW(persistence_facade.subtractResourceSetSafely(transaction, m_id_holder, resource_set));
}

TEST_F(ResourcePersistenceFacadeTest, subtractResourceSetSafely_ResourcesArePresent_SubtractPart)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    ResourceSet resource_set = getResourceSet();

    ResourceManagerAccessorMock * mock = new ResourceManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_COAL))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_COAL, 1000)));
    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_FOOD))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_FOOD, 1000)));
    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_GOLD))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_GOLD, 1000)));
    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_IRON))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_IRON, 1000)));
    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_MANA))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_MANA, 1000)));
    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_ROCK))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_ROCK, 1000)));
    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_WOOD))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_WOOD, 1000)));

    EXPECT_CALL(*mock, decreaseVolume(transaction, m_id_holder, KEY_RESOURCE_COAL, 100));
    EXPECT_CALL(*mock, decreaseVolume(transaction, m_id_holder, KEY_RESOURCE_FOOD, 200));
    EXPECT_CALL(*mock, decreaseVolume(transaction, m_id_holder, KEY_RESOURCE_GOLD, 300));
    EXPECT_CALL(*mock, decreaseVolume(transaction, m_id_holder, KEY_RESOURCE_IRON, 400));
    EXPECT_CALL(*mock, decreaseVolume(transaction, m_id_holder, KEY_RESOURCE_MANA, 500));
    EXPECT_CALL(*mock, decreaseVolume(transaction, m_id_holder, KEY_RESOURCE_ROCK, 600));
    EXPECT_CALL(*mock, decreaseVolume(transaction, m_id_holder, KEY_RESOURCE_WOOD, 700));

    IResourceManagerAccessorAutPtr accessor(mock);

    ResourcePersistenceFacade persistence_facade(accessor);

    ASSERT_NO_THROW(persistence_facade.subtractResourceSetSafely(transaction, m_id_holder, resource_set));
}

TEST_F(ResourcePersistenceFacadeTest, subtractResourceSetSafely_ResourcesArePresent_SubtractPart_Throw)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    ResourceSet resource_set = getResourceSet();

    ResourceManagerAccessorMock * mock = new ResourceManagerAccessorMock;

    std::exception e;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_COAL))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_COAL, 1000)));

    EXPECT_CALL(*mock, decreaseVolume(transaction, m_id_holder, KEY_RESOURCE_COAL, 100))
    .WillOnce(Throw(e));

    IResourceManagerAccessorAutPtr accessor(mock);

    ResourcePersistenceFacade persistence_facade(accessor);

    ASSERT_THROW(persistence_facade.subtractResourceSetSafely(transaction, m_id_holder, resource_set), std::exception);
}

TEST_F(ResourcePersistenceFacadeTest, subtractResourceSetSafely_ResourcesArePresent_SubtractAll)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    ResourceSet resource_set = getResourceSet();

    ResourceManagerAccessorMock * mock = new ResourceManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_COAL))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_COAL, 100)));
    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_FOOD))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_FOOD, 200)));
    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_GOLD))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_GOLD, 300)));
    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_IRON))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_IRON, 400)));
    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_MANA))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_MANA, 500)));
    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_ROCK))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_ROCK, 600)));
    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_WOOD))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_WOOD, 700)));

    EXPECT_CALL(*mock, deleteRecord(transaction, m_id_holder, KEY_RESOURCE_COAL));
    EXPECT_CALL(*mock, deleteRecord(transaction, m_id_holder, KEY_RESOURCE_FOOD));
    EXPECT_CALL(*mock, deleteRecord(transaction, m_id_holder, KEY_RESOURCE_GOLD));
    EXPECT_CALL(*mock, deleteRecord(transaction, m_id_holder, KEY_RESOURCE_IRON));
    EXPECT_CALL(*mock, deleteRecord(transaction, m_id_holder, KEY_RESOURCE_MANA));
    EXPECT_CALL(*mock, deleteRecord(transaction, m_id_holder, KEY_RESOURCE_ROCK));
    EXPECT_CALL(*mock, deleteRecord(transaction, m_id_holder, KEY_RESOURCE_WOOD));

    IResourceManagerAccessorAutPtr accessor(mock);

    ResourcePersistenceFacade persistence_facade(accessor);

    ASSERT_NO_THROW(persistence_facade.subtractResourceSetSafely(transaction, m_id_holder, resource_set));
}

TEST_F(ResourcePersistenceFacadeTest, subtractResourceSetSafely_ResourcesArePresent_SubtractAll_Throw)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    ResourceSet resource_set = getResourceSet();

    ResourceManagerAccessorMock * mock = new ResourceManagerAccessorMock;

    std::exception e;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_COAL))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_COAL, 100)));
    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_FOOD))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_FOOD, 200)));

    EXPECT_CALL(*mock, deleteRecord(transaction, m_id_holder, KEY_RESOURCE_COAL));
    EXPECT_CALL(*mock, deleteRecord(transaction, m_id_holder, KEY_RESOURCE_FOOD))
    .WillOnce(Throw(e));

    IResourceManagerAccessorAutPtr accessor(mock);

    ResourcePersistenceFacade persistence_facade(accessor);

    ASSERT_THROW(persistence_facade.subtractResourceSetSafely(transaction, m_id_holder, resource_set), std::exception);
}

TEST_F(ResourcePersistenceFacadeTest, subtractResourceSetSafely_ResourcesArePresent_SubtractTooMuch)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    ResourceSet resource_set = getResourceSet();

    ResourceManagerAccessorMock * mock = new ResourceManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_COAL))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_COAL, 100)));
    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_FOOD))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_FOOD, 200)));
    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_GOLD))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_GOLD, 300)));
    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_IRON))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_IRON, 399)));
    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_MANA))
    .WillOnce(Return(ResourceWithVolumeRecordShrPtr()));
    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_ROCK))
    .WillOnce(Return(ResourceWithVolumeRecordShrPtr()));
    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_WOOD))
    .WillOnce(Return(ResourceWithVolumeRecordShrPtr()));

    EXPECT_CALL(*mock, deleteRecord(transaction, m_id_holder, KEY_RESOURCE_COAL));
    EXPECT_CALL(*mock, deleteRecord(transaction, m_id_holder, KEY_RESOURCE_FOOD));
    EXPECT_CALL(*mock, deleteRecord(transaction, m_id_holder, KEY_RESOURCE_GOLD));
    EXPECT_CALL(*mock, deleteRecord(transaction, m_id_holder, KEY_RESOURCE_IRON));

    IResourceManagerAccessorAutPtr accessor(mock);

    ResourcePersistenceFacade persistence_facade(accessor);

    ASSERT_NO_THROW(persistence_facade.subtractResourceSetSafely(transaction, m_id_holder, resource_set));
}

/**
 * Unit tests of: ResourcePersistenceFacade::getResource.
 */
TEST_F(ResourcePersistenceFacadeTest, getResource_ResourceIsNotPresent)
{
    // Preconditions.
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: ResourcePersistenceFacadeMock.
    ResourceManagerAccessorMock * mock = new ResourceManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_COAL))
    .WillOnce(Return(ResourceWithVolumeRecordShrPtr()));

    IResourceManagerAccessorAutPtr accessor(mock);

    ResourcePersistenceFacade persistence_facade(accessor);

    // Test commands.
    ResourceWithVolumeShrPtr resource = persistence_facade.getResource(transaction, m_id_holder, KEY_RESOURCE_COAL);

    // Test assertions.
    ASSERT_TRUE(resource == NULL);
}

TEST_F(ResourcePersistenceFacadeTest, getResource_ResourceIsPresent)
{
    // Preconditions.
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: ResourcePersistenceFacadeMock.
    ResourceManagerAccessorMock * mock = new ResourceManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder, KEY_RESOURCE_COAL))
    .WillOnce(Return(make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_COAL, 3)));

    IResourceManagerAccessorAutPtr accessor(mock);

    ResourcePersistenceFacade persistence_facade(accessor);

    // Test commands.
    ResourceWithVolumeShrPtr resource = persistence_facade.getResource(transaction, m_id_holder, KEY_RESOURCE_COAL);

    // Test assertions.
    ASSERT_TRUE(resource != NULL);

    compareResource(resource, KEY_RESOURCE_COAL, 3);
}

/**
 * Unit tests of: ResourcePersistenceFacade::getResources.
 */
TEST_F(ResourcePersistenceFacadeTest, getResources_ResourcesAreNotPresent)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    ResourceManagerAccessorMock * mock = new ResourceManagerAccessorMock;

    EXPECT_CALL(*mock, getRecords(transaction, m_id_holder))
    .WillOnce(Return(ResourceWithVolumeRecordMap()));

    IResourceManagerAccessorAutPtr accessor(mock);

    ResourcePersistenceFacade persistence_facade(accessor);

    ResourceSet resource_set = persistence_facade.getResources(transaction, m_id_holder);

    ResourceWithVolumeMap resource_map = resource_set.getMap();

    ASSERT_FALSE(resource_map.empty());

    ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

    compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 0);
    compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 0);
    compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
    compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
    compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
    compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
    compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
}

TEST_F(ResourcePersistenceFacadeTest, getResources_ResourcesArePresent_OneResource)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    ResourceManagerAccessorMock * mock = new ResourceManagerAccessorMock;

    ResourceWithVolumeRecordMap map;

    map.insert(make_pair(KEY_RESOURCE_COAL, make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_COAL, 3)));

    EXPECT_CALL(*mock, getRecords(transaction, m_id_holder))
    .WillOnce(Return(map));

    IResourceManagerAccessorAutPtr accessor(mock);

    ResourcePersistenceFacade persistence_facade(accessor);

    ResourceSet resource_set = persistence_facade.getResources(transaction, m_id_holder);

    ResourceWithVolumeMap resource_map = resource_set.getMap();

    ASSERT_FALSE(resource_map.empty());

    ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

    compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 3);
    compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 0);
    compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
    compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
    compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
    compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
    compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
}

TEST_F(ResourcePersistenceFacadeTest, getResources_ResourcesArePresent_TwoResources)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    ResourceManagerAccessorMock * mock = new ResourceManagerAccessorMock;

    ResourceWithVolumeRecordMap map;

    map.insert(make_pair(KEY_RESOURCE_COAL, make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_COAL, 3)));
    map.insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_FOOD, 5)));
    map.insert(make_pair(KEY_RESOURCE_COAL, make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_GOLD, 0)));
    map.insert(make_pair(KEY_RESOURCE_COAL, make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_IRON, 0)));
    map.insert(make_pair(KEY_RESOURCE_COAL, make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_MANA, 0)));
    map.insert(make_pair(KEY_RESOURCE_COAL, make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_ROCK, 0)));
    map.insert(make_pair(KEY_RESOURCE_COAL, make_shared<ResourceWithVolumeRecord>(m_id_holder, KEY_RESOURCE_WOOD, 0)));

    EXPECT_CALL(*mock, getRecords(transaction, m_id_holder))
    .WillOnce(Return(map));

    IResourceManagerAccessorAutPtr accessor(mock);

    ResourcePersistenceFacade persistence_facade(accessor);

    ResourceSet resource_set = persistence_facade.getResources(transaction, m_id_holder);

    ResourceWithVolumeMap resource_map = resource_set.getMap();

    ASSERT_FALSE(resource_map.empty());

    ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

    compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 3);
    compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 5);
    compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
    compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
    compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
    compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
    compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
}
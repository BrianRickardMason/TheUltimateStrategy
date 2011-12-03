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

#ifndef GAMESERVER_HUMAN_HUMANACCESSORMOCK_HPP
#define GAMESERVER_HUMAN_HUMANACCESSORMOCK_HPP

#include "../../GameServer/Human/IHumanAccessor.hpp"
#include <gmock/gmock.h>

namespace GameServer
{
namespace Human
{

/**
 * @brief The mock of HumanAccessor.
 */
class HumanAccessorMock
    : public IHumanAccessor
{
public:
    /**
     * @brief Inserts a human with volume record.
     *
     * @param a_transaction A transaction.
     * @param a_id_holder   An identifier of the holder.
     * @param a_key         A key of the human.
     * @param a_volume      A volume of the human.
     */
    MOCK_CONST_METHOD4(
        insertRecord,
        void(
            GameServer::Persistence::ITransactionShrPtr         a_transaction,
            GameServer::Common::IDHolder                const & a_id_holder,
            Configuration::IKey                         const & a_key,
            Volume                                      const & a_volume
        )
    );

    /**
     * @brief Deletes a human with volume record.
     *
     * @param a_transaction A transaction.
     * @param a_id_holder   An identifier of the holder.
     * @param a_key         A key of the human.
     */
    MOCK_CONST_METHOD3(
        deleteRecord,
        void(
            GameServer::Persistence::ITransactionShrPtr         a_transaction,
            GameServer::Common::IDHolder                const & a_id_holder,
            Configuration::IKey                         const & a_key
        )
    );

    /**
     * @brief Gets a human with volume record.
     *
     * @param a_transaction A transaction.
     * @param a_id_holder   An identifier of the holder.
     * @param a_key         A key of the human.
     *
     * @return The human with volume record, null if not found.
     */
    MOCK_CONST_METHOD3(
        getRecord,
        HumanWithVolumeRecordShrPtr(
            GameServer::Persistence::ITransactionShrPtr         a_transaction,
            GameServer::Common::IDHolder                const & a_id_holder,
            Configuration::IKey                         const & a_key
        )
    );

    /**
     * @brief Gets human with volume records.
     *
     * @param a_transaction A transaction.
     * @param a_id_holder   An identifier of the holder.
     *
     * @return A map of human with volume records, an empty map if not found.
     */
    MOCK_CONST_METHOD2(
        getRecords,
        HumanWithVolumeRecordMap(
            GameServer::Persistence::ITransactionShrPtr         a_transaction,
            GameServer::Common::IDHolder                const & a_id_holder
        )
    );

    /**
     * @brief Increases the volume of human with volume record.
     *
     * @param a_transaction A transaction.
     * @param a_id_holder   An identifier of the holder.
     * @param a_key         A key of the human.
     * @param a_volume      A volume to be increased.
     */
    MOCK_CONST_METHOD4(
        increaseVolume,
        void(
            GameServer::Persistence::ITransactionShrPtr         a_transaction,
            GameServer::Common::IDHolder                const & a_id_holder,
            Configuration::IKey                         const & a_key,
            Volume                                      const & a_volume
        )
    );

    /**
     * @brief Decreases the volume of human with volume record.
     *
     * @param a_transaction  A transaction.
     * @param a_id_holder    An identifier of the holder.
     * @param a_key          A key of the human.
     * @param a_volume       A volume to be decreased.
     */
    MOCK_CONST_METHOD4(
        decreaseVolume,
        void(
            GameServer::Persistence::ITransactionShrPtr         a_transaction,
            GameServer::Common::IDHolder                const & a_id_holder,
            Configuration::IKey                         const & a_key,
            Volume                                      const & a_volume
        )
    );
};

} // namespace Human
} // namespace GameServer

#endif // GAMESERVER_HUMAN_HUMANACCESSORMOCK_HPP

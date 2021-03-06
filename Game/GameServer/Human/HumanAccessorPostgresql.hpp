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

#ifndef GAMESERVER_HUMAN_HUMANACCESSORPOSTGRESQL_HPP
#define GAMESERVER_HUMAN_HUMANACCESSORPOSTGRESQL_HPP

#include <Game/GameServer/Human/IHumanAccessor.hpp>
#include <pqxx/result.hxx>
#include <string>

namespace GameServer
{
namespace Human
{

/**
 * @brief The PostgreSQL HumanAccessor.
 */
class HumanAccessorPostgresql
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
    virtual void insertRecord(
        Persistence::ITransactionShrPtr         a_transaction,
        Common::IDHolder                const & a_id_holder,
        Configuration::IKey             const & a_key,
        Volume                          const & a_volume
    ) const;

    /**
     * @brief Deletes a human with volume record.
     *
     * @param a_transaction A transaction.
     * @param a_id_holder   An identifier of the holder.
     * @param a_key         A key of the human.
     */
    virtual void deleteRecord(
        Persistence::ITransactionShrPtr         a_transaction,
        Common::IDHolder                const & a_id_holder,
        Configuration::IKey             const & a_key
    ) const;

    /**
     * @brief Gets a human with volume record.
     *
     * @param a_transaction A transaction.
     * @param a_id_holder   An identifier of the holder.
     * @param a_key         A key of the human.
     *
     * @return The human with volume record, null if not found.
     */
    virtual HumanWithVolumeRecordShrPtr getRecord(
        Persistence::ITransactionShrPtr         a_transaction,
        Common::IDHolder                const & a_id_holder,
        Configuration::IKey             const & a_key
    ) const;

    /**
     * @brief Gets human with volume records.
     *
     * @param a_transaction A transaction.
     * @param a_id_holder   An identifier of the holder.
     *
     * @return A map of human with volume records, an empty map if not found.
     */
    virtual HumanWithVolumeRecordMap getRecords(
        Persistence::ITransactionShrPtr         a_transaction,
        Common::IDHolder                const & a_id_holder
    ) const;

    /**
     * @brief Increases the volume of human with volume record.
     *
     * @param a_transaction A transaction.
     * @param a_id_holder   An identifier of the holder.
     * @param a_key         A key of the human.
     * @param a_volume      A volume to be increased.
     */
    virtual void increaseVolume(
        Persistence::ITransactionShrPtr         a_transaction,
        Common::IDHolder                const & a_id_holder,
        Configuration::IKey             const & a_key,
        Volume                          const & a_volume
    ) const;

    /**
     * @brief Decreases the volume of human with volume record.
     *
     * @param a_transaction A transaction.
     * @param a_id_holder   An identifier of the holder.
     * @param a_key         A key of the human.
     * @param a_volume      A volume to be decreased.
     */
    virtual void decreaseVolume(
        Persistence::ITransactionShrPtr         a_transaction,
        Common::IDHolder                const & a_id_holder,
        Configuration::IKey             const & a_key,
        Volume                          const & a_volume
    ) const;

    /**
     * @brief Gets the number of humans of the land.
     *
     * @param a_transaction The transaction.
     * @param a_land_name   The name of the land.
     *
     * @return The number of humans of the land.
     */
    virtual Volume countHumans(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_land_name
    ) const;

private:
    /**
     * @brief Prepares the result for getRecords* methods.
     *
     * @param a_result A result of the query.
     *
     * @return A map of human with volume records.
     */
    HumanWithVolumeRecordMap prepareResultGetRecords(
        pqxx::result     const & a_result,
        Common::IDHolder const & a_id_holder
    ) const;

    /**
     * @brief Gets the table name dependant on identifier of a holder.
     *
     * @param a_id_holder The identifier of a holder.
     *
     * @return The table name.
     */
    std::string getTableName(
        Common::IDHolder const & a_id_holder
    ) const;
};

} // namespace Human
} // namespace GameServer

#endif // GAMESERVER_HUMAN_HUMANACCESSORPOSTGRESQL_HPP

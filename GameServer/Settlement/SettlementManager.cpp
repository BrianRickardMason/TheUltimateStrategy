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

#include "SettlementManager.hpp"

using namespace GameServer::Land;
using namespace GameServer::Persistency;
using namespace boost;
using namespace std;

namespace GameServer
{
namespace Settlement
{

SettlementManager::SettlementManager(
    ISettlementManagerAccessorAutPtr a_accessor
)
    : m_accessor(a_accessor)
{
}

bool SettlementManager::createSettlement(
    ITransactionShrPtr         a_transaction,
    IDLand             const & a_id_land,
    string             const & a_name
) const
{
    try
    {
        // TODO: The interface of "insertRecord" can be simplified.
        IDSettlement id_settlement = m_accessor->insertRecord(a_transaction, a_id_land, a_name);

        return true;
    }
    catch (std::exception const & e)
    {
        return false;
    }
}

bool SettlementManager::deleteSettlement(
    ITransactionShrPtr         a_transaction,
    IDSettlement       const & a_id_settlement
) const
{
    try
    {
        m_accessor->deleteRecord(a_transaction, a_id_settlement);

        return true;
    }
    catch (std::exception const & e)
    {
        return false;
    }
}

SettlementShrPtr SettlementManager::getSettlement(
    ITransactionShrPtr         a_transaction,
    IDSettlement       const & a_id_settlement
) const
{
    return prepareResultGetSettlement(m_accessor->getRecord(a_transaction, a_id_settlement));
}

SettlementShrPtr SettlementManager::getSettlement(
    ITransactionShrPtr         a_transaction,
    string             const & a_name,
    IDLand             const & a_id_land
) const
{
    return prepareResultGetSettlement(m_accessor->getRecord(a_transaction, a_name, a_id_land));
}

SettlementMap SettlementManager::getSettlements(
    ITransactionShrPtr a_transaction
) const
{
    return prepareResultGetSettlements(m_accessor->getRecords(a_transaction));
}

SettlementMap SettlementManager::getSettlements(
    ITransactionShrPtr         a_transaction,
    IDLand             const & a_id_land
) const
{
    return prepareResultGetSettlements(m_accessor->getRecords(a_transaction, a_id_land));
}

SettlementShrPtr SettlementManager::prepareResultGetSettlement(
    SettlementRecordShrPtr a_record
) const
{
    return a_record ? make_shared<Settlement>(*a_record) : SettlementShrPtr();
}

SettlementMap SettlementManager::prepareResultGetSettlements(
    SettlementRecordMap a_records
) const
{
    SettlementMap result;

    for (SettlementRecordMap::iterator it = a_records.begin(); it != a_records.end(); ++it)
    {
        if (it->second)
        {
            SettlementShrPtr settlement = make_shared<Settlement>(*it->second);
            SettlementPair pair(it->second->getIDSettlement(), settlement);
            result.insert(pair);
        }
    }

    return result;
}

} // namespace Settlement
} // namespace GameServer

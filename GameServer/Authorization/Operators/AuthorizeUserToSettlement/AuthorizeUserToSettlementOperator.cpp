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

#include "AuthorizeUserToSettlementOperator.hpp"

using namespace GameServer::Persistency;
using namespace GameServer::Settlement;
using namespace std;

namespace GameServer
{
namespace Authorization
{

AuthorizeUserToSettlementOperator::AuthorizeUserToSettlementOperator(
    IAuthorizationManagerShrPtr a_authorization_manager
)
    : m_authorization_manager(a_authorization_manager)
{
}

AuthorizeUserToSettlementOperatorExitCode AuthorizeUserToSettlementOperator::authorizeUserToSettlement(
    ITransactionShrPtr         a_transaction,
    string             const   a_login,
    IDSettlement       const & a_id_settlement
) const
{
    try
    {
        bool const result = m_authorization_manager->authorizeUserToSettlement(a_transaction, a_login, a_id_settlement);

        return AuthorizeUserToSettlementOperatorExitCode(AUTHORIZE_USER_TO_SETTLEMENT_OPERATOR_EXIT_CODE_AUTHORIZATION_HAS_BEEN_PERFORMED, result);
    }
    catch (...)
    {
        return AuthorizeUserToSettlementOperatorExitCode(AUTHORIZE_USER_TO_SETTLEMENT_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR);
    }
}

} // namespace Authorization
} // namespace GameServer

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

#include <TUSIntegration/IntegrationCommon/Helpers/Commands/Epoch/EpochCommands.hpp>
#include <TUSIntegration/IntegrationCommon/Helpers/RequestCreators.hpp>

using namespace Network::XmlRPCCommon::Reply;
using namespace Network::XmlRPCCommon::Request;
using namespace std;

namespace IntegrationCommon
{
namespace Helpers
{
namespace Commands
{
namespace Epoch
{

ReplyShrPtr CreateEpoch(
    IClientShrPtr       a_client,
    string        const a_login,
    string        const a_password,
    string        const a_world_name,
    string        const a_epoch_name
)
{
    RequestShrPtr request = createRequestCreateEpoch(a_login, a_password, a_world_name, a_epoch_name);

    return a_client->sendRequest(request);
}

ReplyShrPtr DeleteEpoch(
    IClientShrPtr         a_client,
    string        const & a_login,
    string        const & a_password,
    string        const   a_world_name
)
{
    RequestShrPtr request = createRequestDeleteEpoch(a_login, a_password, a_world_name);

    return a_client->sendRequest(request);
}

ReplyShrPtr GetEpoch(
    IClientShrPtr         a_client,
    string        const & a_login,
    string        const & a_password,
    string        const   a_world_name
)
{
    RequestShrPtr request = createRequestGetEpoch(a_login, a_password, a_world_name);

    return a_client->sendRequest(request);
}

ReplyShrPtr ActivateEpoch(
    IClientShrPtr         a_client,
    string        const & a_login,
    string        const & a_password,
    string        const   a_world_name
)
{
    RequestShrPtr request = createRequestActivateEpoch(a_login, a_password, a_world_name);

    return a_client->sendRequest(request);
}

ReplyShrPtr DeactivateEpoch(
    IClientShrPtr         a_client,
    string        const & a_login,
    string        const & a_password,
    string        const   a_world_name
)
{
    RequestShrPtr request = createRequestDeactivateEpoch(a_login, a_password, a_world_name);

    return a_client->sendRequest(request);
}

ReplyShrPtr FinishEpoch(
    IClientShrPtr         a_client,
    string        const & a_login,
    string        const & a_password,
    string        const   a_world_name
)
{
    RequestShrPtr request = createRequestFinishEpoch(a_login, a_password, a_world_name);

    return a_client->sendRequest(request);
}

ReplyShrPtr TickEpoch(
    IClientShrPtr         a_client,
    string        const & a_login,
    string        const & a_password,
    string        const   a_world_name
)
{
    RequestShrPtr request = createRequestTickEpoch(a_login, a_password, a_world_name);

    return a_client->sendRequest(request);
}

} // namespace Epoch
} // namespace Commands
} // namespace Helpers
} // namespace IntegrationCommon

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

#include "LandCommands.hpp"

#include "../../RequestCreators.hpp"

using namespace Network::XmlRPCCommon::Reply;
using namespace Network::XmlRPCCommon::Request;
using namespace std;

namespace IntegrationCommon
{
namespace Helpers
{
namespace Commands
{
namespace Land
{

ReplyShrPtr CreateLand(
    IClientShrPtr        a_client,
    unsigned int const   a_id_user,
    string       const & a_password,
    unsigned int const   a_id_world,
    unsigned int const   a_id_epoch,
    string       const & a_name
)
{
    RequestShrPtr request = createRequestCreateLand(a_id_user, a_password, a_id_world, a_id_epoch, a_name);

    return a_client->sendRequest(request);
}

ReplyShrPtr DeleteLand(
    IClientShrPtr        a_client,
    unsigned int const   a_id_user,
    string       const & a_password,
    unsigned int const   a_id_land
)
{
    RequestShrPtr request = createRequestDeleteLand(a_id_user, a_password, a_id_land);

    return a_client->sendRequest(request);
}

ReplyShrPtr GetLandByIDLand(
    IClientShrPtr        a_client,
    unsigned int const   a_id_user,
    string       const & a_password,
    unsigned int const   a_id_land
)
{
    RequestShrPtr request = createRequestGetLandByIDLand(a_id_user, a_password, a_id_land);

    return a_client->sendRequest(request);
}

ReplyShrPtr GetLandByName(
    IClientShrPtr        a_client,
    unsigned int const   a_id_user,
    string       const & a_password,
    string       const & a_name
)
{
    RequestShrPtr request = createRequestGetLandByName(a_id_user, a_password, a_name);

    return a_client->sendRequest(request);
}

ReplyShrPtr GetLandsByIDWorld(
    IClientShrPtr        a_client,
    unsigned int const   a_id_user,
    string       const & a_password,
    unsigned int const   a_id_world
)
{
    RequestShrPtr request = createRequestGetLandsByIDWorld(a_id_user, a_password, a_id_world);

    return a_client->sendRequest(request);
}

} // namespace Land
} // namespace Commands
} // namespace Helpers
} // namespace IntegrationCommon

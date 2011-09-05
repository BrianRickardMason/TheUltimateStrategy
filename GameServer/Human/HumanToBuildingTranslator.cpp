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

#include "HumanToBuildingTranslator.hpp"
#include <stdexcept>

using namespace GameServer::Building;
using namespace boost;

namespace GameServer
{
namespace Human
{

Building::BuildingShrPtr HumanToBuildingTranslator::getPlaceOfWork(
    Key const & a_key
) const
{
    return doGetPlaceOfWork(a_key.getInternalKey().get<0>());
}

Building::BuildingShrPtr HumanToBuildingTranslator::getPlaceOfWork(
    IDHuman const & a_id_human
) const
{
    return doGetPlaceOfWork(a_id_human);
}

Building::BuildingShrPtr HumanToBuildingTranslator::getPlaceOfWork(
    Common::KeyHash const & a_key_hash
) const
{
    // Create the human key.
    Key key(a_key_hash);

    // Get the place of work.
    return doGetPlaceOfWork(key.getInternalKey().get<0>());
}

Building::BuildingShrPtr HumanToBuildingTranslator::doGetPlaceOfWork(
    IDHuman const & a_id_human
) const
{
    // Get corresponding building.
    std::vector<Building::Key> buildings = PLACES_OF_WORK.at(a_id_human);

    // Check if the human has a place of work.
    if (buildings.size())
    {
        // The human does have the place of work.
        return make_shared<Building::Building>(buildings.front());
    }
    else
    {
        // The human does not have the place of work.
        return BuildingShrPtr();
    }
}

} // namespace Human
} // namespace GameServer

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

#ifndef GAMESERVER_PROPERTY_IDPROPERTY_HPP
#define GAMESERVER_PROPERTY_IDPROPERTY_HPP

#include "../Common/ConstrainedValue.hpp"

namespace GameServer
{
namespace Property
{

/**
 * @brief The fake type class to declare IDProperty.
 */
class TIDProperty
{
};

/**
 * @brief The identifier of a property.
 */
typedef Common::ConstrainedValue<TIDProperty, Common::RangedUnsignedShortIntPolicy<1, 4> > IDProperty;

/**
 * @brief Available identifiers of building properties.
 */
const IDProperty ID_PROPERTY_BUILDING_CAPACITY(1);

/**
 * @brief Available identifiers of human properties.
 */
const IDProperty ID_PROPERTY_HUMAN_DISMISSABLE(2);
const IDProperty ID_PROPERTY_HUMAN_ENGAGEABLE (3);
const IDProperty ID_PROPERTY_HUMAN_PRODUCTION (4);

} // namespace Property
} // namespace GameServer

#endif // GAMESERVER_PROPERTY_IDPROPERTY_HPP

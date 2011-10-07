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

#ifndef GAMESERVER_EPOCH_EPOCHRECORD_HPP
#define GAMESERVER_EPOCH_EPOCHRECORD_HPP

#include "IDEpoch.hpp"
#include <boost/shared_ptr.hpp>
#include <string>

namespace GameServer
{
namespace Epoch
{

/**
 * @brief The record of the epoch.
 */
class EpochRecord
{
public:
    /**
     * @brief Constructs the epoch record.
     *
     * @param a_id_epoch   The identifier of the epoch.
     * @param a_world_name The name of the world.
     * @param a_active     Indicates whether the epoch is active.
     * @param a_finished   Indicates whether the epoch has been finished.
     * @param a_ticks      The number of ticks of the epoch.
     */
    EpochRecord(
        IDEpoch        const & a_id_epoch,
        std::string    const   a_world_name,
        bool           const   a_active,
        bool           const   a_finished,
        unsigned int   const   a_ticks
    );

    /**
     * @brief Gets the identifier of the epoch.
     *
     * @return The identifier of the epoch.
     */
    IDEpoch const & getIDEpoch() const;

    /**
     * @brief Gets the name of the world.
     *
     * @return The name of the world.
     */
    std::string getWorldName() const;

    /**
     * @brief Gets the "active" status of the epoch.
     *
     * @return True if the epoch is active, false otherwise.
     */
    bool getActive() const;

    /**
     * @brief Gets the "finished" status of the epoch.
     *
     * @return True if the epoch has been finished, false otherwise.
     */
    bool getFinished() const;

    /**
     * @brief Gets the number of ticks of the epoch.
     *
     * @return The number of the ticks of the epoch.
     */
    unsigned int getTicks() const;

private:
    /**
     * @brief The identifier of the epoch.
     */
    IDEpoch const m_id_epoch;

    /**
     * @brief The name of the world.
     */
    std::string const m_world_name;

    /**
     * @brief The "active" status of the epoch.
     */
    bool const m_active;

    /**
     * @brief The "finished" status of the epoch.
     */
    bool const m_finished;

    /**
     * @brief The number of the ticks of the epoch.
     */
    unsigned int const m_ticks;
};

/**
 * @brief The shared pointer of the record of the epoch.
 */
typedef boost::shared_ptr<EpochRecord> EpochRecordShrPtr;

} // namespace Epoch
} // namespace GameServer

#endif // GAMESERVER_EPOCH_EPOCHRECORD_HPP

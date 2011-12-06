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

#include "Constants.hpp"
#include <boost/assign.hpp>

H::KeyVec HUMAN_IS_NOT_ENGAGEABLE = boost::assign::list_of
    (H::KEY_WORKER_BLACKSMITH_ADVANCED  )
    (H::KEY_WORKER_BREEDER_ADVANCED     )
    (H::KEY_WORKER_DRUID_ADVANCED       )
    (H::KEY_WORKER_FARMER_ADVANCED      )
    (H::KEY_WORKER_FISHERMAN_ADVANCED   )
    (H::KEY_WORKER_JOBLESS_NOVICE       )
    (H::KEY_WORKER_JOBLESS_ADVANCED     )
    (H::KEY_WORKER_LUMBERJACK_ADVANCED  )
    (H::KEY_WORKER_MERCHANT_ADVANCED    )
    (H::KEY_WORKER_MINER_ADVANCED       )
    (H::KEY_WORKER_OFFICIAL_ADVANCED    )
    (H::KEY_WORKER_PRIEST_ADVANCED      )
    (H::KEY_WORKER_STEELWORKER_ADVANCED )
    (H::KEY_WORKER_STONE_MASON_ADVANCED )
    (H::KEY_WORKER_TEACHER_ADVANCED     );

H::KeyVec HUMAN_IS_NOT_DISMISSABLE = boost::assign::list_of
    (H::KEY_WORKER_JOBLESS_NOVICE  )
    (H::KEY_WORKER_JOBLESS_ADVANCED);

H::KeyVec HUMAN_DOES_NOT_PRODUCE = boost::assign::list_of
    (H::KEY_WORKER_BLACKSMITH_NOVICE    )
    (H::KEY_WORKER_BLACKSMITH_ADVANCED  )
    (H::KEY_WORKER_JOBLESS_NOVICE       )
    (H::KEY_WORKER_JOBLESS_ADVANCED     )
    (H::KEY_WORKER_OFFICIAL_NOVICE      )
    (H::KEY_WORKER_OFFICIAL_ADVANCED    )
    (H::KEY_WORKER_PRIEST_NOVICE        )
    (H::KEY_WORKER_PRIEST_ADVANCED      )
    (H::KEY_WORKER_TEACHER_NOVICE       )
    (H::KEY_WORKER_TEACHER_ADVANCED     );

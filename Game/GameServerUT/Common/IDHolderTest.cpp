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

#include <Game/GameServer/Common/IDHolder.hpp>
#include <gmock/gmock.h>

using namespace GameServer::Common;

TEST(IDHolderTest, IDHolder_Parameterless)
{
    ASSERT_NO_THROW(IDHolder id_holder);

    IDHolder id_holder;

    ASSERT_EQ(ID_HOLDER_CLASS_SETTLEMENT, id_holder.getValue1());
    ASSERT_STREQ("", id_holder.getValue2().c_str());
}

TEST(IDHolderTest, IDHolder_ValueType)
{
    ASSERT_NO_THROW(IDHolder id_holder(ID_HOLDER_CLASS_SETTLEMENT, "Settlement"));
    ASSERT_NO_THROW(IDHolder id_holder(ID_HOLDER_CLASS_SETTLER,    "Settler"));
    ASSERT_NO_THROW(IDHolder id_holder(ID_HOLDER_CLASS_TRANSPORT,  "Transport"));
    ASSERT_NO_THROW(IDHolder id_holder(ID_HOLDER_CLASS_TROOP,      "Troop"));

    ASSERT_THROW(IDHolder id_holder(0, "Settlement"), std::range_error);
    ASSERT_THROW(IDHolder id_holder(5, "Settlement"), std::range_error);

    IDHolder id_holder(ID_HOLDER_CLASS_SETTLEMENT, "Settlement");
    ASSERT_EQ(ID_HOLDER_CLASS_SETTLEMENT, id_holder.getValue1());
    ASSERT_STREQ("Settlement", id_holder.getValue2().c_str());
}

TEST(IDHolderTest, IDHolder_Copy)
{
    IDHolder id_holder_1(ID_HOLDER_CLASS_SETTLEMENT, "Settlement");

    ASSERT_NO_THROW(IDHolder id_holder(id_holder_1));

    IDHolder id_holder = id_holder_1;
    ASSERT_EQ(ID_HOLDER_CLASS_SETTLEMENT, id_holder.getValue1());
    ASSERT_STREQ("Settlement", id_holder.getValue2().c_str());
}

TEST(IDHolderTest, Assignment)
{
    ASSERT_NO_THROW(IDHolder id_holder; id_holder.assign(ID_HOLDER_CLASS_SETTLEMENT, "Settlement"));
    ASSERT_NO_THROW(IDHolder id_holder; id_holder.assign(ID_HOLDER_CLASS_SETTLER,    "Settler"));
    ASSERT_NO_THROW(IDHolder id_holder; id_holder.assign(ID_HOLDER_CLASS_TRANSPORT,  "Transport"));
    ASSERT_NO_THROW(IDHolder id_holder; id_holder.assign(ID_HOLDER_CLASS_TROOP,      "Troop"));

    ASSERT_THROW(IDHolder id_holder; id_holder.assign(0, "Settlement"), std::range_error);
    ASSERT_THROW(IDHolder id_holder; id_holder.assign(5, "Settlement"), std::range_error);

    IDHolder id_holder; id_holder.assign(ID_HOLDER_CLASS_SETTLEMENT, "Settlement");
    ASSERT_EQ(ID_HOLDER_CLASS_SETTLEMENT, id_holder.getValue1());
    ASSERT_STREQ("Settlement", id_holder.getValue2().c_str());
}

TEST(IDHolderTest, GetValue1)
{
    IDHolder id_holder(ID_HOLDER_CLASS_SETTLEMENT, "Settlement");

    ASSERT_EQ(ID_HOLDER_CLASS_SETTLEMENT, id_holder.getValue1());
}

TEST(IDHolderTest, GetValue2)
{
    IDHolder id_holder(ID_HOLDER_CLASS_SETTLEMENT, "Settlement");

    ASSERT_STREQ("Settlement", id_holder.getValue2().c_str());
}

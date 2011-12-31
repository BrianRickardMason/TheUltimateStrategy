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

#ifndef GAMESERVER_COMMON_CONSTRAINEDPAIR_HPP
#define GAMESERVER_COMMON_CONSTRAINEDPAIR_HPP

#include <stdexcept>

namespace GameServer
{
namespace Common
{

/**
 * @brief A constrained pair base class.
 *
 * The class holds the pair with policy specific constraints.
 * The operators to manipulate the pair are reduced to the very minimum.
 *
 * TODO: boost::operators.
 */
template<
    typename Policy
>
class ConstrainedPair
{
    /**
     * @brief Useful typedefs.
     */
    typedef typename Policy::value1_type value1_type;
    typedef typename Policy::value2_type value2_type;
    typedef ConstrainedPair self;

public:
    /**
     * @brief Constructs a constrained pair.
     */
    ConstrainedPair()
        : m_value1(Policy::default_value1),
          m_value2()
    {
    }

    /**
     * @brief Constructs a constrained pair.
     *
     * @param a_value1 The value1 to be assigned.
     * @param a_value2 The value2 to be assigned.
     *
     * @throws std::range_error If rhs is out of valid range.
     */
    ConstrainedPair(
        value1_type const & a_value1,
        value2_type const & a_value2
    )
    {
        Policy::assign(m_value1, a_value1, m_value2, a_value2);
    }

    /**
     * @brief Constructs a constrained value.
     *
     * @param a_other The other constrained pair.
     */
    ConstrainedPair(
        self const & a_other
    )
        : m_value1(a_other.m_value1),
          m_value2(a_other.m_value2)
    {
    }

    /**
     * @brief Relational operators.
     */
    friend bool operator==(self const & a_lhs, self const & a_rhs) { return a_lhs.m_value1 == a_rhs.m_value1 and a_lhs.m_value2 == a_rhs.m_value2; }
    friend bool operator!=(self const & a_lhs, self const & a_rhs) { return a_lhs.m_value1 != a_rhs.m_value1 or  a_lhs.m_value2 != a_rhs.m_value2; }
    friend bool operator< (self const & a_lhs, self const & a_rhs)
    {
        if (a_lhs.m_value1 != a_rhs.m_value1)
        {
            return a_lhs.m_value1 < a_rhs.m_value1;
        }
        else
        {
            return a_lhs.m_value2 < a_rhs.m_value2;
        }
    }

    /**
     * @brief Uses the policy defined assing function.
     *
     * @param a_value1 The value1 to be assigned.
     * @param a_value2 The value2 to be assigned.
     *
     * @throws std::range_error If rhs is out of valid range.
     */
    void assign(
        value1_type const & a_value1,
        value2_type const & a_value2
    )
    {
        Policy::assign(m_value1, a_value1, m_value2, a_value2);
    }

    /**
     * @brief Gets the value1.
     *
     * @return The value1.
     */
    value1_type getValue1() const
    {
        return m_value1;
    }

    /**
     * @brief Gets the value2.
     *
     * @return The value2.
     */
    value2_type getValue2() const
    {
        return m_value2;
    }

private:
    /**
     * @brief The value1.
     */
    value1_type m_value1;

    /**
     * @brief The value2.
     */
    value2_type m_value2;
};

/**
 * @brief A "ranged pair unsigned short int" policy.
 */
template<
    unsigned short int Val2Min1,
    unsigned short int Val2Max1,
    unsigned short int Val2Min2,
    unsigned short int Val2Max2,
    unsigned short int Val2Min3,
    unsigned short int Val2Max3,
    unsigned short int Val2Min4,
    unsigned short int Val2Max4
>
class RangedPairUnsignedShortIntPolicy
{
public:
    /**
     * @brief Public typedefs.
     */
    typedef unsigned short int value1_type;
    typedef unsigned short int value2_type;

    /**
     * @brief Default value.
     */
    static const value1_type default_value1 = 1;
    static const value2_type default_value2 = Val2Min1;

    /**
     * @brief Assigns the value.
     *
     * @param a_lhs1 Left hand side 1.
     * @param a_rhs1 Right hand side 1.
     * @param a_lhs2 Left hand side 2.
     * @param a_rhs2 Right hand side 2.
     *
     * @throws std::range_error If rhs is out of valid range.
     */
    static void assign(
        value1_type       & a_lhs1,
        value1_type const & a_rhs1,
        value2_type       & a_lhs2,
        value2_type const & a_rhs2
    )
    {
        if (a_rhs1 < 1 or a_rhs1 > 4)
        {
            throw std::range_error("Out of a valid range.");
        }

        a_lhs1 = a_rhs1;

        switch (a_lhs1)
        {
            case 1:
                if (a_rhs2 < Val2Min1 or a_rhs2 > Val2Max1)
                    throw std::range_error("Out of a valid range.");
                break;
            case 2:
                if (a_rhs2 < Val2Min2 or a_rhs2 > Val2Max2)
                    throw std::range_error("Out of a valid range.");
                break;
            case 3:
                if (a_rhs2 < Val2Min3 or a_rhs2 > Val2Max3)
                    throw std::range_error("Out of a valid range.");
                break;
            case 4:
                if (a_rhs2 < Val2Min4 or a_rhs2 > Val2Max4)
                    throw std::range_error("Out of a valid range.");
                break;
        }

        a_lhs2 = a_rhs2;
    }
};

/**
 * @brief A "ranged unsigned short int + unsigned int" policy.
 */
template<
    unsigned short int Min,
    unsigned short int Max
>
class RangedUnsignedShortIntPlusStringPolicy
{
public:
    /**
     * @brief Public typedefs.
     */
    typedef unsigned short int value1_type;
    typedef std::string        value2_type;

    /**
     * @brief Default value.
     */
    static const value1_type default_value1 = Min;

    /**
     * @brief Assigns the value.
     *
     * @param a_lhs1 Left hand side 1.
     * @param a_rhs1 Right hand side 1.
     * @param a_lhs2 Left hand side 2.
     * @param a_rhs2 Right hand side 2.
     *
     * @throws std::range_error If rhs is out of valid range.
     */
    static void assign(
        value1_type       & a_lhs1,
        value1_type const & a_rhs1,
        value2_type       & a_lhs2,
        value2_type const & a_rhs2
    )
    {
        if (a_rhs1 < Min or a_rhs1 > Max)
        {
            throw std::range_error("Out of a valid range.");
        }

        a_lhs1 = a_rhs1;
        a_lhs2 = a_rhs2;
    }
};

} // namespace Common
} // namespace GameServer

#endif // GAMESERVER_COMMON_CONSTRAINEDVALUE_HPP

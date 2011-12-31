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

#ifndef GAMESERVER_COMMON_CONSTRAINEDVALUE_HPP
#define GAMESERVER_COMMON_CONSTRAINEDVALUE_HPP

#include <stdexcept>

namespace GameServer
{
namespace Common
{

/**
 * @brief A constrained value base class.
 *
 * The class holds the value with policy specific constraints.
 * The operators to manipulate the value are reduced to the very minimum.
 * If the value should be used in any arithmetic expressions, internal value shall be got by getValue() method.
 *
 * CRTP was considered to be used here. However, it is much easier to declare a strict type with typedef than
 * with CRTP. If you can handle it in a more elegant way, do not hesitate to contact me.
 *
 * TObject is just a fake class that is used to create a strict type.
 *
 * TODO: boost::operators.
 */
template<
    typename TObject,
    typename TPolicy
>
class ConstrainedValue
{
    /**
     * @brief Useful typedefs.
     */
    typedef typename TPolicy::value_type value_type;
    typedef ConstrainedValue self;

public:
    /**
     * @brief Constructs a constrained value.
     */
    ConstrainedValue()
        : m_value(TPolicy::default_value)
    {
    }

    /**
     * @brief Constructs a constrained value.
     *
     * @param a_value The value to be assigned.
     *
     * @throws std::range_error If rhs is out of valid range.
     */
    explicit ConstrainedValue(
        value_type const & a_value
    )
    {
        TPolicy::assign(m_value, a_value);
    }

    /**
     * @brief Constructs a constrained value.
     *
     * @param a_other The other constrained value.
     */
    ConstrainedValue(
        self const & a_other
    )
        : m_value(a_other.m_value)
    {
    }

    /**
     * @brief Assignement operators.
     *
     * @throws std::range_error If rhs is out of valid range.
     */
    self & operator=(value_type const & a_value) { assign(a_value); return *this; }

    /**
     * @brief Relational operators.
     */
    friend bool operator< (self const & a_lhs, self const & a_rhs) { return a_lhs.m_value <  a_rhs.m_value; }
    friend bool operator> (self const & a_lhs, self const & a_rhs) { return a_lhs.m_value >  a_rhs.m_value; }
    friend bool operator<=(self const & a_lhs, self const & a_rhs) { return a_lhs.m_value <= a_rhs.m_value; }
    friend bool operator>=(self const & a_lhs, self const & a_rhs) { return a_lhs.m_value >= a_rhs.m_value; }
    friend bool operator==(self const & a_lhs, self const & a_rhs) { return a_lhs.m_value == a_rhs.m_value; }
    friend bool operator!=(self const & a_lhs, self const & a_rhs) { return a_lhs.m_value != a_rhs.m_value; }

    /**
     * @brief Gets the value.
     *
     * @return The value.
     */
    value_type getValue() const
    {
        return m_value;
    }

private:
    /**
     * @brief Uses the policy defined assign function.
     *
     * @param a_value The value to be assigned.
     *
     * @throws std::range_error If rhs is out of valid range.
     */
    void assign(
        value_type const & a_value
    )
    {
        TPolicy::assign(m_value, a_value);
    }

    /**
     * @brief The value.
     */
    value_type m_value;
};

/**
 * @brief A "ranged unsigned short int" policy.
 */
template<
    unsigned short int TMin,
    unsigned short int TMax
>
class RangedUnsignedShortIntPolicy
{
public:
    /**
     * @brief Public typedefs.
     */
    typedef unsigned short int value_type;

    /**
     * @brief Default value.
     */
    static const value_type default_value = TMin;

    /**
     * @brief Assigns the value.
     *
     * @param a_lhs Left hand side.
     * @param a_rhs Right hand side.
     *
     * @throws std::range_error If rhs is out of valid range.
     */
    static void assign(
        value_type       & a_lhs,
        value_type const & a_rhs
    )
    {
        if (a_rhs < TMin or a_rhs > TMax)
        {
            throw std::range_error("Out of a valid range.");
        }

        a_lhs = a_rhs;
    }
};

/**
 * @brief A "unsigned int" policy.
 */
class UnsignedIntPolicy
{
public:
    /**
     * @brief Public typedefs.
     */
    typedef unsigned int value_type;

    /**
     * @brief Default value.
     */
    static const value_type default_value = 0;

    /**
     * @brief Assigns the value.
     *
     * @param a_lhs Left hand side.
     * @param a_rhs Right hand side.
     */
    static void assign(
        value_type       & a_lhs,
        value_type const & a_rhs
    )
    {
        a_lhs = a_rhs;
    }
};

} // namespace Common
} // namespace GameServer

#endif // GAMESERVER_COMMON_CONSTRAINEDVALUE_HPP

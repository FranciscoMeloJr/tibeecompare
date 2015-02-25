/* Copyright (c) 2015 Francois Doray <francois.pierre-doray@polymtl.ca>
 *
 * This file is part of tibeecompare.
 *
 * tibeecompare is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * tibeecompare is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with tibeecompare.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "gtest/gtest.h"

#include <vector>

#include "state/StateHistory.hpp"

namespace tibee
{
namespace state
{

namespace
{

struct V {
    V() : value(0), start(0), end(0) {}
    V(uint32_t value, timestamp_t start, timestamp_t end)
        : value(value), start(start), end(end) {}

    uint32_t value;
    timestamp_t start;
    timestamp_t end;

    bool operator==(const V& other) const {
        return value == other.value &&
               start == other.start &&
               end == other.end;
    }
};

void Callback(uint32_t value, timestamp_t start, timestamp_t end, std::vector<V>* vec)
{
    vec->push_back(V(value, start, end));
}

}  // namespace

TEST(StateHistory, StateHistory)
{
    namespace pl = std::placeholders;

    StateHistory history;

    history.SetTimestamp(10);
    history.SetUIntegerValue(AttributeKey(1), 5);
    history.SetUIntegerValue(AttributeKey(2), 15);

    history.SetTimestamp(20);
    history.SetUIntegerValue(AttributeKey(1), 7);

    history.SetTimestamp(30);
    history.SetUIntegerValue(AttributeKey(1), 7);

    history.SetTimestamp(40);
    history.SetUIntegerValue(AttributeKey(1), 101);
    history.SetUIntegerValue(AttributeKey(2), 102);

    history.SetTimestamp(50);
    history.SetUIntegerValue(AttributeKey(1), 102);
    history.SetUIntegerValue(AttributeKey(2), 103);

    uint32_t val = 0;

    EXPECT_FALSE(history.GetUIntegerValue(1, 5, &val));
    EXPECT_EQ(0u, val);
    EXPECT_TRUE(history.GetUIntegerValue(1, 10, &val));
    EXPECT_EQ(5u, val);
    EXPECT_TRUE(history.GetUIntegerValue(1, 15, &val));
    EXPECT_EQ(5u, val);
    EXPECT_TRUE(history.GetUIntegerValue(1, 20, &val));
    EXPECT_EQ(7u, val);
    EXPECT_TRUE(history.GetUIntegerValue(1, 25, &val));
    EXPECT_EQ(7u, val);
    EXPECT_TRUE(history.GetUIntegerValue(1, 30, &val));
    EXPECT_EQ(7u, val);
    EXPECT_TRUE(history.GetUIntegerValue(1, 35, &val));
    EXPECT_EQ(7u, val);
    EXPECT_TRUE(history.GetUIntegerValue(1, 40, &val));
    EXPECT_EQ(101u, val);
    EXPECT_TRUE(history.GetUIntegerValue(1, 45, &val));
    EXPECT_EQ(101u, val);
    EXPECT_TRUE(history.GetUIntegerValue(1, 50, &val));
    EXPECT_EQ(102u, val);
    EXPECT_TRUE(history.GetUIntegerValue(1, 55, &val));
    EXPECT_EQ(102u, val);

    val = 0;

    EXPECT_FALSE(history.GetUIntegerValue(2, 5, &val));
    EXPECT_EQ(0u, val);
    EXPECT_TRUE(history.GetUIntegerValue(2, 10, &val));
    EXPECT_EQ(15u, val);
    EXPECT_TRUE(history.GetUIntegerValue(2, 15, &val));
    EXPECT_EQ(15u, val);
    EXPECT_TRUE(history.GetUIntegerValue(2, 20, &val));
    EXPECT_EQ(15u, val);
    EXPECT_TRUE(history.GetUIntegerValue(2, 25, &val));
    EXPECT_EQ(15u, val);
    EXPECT_TRUE(history.GetUIntegerValue(2, 30, &val));
    EXPECT_EQ(15u, val);
    EXPECT_TRUE(history.GetUIntegerValue(2, 35, &val));
    EXPECT_EQ(15u, val);
    EXPECT_TRUE(history.GetUIntegerValue(2, 40, &val));
    EXPECT_EQ(102u, val);
    EXPECT_TRUE(history.GetUIntegerValue(2, 45, &val));
    EXPECT_EQ(102u, val);
    EXPECT_TRUE(history.GetUIntegerValue(2, 50, &val));
    EXPECT_EQ(103u, val);
    EXPECT_TRUE(history.GetUIntegerValue(2, 55, &val));
    EXPECT_EQ(103u, val);

    std::vector<V> vec;
    history.EnumerateUIntegerValues(1, 0, 60, std::bind(&Callback, pl::_1, pl::_2, pl::_3, &vec));
    std::vector<V> expectedVec({{5, 10, 20}, {7, 20, 40}, {101, 40, 50}, {102, 50, 60}});
    EXPECT_EQ(expectedVec, vec);

    vec.clear();
    history.EnumerateUIntegerValues(1, 25, 50, std::bind(&Callback, pl::_1, pl::_2, pl::_3, &vec));
    expectedVec = {{7, 25, 40}, {101, 40, 50}};
    EXPECT_EQ(expectedVec, vec);
}

}  // namespace stacks
}  // namespace tibee

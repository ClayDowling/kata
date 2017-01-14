//
// Created by clay on 1/14/17.
//

#include "../RomanNumeral.h"

#include <vector>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;
using namespace ::testing;

class RomanNumeralOutOfRangeTest : public Test
{
public:
    RomanNumeral roman;
};

TEST_F(RomanNumeralOutOfRangeTest, ZeroThrowsOutOfRange)
{
    ASSERT_THROW(roman.toRoman(0), out_of_range);
}
TEST_F(RomanNumeralOutOfRangeTest, NegativeOneThrowsOutOfRange)
{
    ASSERT_THROW(roman.toRoman(-1), out_of_range);
}
TEST_F(RomanNumeralOutOfRangeTest, FourThousandThrowsOutOfRange)
{
    ASSERT_THROW(roman.toRoman(4000), out_of_range);
}
TEST_F(RomanNumeralOutOfRangeTest, BigNumThrowsOutOfRange)
{
    ASSERT_THROW(roman.toRoman(100000000), out_of_range);
}